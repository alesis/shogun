/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2010 Soeren Sonnenburg
 * Written (W) 1999-2008 Gunnar Raetsch
 * Copyright (C) 1999-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 * Copyright (C) 2010 Berlin Institute of Technology
 */

#ifndef _SIMPLEFEATURES__H__
#define _SIMPLEFEATURES__H__

#include "lib/common.h"
#include "lib/Mathematics.h"
#include "lib/io.h"
#include "lib/Cache.h"
#include "lib/File.h"
#include "preprocessor/SimplePreprocessor.h"
#include "features/DotFeatures.h"
#include "features/StringFeatures.h"
#include "base/Parameter.h"
#include "lib/DataType.h"

#include <string.h>

namespace shogun
{
template <class ST> class CStringFeatures;
template <class ST> class CSimpleFeatures;
template <class ST> class CSimplePreprocessor;
template <class ST> struct SGMatrix;
class CDotFeatures;

/** @brief The class SimpleFeatures implements dense feature matrices.
 *
 * The feature matrices are stored en-block in memory in fortran order, i.e.
 * column-by-column, where a column denotes a feature vector.
 *
 * There are get_num_vectors() many feature vectors, of dimension
 * get_num_features(). To access a feature vector call
 * get_feature_vector() and when you are done treating it call
 * free_feature_vector(). While free_feature_vector() is a NOP in most cases
 * feature vectors might have been generated on the fly (due to a number
 * preprocessors being attached to them).
 *
 * From this template class a number the following dense feature matrix types
 * are used and supported:
 *
 * \li bool matrix - CSimpleFeatures<bool>
 * \li 8bit char matrix - CSimpleFeatures<char>
 * \li 8bit Byte matrix - CSimpleFeatures<uint8_t>
 * \li 16bit Integer matrix - CSimpleFeatures<int16_t>
 * \li 16bit Word matrix - CSimpleFeatures<uint16_t>
 * \li 32bit Integer matrix - CSimpleFeatures<int32_t>
 * \li 32bit Unsigned Integer matrix - CSimpleFeatures<uint32_t>
 * \li 32bit Float matrix - CSimpleFeatures<float32_t>
 * \li 64bit Float matrix - CSimpleFeatures<float64_t>
 * \li 64bit Float matrix <b>in a file</b> - CRealFileFeatures
 * \li 64bit Tangent of posterior log-odds (TOP) features from HMM - CTOPFeatures
 * \li 64bit Fisher Kernel (FK) features from HMM - CTOPFeatures
 * \li 96bit Float matrix - CSimpleFeatures<floatmax_t>
 */
template <class ST> class CSimpleFeatures: public CDotFeatures
{
	public:
		/** constructor
		 *
		 * @param size cache size
		 */
		CSimpleFeatures(int32_t size=0)
			: CDotFeatures(size)
		{
			init();
		}

		/** copy constructor */
		CSimpleFeatures(const CSimpleFeatures & orig)
		: CDotFeatures(orig)
		{
			copy_feature_matrix(orig.feature_matrix,
					orig.num_features, orig.num_vectors);
			initialize_cache();
		}

		/** constructor
		 *
		 * @param src feature matrix
		 * @param num_feat number of features in matrix
		 * @param num_vec number of vectors in matrix
		 */
		CSimpleFeatures(ST* src, int32_t num_feat, int32_t num_vec)
		: CDotFeatures()
		{
			init();
			copy_feature_matrix(src, num_feat, num_vec);
		}

		/** constructor loading features from file
		 *
		 * @param loader File object via which to load data
		 */
		CSimpleFeatures(CFile* loader)
		: CDotFeatures(loader)
		{
			init();
			load(loader);
		}

		/** duplicate feature object
		 *
		 * @return feature object
		 */
		virtual CFeatures* duplicate() const
		{
			return new CSimpleFeatures<ST>(*this);
		}

		virtual ~CSimpleFeatures()
		{
			free_features();
		}

		/** free feature matrix
		 *
		 */
		void free_feature_matrix()
		{
            delete[] feature_matrix;
            feature_matrix = NULL;
			feature_matrix_num_features=num_features;
			feature_matrix_num_vectors=num_vectors;
            num_vectors=0;
            num_features=0;
		}

		/** free feature matrix and cache
		 *
		 */
		void free_features()
		{
			free_feature_matrix();
			SG_UNREF(feature_cache);
		}

		/** get feature vector
		 * for sample num from the matrix as it is if matrix is
		 * initialized, else return preprocessed compute_feature_vector
		 *
		 * @param num index of feature vector
		 * @param len length is returned by reference
		 * @param dofree whether returned vector must be freed by
		 * caller via free_feature_vector
		 * @return feature vector
		 */
		ST* get_feature_vector(int32_t num, int32_t& len, bool& dofree)
		{
			len=num_features;

			if (feature_matrix)
			{
				dofree=false;
				return &feature_matrix[num*int64_t(num_features)];
			} 
			else
			{
				ST* feat=NULL;
				dofree=false;

				if (feature_cache)
				{
					feat=feature_cache->lock_entry(num);

					if (feat)
						return feat;
					else
					{
						feat=feature_cache->set_entry(num);
					}
				}

				if (!feat)
					dofree=true;
				feat=compute_feature_vector(num, len, feat);


				if (get_num_preproc())
				{
					int32_t tmp_len=len;
					ST* tmp_feat_before = feat;
					ST* tmp_feat_after = NULL;

					for (int32_t i=0; i<get_num_preproc(); i++)
					{
						CSimplePreprocessor<ST>* p = (CSimplePreprocessor<ST>*) get_preproc(i);
						tmp_feat_after=p->apply_to_feature_vector(tmp_feat_before, tmp_len);
						SG_UNREF(p);

						if (i!=0)	// delete feature vector, except for the the first one, i.e., feat
							delete[] tmp_feat_before;
						tmp_feat_before=tmp_feat_after;
					}

					memcpy(feat, tmp_feat_after, sizeof(ST)*tmp_len);
					delete[] tmp_feat_after;

					len=tmp_len ;
				}
				return feat ;
			}
		}

		/** set feature vector num
		 *
		 * ( only available in-memory feature matrices )
		 *
		 * @param src vector
		 * @param len length of vector
		 * @param num index where to put vector to
		 */
		void set_feature_vector(ST* src, int32_t len, int32_t num)
		{
			if (num>=num_vectors)
			{
				SG_ERROR("Index out of bounds (number of vectors %d, you "
						"requested %d)\n", num_vectors, num);
			}

			if (!feature_matrix)
				SG_ERROR("Requires a in-memory feature matrix\n");

			if (len != num_features)
				SG_ERROR("Vector not of length %d (has %d)\n", num_features, len);

			memcpy(&feature_matrix[num*int64_t(num_features)], src, int64_t(num_features)*sizeof(ST));
		}

		/** get feature vector num
		 *
		 * @param dst destination to store vector in
		 * @param len length of vector
		 * @param num index of vector
		 */
		void get_feature_vector(ST** dst, int32_t* len, int32_t num)
		{
			if (num>=num_vectors)
			{
				SG_ERROR("Index out of bounds (number of vectors %d, you "
						"requested %d)\n", num_vectors, num);
			}

			int32_t vlen=0;
			bool free_vec;

			ST* vec= get_feature_vector(num, vlen, free_vec);

			*len=vlen;
			*dst=(ST*) SG_MALLOC(vlen*sizeof(ST));
			memcpy(*dst, vec, vlen*sizeof(ST));

			free_feature_vector(vec, num, free_vec);
		}

		/** free feature vector
		 *
		 * @param feat_vec feature vector to free
		 * @param num index in feature cache
		 * @param dofree if vector should be really deleted
		 */
		void free_feature_vector(ST* feat_vec, int32_t num, bool dofree)
		{
			if (feature_cache)
				feature_cache->unlock_entry(num);

			if (dofree)
				delete[] feat_vec ;
		}

		/**
		 * Extracts the feature vectors mentioned in idx and replaces them in
		 * feature matrix in place. 
		 *
		 * It does not resize the allocated memory block.
		 *
		 * @param idx index with examples that shall remain in the feature matrix
		 * @param idx_len length of the index
		 *
		 * Note: assumes idx is sorted
		 */
		void vector_subset(int32_t* idx, int32_t idx_len)
		{
			ASSERT(feature_matrix);
			ASSERT(idx_len<=num_vectors);

			int32_t num_vec=num_vectors;
			num_vectors=idx_len;

			int32_t old_ii=-1;

			for (int32_t i=0; i<idx_len; i++)
			{
				int32_t ii=idx[i];
				ASSERT(old_ii<ii);
				if (ii<0 || ii>=num_vec)
					SG_ERROR("Index out of range: should be 0<%d<%d\n", ii, num_vec);

				if (i==ii)
					continue;

				memcpy(&feature_matrix[int64_t(num_features)*i],
						&feature_matrix[int64_t(num_features)*ii],
						num_features*sizeof(ST));
				old_ii=ii;
			}
		}

		/**
		 * Extracts the features mentioned in idx and replaces them in
		 * feature matrix in place. 
		 *
		 * It does not resize the allocated memory block.
		 *
		 * @param idx index with features that shall remain in the feature matrix
		 * @param idx_len length of the index
		 *
		 * Note: assumes idx is sorted
		 */
		void feature_subset(int32_t* idx, int32_t idx_len)
		{
			ASSERT(feature_matrix);
			ASSERT(idx_len<=num_features);
			int32_t num_feat=num_features;
			num_features=idx_len;

			for (int32_t i=0; i<num_vectors; i++)
			{
				ST* src=&feature_matrix[int64_t(num_feat)*i];
				ST* dst=&feature_matrix[int64_t(num_features)*i];

				int32_t old_jj=-1;
				for (int32_t j=0; j<idx_len; j++)
				{
					int32_t jj=idx[j];
					ASSERT(old_jj<jj);
					if (jj<0 || jj>=num_feat)
						SG_ERROR("Index out of range: should be 0<%d<%d\n", jj, num_feat);

					dst[j]=src[jj];
					old_jj=jj;
				}
			}
		}

		/** get a copy of the feature matrix
		 * num_feat,num_vectors are returned by reference
		 *
		 * @param dst destination to store matrix in
		 * @param num_feat number of features (rows of matrix)
		 * @param num_vec number of vectors (columns of matrix)
		 */
		void get_feature_matrix(ST** dst, int32_t* num_feat, int32_t* num_vec)
		{
			ASSERT(feature_matrix);

			int64_t num=int64_t(num_features)*num_vectors;
			*num_feat=num_features;
			*num_vec=num_vectors;
			*dst=(ST*) SG_MALLOC(sizeof(ST)*num);
			if (!*dst)
				SG_ERROR("Allocating %ld bytes failes\n", sizeof(ST)*num);
			memcpy(*dst, feature_matrix, num * sizeof(ST));
		}

		SGMatrix<ST> get_feature_matrix()
		{
			return SGMatrix<ST>(feature_matrix, num_features, num_vectors);
		}

		void set_feature_matrix(SGMatrix<ST> matrix)
		{
			feature_matrix=matrix.matrix;
			num_features=matrix.num_rows;
			num_vectors=matrix.num_cols;
		}

		/** get the pointer to the feature matrix
		 * num_feat,num_vectors are returned by reference
		 *
		 * @param num_feat number of features in matrix
		 * @param num_vec number of vectors in matrix
		 * @return feature matrix
		 */
		ST* get_feature_matrix(int32_t &num_feat, int32_t &num_vec)
		{
			num_feat=num_features;
			num_vec=num_vectors;
			return feature_matrix;
		}

		/** get a transposed copy of the features
		 *
		 * @return transposed copy
		 */
		CSimpleFeatures<ST>* get_transposed()
		{
			int32_t num_feat;
			int32_t num_vec;
			ST* fm=get_transposed(num_feat, num_vec);

			return new CSimpleFeatures<ST>(fm, num_feat, num_vec);
		}

		/** compute and return the transpose of the feature matrix
		 * which will be prepocessed.
		 * num_feat, num_vectors are returned by reference
		 * caller has to clean up
		 *
		 * @param num_feat number of features in matrix
		 * @param num_vec number of vectors in matrix
		 * @return transposed sparse feature matrix
		 */
		ST* get_transposed(int32_t &num_feat, int32_t &num_vec)
		{
			num_feat=num_vectors;
			num_vec=num_features;

			ST* fm=new ST[int64_t(num_feat)*num_vec];

			for (int32_t i=0; i<num_vectors; i++)
			{
				int32_t vlen;
				bool vfree;
				ST* vec=get_feature_vector(i, vlen, vfree);

				for (int32_t j=0; j<vlen; j++)
					fm[j*int64_t(num_vectors)+i]=vec[j];

				free_feature_vector(vec, i, vfree);
			}

			return fm;
		}

		/** set feature matrix
		 * necessary to set feature_matrix, num_features,
		 * num_vectors, where num_features is the column offset,
		 * and columns are linear in memory
		 * see below for definition of feature_matrix
		 *
		 * @param fm feature matrix to se
		 * @param num_feat number of features in matrix
		 * @param num_vec number of vectors in matrix
		 */
		virtual void set_feature_matrix(ST* fm, int32_t num_feat, int32_t num_vec)
		{
			free_feature_matrix();
			feature_matrix=fm;
			feature_matrix_num_features=num_feat;
			feature_matrix_num_vectors=num_vec;

			num_features=num_feat;
			num_vectors=num_vec;
			initialize_cache();
		}

		/** copy feature matrix
		 * store copy of feature_matrix, where num_features is the
		 * column offset, and columns are linear in memory
		 * see below for definition of feature_matrix
		 *
		 * @param src feature matrix to copy
		 * @param num_feat number of features in matrix
		 * @param num_vec number of vectors in matrix
		 */
		virtual void copy_feature_matrix(ST* src, int32_t num_feat, int32_t num_vec)
		{
			free_feature_matrix();
			feature_matrix=new ST[((int64_t) num_feat)*num_vec];
			feature_matrix_num_features=num_feat;
			feature_matrix_num_vectors=num_vec;

			memcpy(feature_matrix, src, (sizeof(ST)*((int64_t) num_feat)*num_vec));

			num_features=num_feat;
			num_vectors=num_vec;
			initialize_cache();
		}

		/** obtain simple features from other dotfeatures
		 *
		 * @param df dotfeatures to obtain features from
		 */
		void obtain_from_dot(CDotFeatures* df)
		{
			int32_t num_feat=df->get_dim_feature_space();
			int32_t num_vec=df->get_num_vectors();

			ASSERT(num_feat>0 && num_vec>0);

			free_feature_matrix();
			feature_matrix=new ST[((int64_t) num_feat)*num_vec];
			feature_matrix_num_features=num_feat;
			feature_matrix_num_vectors=num_vec;

			for (int32_t i=0; i<num_vec; i++)
			{
				float64_t* dst;
				int32_t len;
				df->get_feature_vector(&dst, &len, i);
				ASSERT(num_feat==len);

				for (int32_t j=0; j<num_feat; j++)
					feature_matrix[i*int64_t(num_feat)+j]=(ST) dst[j];

				delete[] dst;
			}
			num_features=num_feat;
			num_vectors=num_vec;
		}

		/** apply preprocessor
		 *
		 * @param force_preprocessing if preprocssing shall be forced
		 * @return if applying was successful
		 */
		virtual bool apply_preproc(bool force_preprocessing=false)
		{
			SG_DEBUG( "force: %d\n", force_preprocessing);

			if ( feature_matrix && get_num_preproc())
			{

				for (int32_t i=0; i<get_num_preproc(); i++)
				{ 
					if ( (!is_preprocessed(i) || force_preprocessing) )
					{
						set_preprocessed(i);
						CSimplePreprocessor<ST>* p = (CSimplePreprocessor<ST>*) get_preproc(i);
						SG_INFO( "preprocessing using preproc %s\n", p->get_name());
						if (p->apply_to_feature_matrix(this) == NULL)
						{
							SG_UNREF(p);
							return false;
						}
						SG_UNREF(p);
					}
				}
				return true;
			}
			else
			{
				if (!feature_matrix)
					SG_ERROR( "no feature matrix\n");

				if (!get_num_preproc())
					SG_ERROR( "no preprocessors available\n");

				return false;
			}
		}

		/** get memory footprint of one feature
		 *
		 * @return memory footprint of one feature
		 */
		virtual int32_t get_size() { return sizeof(ST); }


		/** get number of feature vectors
		 *
		 * @return number of feature vectors
		 */
		virtual inline int32_t  get_num_vectors() { return num_vectors; }

		/** get number of features
		 *
		 * @return number of features
		 */
		inline int32_t  get_num_features() { return num_features; }

		/** set number of features
		 *
		 * @param num number to set
		 */
		inline void set_num_features(int32_t num)
		{ 
			num_features= num;
			initialize_cache();
		}

		/** set number of vectors
		 *
		 * @param num number to set
		 */
		inline void set_num_vectors(int32_t num)
		{
			num_vectors= num;
			initialize_cache();
		}

		/* Initialize cache */
		inline void initialize_cache()
		{
			if (num_features && num_vectors)
			{
				SG_UNREF(feature_cache);
				feature_cache= new CCache<ST>(get_cache_size(), num_features, num_vectors);
				SG_REF(feature_cache);
			}
		}

		/** get feature class
		 *
		 * @return feature class SIMPLE
		 */
		inline virtual EFeatureClass get_feature_class() { return C_SIMPLE; }

		/** get feature type
		 *
		 * @return templated feature type
		 */
		inline virtual EFeatureType get_feature_type();

		/** reshape
		 *
		 * @param p_num_features new number of features
		 * @param p_num_vectors new number of vectors
		 * @return if reshaping was successful
		 */
		virtual bool reshape(int32_t p_num_features, int32_t p_num_vectors)
		{
			if (p_num_features*p_num_vectors == this->num_features * this->num_vectors)
			{
				this->num_features=p_num_features;
				this->num_vectors=p_num_vectors;
				return true;
			}
			else
				return false;
		}

		/** obtain the dimensionality of the feature space
		 *
		 * (not mix this up with the dimensionality of the input space, usually
		 * obtained via get_num_features())
		 *
		 * @return dimensionality
		 */
		virtual int32_t get_dim_feature_space()
		{
			return num_features;
		}

		/** compute dot product between vector1 and vector2,
		 * appointed by their indices
		 *
		 * @param vec_idx1 index of first vector
		 * @param df DotFeatures (of same kind) to compute dot product with
		 * @param vec_idx2 index of second vector
		 */
		virtual float64_t dot(int32_t vec_idx1, CDotFeatures* df, int32_t vec_idx2)
		{
			ASSERT(df);
			ASSERT(df->get_feature_type() == get_feature_type());
			ASSERT(df->get_feature_class() == get_feature_class());
			CSimpleFeatures<ST>* sf=(CSimpleFeatures<ST>*) df;

			int32_t len1, len2;
			bool free1, free2;

			ST* vec1= get_feature_vector(vec_idx1, len1, free1);
			ST* vec2= sf->get_feature_vector(vec_idx2, len2, free2);

			float64_t result=CMath::dot(vec1, vec2, len1);

			free_feature_vector(vec1, vec_idx1, free1);
			sf->free_feature_vector(vec2, vec_idx2, free2);

			return result;
		}

		/** compute dot product between vector1 and a dense vector
		 *
		 * @param vec_idx1 index of first vector
		 * @param vec2 pointer to real valued vector
		 * @param vec2_len length of real valued vector
		 */
		virtual float64_t dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len);

