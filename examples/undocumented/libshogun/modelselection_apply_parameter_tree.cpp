/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Heiko Strathmann
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */

#include <shogun/base/init.h>
#include <shogun/modelselection/ModelSelectionParameters.h>
#include <shogun/kernel/GaussianKernel.h>
#include <shogun/features/Labels.h>
#include <shogun/features/SimpleFeatures.h>
#include <shogun/classifier/svm/LibSVM.h>

using namespace shogun;

void print_message(FILE* target, const char* str)
{
	fprintf(target, "%s", str);
}

CModelSelectionParameters* create_param_tree()
{
	CModelSelectionParameters* root=new CModelSelectionParameters();

	CModelSelectionParameters* kernel=new CModelSelectionParameters("kernel");
	root->append_child(kernel);

	CModelSelectionParameters* c=new CModelSelectionParameters("C1");
	root->append_child(c);
	c->set_range(1, 2, R_EXP);

	CGaussianKernel* gaussian_kernel=new CGaussianKernel();
	CModelSelectionParameters* param_gaussian_kernel=
			new CModelSelectionParameters("kernel", gaussian_kernel);

	kernel->append_child(param_gaussian_kernel);

	CModelSelectionParameters* param_gaussian_kernel_width=
			new CModelSelectionParameters("width");
	param_gaussian_kernel_width->set_range(1, 2, R_EXP);
	param_gaussian_kernel->append_child(param_gaussian_kernel_width);

	return root;
}

void apply_parameter_tree(DynArray<CParameterCombination*>& combinations)
{
	/* create some data */
	float64_t* matrix=new float64_t[6];
	for (index_t i=0; i<6; i++)
		matrix[i]=i;

	/* create three 2-dimensional vectors
	 * to avoid deleting these, REF now and UNREF when finished */
	CSimpleFeatures<float64_t>* features=new CSimpleFeatures<float64_t> ();
	features->set_feature_matrix(matrix, 2, 3);
	SG_REF(features);

	/* create three labels, will be handed to svm and automaticall deleted */
	CLabels* labels=new CLabels(3);
	labels->set_label(0, -1);
	labels->set_label(1, +1);
	labels->set_label(2, -1);

	/* create libsvm with C=10 and train */
	CLibSVM* svm=new CLibSVM();
	svm->set_labels(labels);

	for (index_t i=0; i<combinations.get_num_elements(); ++i)
	{
		SG_SPRINT("applying:\n");
		combinations[i]->print();
		CParameterCombination* current_combination=combinations[i];
		Parameter* current_parameters=svm->m_parameters;
		current_combination->apply_to_parameter(current_parameters);

		/* get kernel to set features, get_kernel SG_REF's the kernel */
		CKernel* kernel=svm->get_kernel();
		kernel->init(features, features);

		svm->train();

		/* classify on training examples */
		for (index_t i=0; i<3; i++)
			SG_SPRINT("output[%d]=%f\n", i, svm->apply(i));

		/* unset features and SG_UNREF kernel */
		kernel->cleanup();
		SG_UNREF(kernel);

		SG_SPRINT("----------------\n\n");
	}

	/* free up memory */
	SG_UNREF(features);
	SG_UNREF(svm);
}

int main(int argc, char **argv)
{
	init_shogun(&print_message, &print_message, &print_message);

	/* create example tree */
	CModelSelectionParameters* tree=create_param_tree();
	tree->print();
	SG_SPRINT("----------------------------------\n");

	/* build combinations of parameter trees */
	DynArray<CParameterCombination*> combinations;
	tree->get_combinations(combinations);

	apply_parameter_tree(combinations);

	/* print and directly delete them all */
	for (index_t i=0; i<combinations.get_num_elements(); ++i)
		combinations[i]->destroy(true, true);

	/* delete example tree (after processing of combinations because CSGObject
	 * (namely the kernel) of the tree is SG_UNREF'ed (and not REF'ed anywhere
	 * else) */
	tree->destroy();

	exit_shogun();

	return 0;
}


