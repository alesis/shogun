#include <shogun/features/Labels.h>
#include <shogun/features/SimpleFeatures.h>
#include <shogun/kernel/GaussianKernel.h>
#include <shogun/classifier/svm/LibSVM.h>
#include <shogun/base/init.h>
#include <shogun/lib/common.h>
#include <shogun/lib/io.h>

using namespace shogun;

void print_message(FILE* target, const char* str)
{
	fprintf(target, "%s", str);
}

int main(int argc, char** argv)
{
	init_shogun(&print_message);

	// create some data
	float64_t* matrix = new float64_t[6];
	for (int32_t i=0; i<6; i++)
		matrix[i]=i;

	// create three 2-dimensional vectors 
	// shogun will now own the matrix created
	CSimpleFeatures<float64_t>* features= new CSimpleFeatures<float64_t>();
	features->set_feature_matrix(matrix, 2, 3);

	// create three labels
	CLabels* labels=new CLabels(3);
	labels->set_label(0, -1);
	labels->set_label(1, +1);
	labels->set_label(2, -1);

	// create gaussian kernel with cache 10MB, width 0.5
	CGaussianKernel* kernel = new CGaussianKernel(10, 0.5);
	kernel->init(features, features);

	// create libsvm with C=10 and train
	CLibSVM* svm = new CLibSVM(10, kernel, labels);
	svm->train();

	// classify on training examples
	for (int32_t i=0; i<3; i++)
		SG_SPRINT("output[%d]=%f\n", i, svm->apply(i));

	// free up memory
	SG_UNREF(svm);

	exit_shogun();
	return 0;
}