		/** add vector 1 multiplied with alpha to dense vector2
		 *
		 * @param alpha scalar alpha
		 * @param vec_idx1 index of first vector
		 * @param vec2 pointer to real valued vector
		 * @param vec2_len length of real valued vector
		 * @param abs_val if true add the absolute value
		 */
		virtual void add_to_dense_vec(float64_t alpha, int32_t vec_idx1, float64_t* vec2, int32_t vec2_len, bool abs_val=false)
		{
			ASSERT(vec2_len == num_features);

			int32_t vlen;
			bool vfree;
			ST* vec1=get_feature_vector(vec_idx1, vlen, vfree);

			ASSERT(vlen == num_features);

			if (abs_val)
			{
				for (int32_t i=0; i<num_features; i++)
					vec2[i]+=alpha*CMath::abs(vec1[i]);
			}
			else
			{
				for (int32_t i=0; i<num_features; i++)
					vec2[i]+=alpha*vec1[i];
			}

			free_feature_vector(vec1, vec_idx1, vfree);
		}

		/** get number of non-zero features in vector
		 *
		 * @param num which vector
		 * @return number of non-zero features in vector
		 */
		virtual inline int32_t get_nnz_features_for_vector(int32_t num)
		{
			return num_features;
		}

		/** align char features
		 *
		 * @param cf char features
		 * @param Ref other char features
		 * @param gapCost gap cost
		 * @return if aligning was successful
		 */
		virtual inline bool Align_char_features(
			CStringFeatures<char>* cf, CStringFeatures<char>* Ref, float64_t gapCost)
		{
			return false;
		}

		/** load features from file
		 *
		 * @param loader File object via which to load data
		 */
		virtual inline void load(CFile* loader);

		/** save features to file
		 *
		 * @param saver File object via which to save data
		 */
		virtual inline void save(CFile* saver);

		/** iterator for simple features */
		struct simple_feature_iterator
		{
			/** pointer to feature vector */
			ST* vec;
			/** index of vector */
			int32_t vidx;
			/** length of vector */
			int32_t vlen;
			/** if we need to free the vector*/
			bool vfree;

			/** feature index */
			int32_t index;
		};

		/** iterate over the non-zero features
		 *
		 * call get_feature_iterator first, followed by get_next_feature and
		 * free_feature_iterator to cleanup
		 *
		 * @param vector_index the index of the vector over whose components to
		 * 			iterate over
		 * @return feature iterator (to be passed to get_next_feature)
		 */
		virtual void* get_feature_iterator(int32_t vector_index)
		{
			if (vector_index>=num_vectors)
			{
				SG_ERROR("Index out of bounds (number of vectors %d, you "
						"requested %d)\n", num_vectors, vector_index);
			}

			simple_feature_iterator* iterator=new simple_feature_iterator[1];
			iterator->vec= get_feature_vector(vector_index, iterator->vlen, iterator->vfree);
			iterator->vidx=vector_index;
			iterator->index=0;
			return iterator;
		}

		/** iterate over the non-zero features
		 *
		 * call this function with the iterator returned by get_first_feature
		 * and call free_feature_iterator to cleanup
		 *
		 * @param index is returned by reference (-1 when not available)
		 * @param value is returned by reference
		 * @param iterator as returned by get_first_feature
		 * @return true if a new non-zero feature got returned
		 */
		virtual bool get_next_feature(int32_t& index, float64_t& value, void* iterator)
		{
			simple_feature_iterator* it=(simple_feature_iterator*) iterator;
			if (!it || it->index>=it->vlen)
				return false;

			index=it->index++;
			value = (float64_t) it->vec[index];

			return true;
		}

		/** clean up iterator
		 * call this function with the iterator returned by get_first_feature
		 *
		 * @param iterator as returned by get_first_feature
		 */
		virtual void free_feature_iterator(void* iterator)
		{
			if (!iterator)
				return;

			simple_feature_iterator* it=(simple_feature_iterator*) iterator;
			free_feature_vector(it->vec, it->vidx, it->vfree);
			delete[] it;
		}

		/** @return object name */
		inline virtual const char* get_name() const { return "SimpleFeatures"; }

	protected:
		/** compute feature vector for sample num
		 * if target is set the vector is written to target
		 * len is returned by reference
		 *
		 * NOT IMPLEMENTED!
		 *
		 * @param num num
		 * @param len len
		 * @param target
		 * @return feature vector
		 */
		virtual ST* compute_feature_vector(int32_t num, int32_t& len, ST* target=NULL)
		{
			len=0;
			return NULL;
		}

	private:
		void init()
		{
			num_vectors=0;
			num_features=0;

			feature_matrix=NULL;
			feature_matrix_num_vectors=0;
			feature_matrix_num_features=0;

			feature_cache=NULL;

			set_generic<ST>();
			m_parameters->add(&num_vectors,
						"num_vectors", "Number of vectors.");
			m_parameters->add(&num_features,
						"num_features", "Number of features.");
			m_parameters->add_matrix(&feature_matrix,
					&feature_matrix_num_features, &feature_matrix_num_vectors,
					"feature_matrix", "Matrix of feature vectors / 1 vector per column.");
		}

	protected:
		/// number of vectors in cache
		int32_t num_vectors;

		/// number of features in cache
		int32_t num_features;

		/** Feature matrix and its associated number of
		 * vectors and features. Note that num_vectors / num_features
		 * above have the same sizes if feature_matrix != NULL
		 * */
		ST* feature_matrix;
		int32_t feature_matrix_num_vectors;
		int32_t feature_matrix_num_features;

		/** feature cache */
		CCache<ST>* feature_cache;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#define GET_FEATURE_TYPE(f_type, sg_type)	\
template<> inline EFeatureType CSimpleFeatures<sg_type>::get_feature_type() \
{ 																			\
	return f_type; 															\
}

GET_FEATURE_TYPE(F_BOOL, bool)
GET_FEATURE_TYPE(F_CHAR, char)
GET_FEATURE_TYPE(F_BYTE, uint8_t)
GET_FEATURE_TYPE(F_BYTE, int8_t)
GET_FEATURE_TYPE(F_SHORT, int16_t)
GET_FEATURE_TYPE(F_WORD, uint16_t)
GET_FEATURE_TYPE(F_INT, int32_t)
GET_FEATURE_TYPE(F_UINT, uint32_t)
GET_FEATURE_TYPE(F_LONG, int64_t)
GET_FEATURE_TYPE(F_ULONG, uint64_t)
GET_FEATURE_TYPE(F_SHORTREAL, float32_t)
GET_FEATURE_TYPE(F_DREAL, float64_t)
GET_FEATURE_TYPE(F_LONGREAL, floatmax_t)
#undef GET_FEATURE_TYPE

/** align strings and compute emperical kernel map based on alignment scores
 *
 * non functional code - needs updating
 *
 * @param cf strings to be aligned to reference
 * @param Ref reference strings to be aligned to
 * @param gapCost costs for a gap
 */
template<> inline bool CSimpleFeatures<float64_t>::Align_char_features(
		CStringFeatures<char>* cf, CStringFeatures<char>* Ref, float64_t gapCost)
{
	ASSERT(cf);
	/*num_vectors=cf->get_num_vectors();
	num_features=Ref->get_num_vectors();

	int64_t len=((int64_t) num_vectors)*num_features;
	free_feature_matrix();
	feature_matrix=new float64_t[len];
	int32_t num_cf_feat=0;
	int32_t num_cf_vec=0;
	int32_t num_ref_feat=0;
	int32_t num_ref_vec=0;
	char* fm_cf=NULL; //cf->get_feature_matrix(num_cf_feat, num_cf_vec);
	char* fm_ref=NULL; //Ref->get_feature_matrix(num_ref_feat, num_ref_vec);

	ASSERT(num_cf_vec==num_vectors);
	ASSERT(num_ref_vec==num_features);

	SG_INFO( "computing aligments of %i vectors to %i reference vectors: ", num_cf_vec, num_ref_vec) ;
	for (int32_t i=0; i< num_ref_vec; i++)
	{
		SG_PROGRESS(i, num_ref_vec) ;
		for (int32_t j=0; j<num_cf_vec; j++)
			feature_matrix[i+j*num_features] = CMath::Align(&fm_cf[j*num_cf_feat], &fm_ref[i*num_ref_feat], num_cf_feat, num_ref_feat, gapCost);
	} ;

	SG_INFO( "created %i x %i matrix (0x%p)\n", num_features, num_vectors, feature_matrix) ;*/
	return true;
}

template<> inline float64_t CSimpleFeatures<bool>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	bool* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i] ? vec2[i] : 0;

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}


template<> inline float64_t CSimpleFeatures<char>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	char* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<int8_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	int8_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<uint8_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	uint8_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<int16_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	int16_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}


template<> inline float64_t CSimpleFeatures<uint16_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	uint16_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<int32_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	int32_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<uint32_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	uint32_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<int64_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	int64_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<uint64_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	uint64_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<float32_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	float32_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<float64_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	float64_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=CMath::dot(vec1, vec2, num_features);

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

template<> inline float64_t CSimpleFeatures<floatmax_t>:: dense_dot(int32_t vec_idx1, const float64_t* vec2, int32_t vec2_len)
{
	ASSERT(vec2_len == num_features);

	int32_t vlen;
	bool vfree;
	floatmax_t* vec1= get_feature_vector(vec_idx1, vlen, vfree);

	ASSERT(vlen == num_features);
	float64_t result=0;

	for (int32_t i=0 ; i<num_features; i++)
		result+=vec1[i]*vec2[i];

	free_feature_vector(vec1, vec_idx1, vfree);

	return result;
}

#define LOAD(f_load, sg_type)												\
template<> inline void CSimpleFeatures<sg_type>::load(CFile* loader)		\
{ 																			\
	SG_SET_LOCALE_C;													\
	ASSERT(loader);															\
	sg_type* matrix;														\
	int32_t num_feat;														\
	int32_t num_vec;														\
	loader->f_load(matrix, num_feat, num_vec);								\
	set_feature_matrix(matrix, num_feat, num_vec);							\
	SG_RESET_LOCALE;													\
}

LOAD(get_bool_matrix, bool)
LOAD(get_char_matrix, char)
LOAD(get_int8_matrix, int8_t)
LOAD(get_byte_matrix, uint8_t)
LOAD(get_short_matrix, int16_t)
LOAD(get_word_matrix, uint16_t)
LOAD(get_int_matrix, int32_t)
LOAD(get_uint_matrix, uint32_t)
LOAD(get_long_matrix, int64_t)
LOAD(get_ulong_matrix, uint64_t)
LOAD(get_shortreal_matrix, float32_t)
LOAD(get_real_matrix, float64_t)
LOAD(get_longreal_matrix, floatmax_t)
#undef LOAD

#define SAVE(f_write, sg_type)												\
template<> inline void CSimpleFeatures<sg_type>::save(CFile* writer)		\
{ 																			\
	SG_SET_LOCALE_C;													\
	ASSERT(writer);															\
	writer->f_write(feature_matrix, num_features, num_vectors);				\
	SG_RESET_LOCALE;													\
}

SAVE(set_bool_matrix, bool)
SAVE(set_char_matrix, char)
SAVE(set_int8_matrix, int8_t)
SAVE(set_byte_matrix, uint8_t)
SAVE(set_short_matrix, int16_t)
SAVE(set_word_matrix, uint16_t)
SAVE(set_int_matrix, int32_t)
SAVE(set_uint_matrix, uint32_t)
SAVE(set_long_matrix, int64_t)
SAVE(set_ulong_matrix, uint64_t)
SAVE(set_shortreal_matrix, float32_t)
SAVE(set_real_matrix, float64_t)
SAVE(set_longreal_matrix, floatmax_t)
#undef SAVE

#endif // DOXYGEN_SHOULD_SKIP_THIS
}
#endif // _SIMPLEFEATURES__H__
