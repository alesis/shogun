/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2010 Soeren Sonnenburg
 * Copyright (C) 2010 Berlin Institute of Technology
 */

#include "base/Parameter.h"
#include "base/class_list.h"

using namespace shogun;

extern IO* sg_io;

/* **************************************************************** */
/* Scalar wrappers  */

void
Parameter::add(bool* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_BOOL);
	add_type(&type, param, name, description);
}

void
Parameter::add(char* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_CHAR);
	add_type(&type, param, name, description);
}

void
Parameter::add(int8_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_INT8);
	add_type(&type, param, name, description);
}

void
Parameter::add(uint8_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_UINT8);
	add_type(&type, param, name, description);
}

void
Parameter::add(int16_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_INT16);
	add_type(&type, param, name, description);
}

void
Parameter::add(uint16_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_UINT16);
	add_type(&type, param, name, description);
}

void
Parameter::add(int32_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_INT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(uint32_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_UINT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(int64_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_INT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(uint64_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_UINT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(float32_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_FLOAT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(float64_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_FLOAT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(floatmax_t* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_FLOATMAX);
	add_type(&type, param, name, description);
}

void
Parameter::add(CSGObject** param,
			   const char* name, const char* description) {
	TSGDataType type(CT_SCALAR, ST_NONE, PT_SGOBJECT);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<bool>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_BOOL);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<char>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_CHAR);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<int8_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_INT8);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<uint8_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_UINT8);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<int16_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_INT16);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<uint16_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_UINT16);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<int32_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_INT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<uint32_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_UINT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<int64_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_INT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<uint64_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_UINT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<float32_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_FLOAT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<float64_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_FLOAT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGString<floatmax_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_STRING, PT_FLOATMAX);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<bool>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_BOOL);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<char>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_CHAR);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<int8_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_INT8);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<uint8_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_UINT8);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<int16_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_INT16);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<uint16_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_UINT16);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<int32_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_INT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<uint32_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_UINT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<int64_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_INT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<uint64_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_UINT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<float32_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_FLOAT32);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<float64_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_FLOAT64);
	add_type(&type, param, name, description);
}

void
Parameter::add(SGSparseVector<floatmax_t>* param, const char* name,
			   const char* description) {
	TSGDataType type(CT_SCALAR, ST_SPARSE, PT_FLOATMAX);
	add_type(&type, param, name, description);
}

/* **************************************************************** */
/* Vector wrappers  */

void
Parameter::add_vector(
	bool** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_BOOL, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	char** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_CHAR, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	int8_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT8, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	uint8_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT8, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	int16_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT16, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	uint16_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT16, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	int32_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	uint32_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	int64_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	uint64_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	float32_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_FLOAT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	float64_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_FLOAT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(
	floatmax_t** param, index_t* length, const char* name,
	const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_FLOATMAX, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(CSGObject*** param, index_t* length,
					   const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_NONE, PT_SGOBJECT,
					 length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<bool>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_BOOL, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<char>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_CHAR, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<int8_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT8, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<uint8_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT8, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<int16_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT16, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<uint16_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT16, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<int32_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<uint32_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<int64_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<uint64_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<float32_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_FLOAT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<float64_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_FLOAT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGString<floatmax_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_STRING, PT_FLOATMAX, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<bool>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_BOOL, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<char>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_CHAR, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<int8_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT8, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<uint8_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT8, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<int16_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT16, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<uint16_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT16, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<int32_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<uint32_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<int64_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<uint64_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<float32_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_FLOAT32, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<float64_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_FLOAT64, length);
	add_type(&type, param, name, description);
}

void
Parameter::add_vector(SGSparseVector<floatmax_t>** param, index_t* length,
					  const char* name, const char* description) {
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_FLOATMAX, length);
	add_type(&type, param, name, description);
}




void Parameter::add(SGVector<bool>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_BOOL, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<char>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_CHAR, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<int8_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT8, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<uint8_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT8, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<int16_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT16, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<uint16_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT16, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<int32_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<uint32_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<int64_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_INT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<uint64_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_UINT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<float32_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_FLOAT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<float64_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_FLOAT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<floatmax_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_FLOATMAX, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<CSGObject*>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_NONE, PT_SGOBJECT, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<bool> >* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_BOOL, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<char> >* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_CHAR, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<int8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT8, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<uint8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT8, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<int16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT16, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<uint16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT16, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<int32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<uint32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<int64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_INT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<uint64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_UINT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<float32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_FLOAT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<float64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_FLOAT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGString<floatmax_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_STRING, PT_FLOATMAX, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<bool> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_BOOL, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<char> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_CHAR, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<int8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT8, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<uint8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT8, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<int16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT16, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<uint16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT16, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<int32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<uint32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<int64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_INT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<uint64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_UINT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<float32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_FLOAT32, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<float64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_FLOAT64, &param->length);
	add_type(&type, param, name, description);
}

void Parameter::add(SGVector<SGSparseVector<floatmax_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_VECTOR, ST_SPARSE, PT_FLOATMAX, &param->length);
	add_type(&type, param, name, description);
}

/* **************************************************************** */
/* Matrix wrappers  */

void
Parameter::add_matrix(
	bool** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_BOOL, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	char** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_CHAR, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	int8_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT8, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	uint8_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT8, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	int16_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT16, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	uint16_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT16, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	int32_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	uint32_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	int64_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	uint64_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	float32_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_FLOAT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	float64_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_FLOAT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	floatmax_t** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_FLOATMAX, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(
	CSGObject*** param, index_t* length_y, index_t* length_x,
	const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_NONE, PT_SGOBJECT,
					 length_y, length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<bool>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_BOOL, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<char>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_CHAR, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<int8_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT8, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<uint8_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT8, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<int16_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT16, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<uint16_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT16, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<int32_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<uint32_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<int64_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<uint64_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<float32_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_FLOAT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<float64_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_FLOAT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGString<floatmax_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_STRING, PT_FLOATMAX, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<bool>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_BOOL, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<char>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_CHAR, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<int8_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT8, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<uint8_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT8, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<int16_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT16, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<uint16_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT16, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<int32_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<uint32_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<int64_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<uint64_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<float32_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_FLOAT32, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<float64_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_FLOAT64, length_y,
					 length_x);
	add_type(&type, param, name, description);
}

void
Parameter::add_matrix(SGSparseVector<floatmax_t>** param,
					  index_t* length_y, index_t* length_x,
					  const char* name, const char* description) {
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_FLOATMAX, length_y,
					 length_x);
	add_type(&type, param, name, description);
}




void Parameter::add(SGMatrix<bool>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_BOOL, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<char>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_CHAR, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<int8_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT8, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<uint8_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT8, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<int16_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT16, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<uint16_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT16, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<int32_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<uint32_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<int64_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_INT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<uint64_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_UINT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<float32_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_FLOAT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<float64_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_FLOAT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<floatmax_t>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_FLOATMAX, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<CSGObject*>* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_NONE, PT_SGOBJECT, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<bool> >* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_BOOL, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<char> >* param, const char* name,
		const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_CHAR, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<int8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT8, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<uint8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT8, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<int16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT16, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<uint16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT16, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<int32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<uint32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<int64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_INT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<uint64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_UINT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<float32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_FLOAT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<float64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_FLOAT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGString<floatmax_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_STRING, PT_FLOATMAX, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<bool> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_BOOL, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<char> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_CHAR, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<int8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT8, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<uint8_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT8, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<int16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT16, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<uint16_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT16, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<int32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<uint32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<int64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_INT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<uint64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_UINT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<float32_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_FLOAT32, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<float64_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_FLOAT64, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}

void Parameter::add(SGMatrix<SGSparseVector<floatmax_t> >* param,
		const char* name, const char* description)
{
	TSGDataType type(CT_MATRIX, ST_SPARSE, PT_FLOATMAX, &param->num_rows,
			&param->num_cols);
	add_type(&type, param, name, description);
}
/* **************************************************************** */
/* End of wrappers  */

TParameter::TParameter(const TSGDataType* datatype, void* parameter,
					   const char* name, const char* description)
	:m_datatype(*datatype)
{
	m_parameter = parameter;
	m_name = strdup(name);
	m_description = strdup(description);
}

TParameter::~TParameter(void)
{
	SG_FREE(m_description);
	SG_FREE(m_name);
}

char*
TParameter::new_prefix(const char* s1, const char* s2)
{
	char* tmp = new char[strlen(s1)+strlen(s2)+2];

	sprintf(tmp, "%s%s/", s1, s2);

	return tmp;
}

void
TParameter::print(const char* prefix)
{
	string_t buf;
	m_datatype.to_string(buf, STRING_LEN);

	SG_SPRINT("\n%s\n%35s %24s :%s\n", prefix, m_description == NULL
			 || *m_description == '\0' ? "(Parameter)": m_description,
			 m_name, buf);

	if (m_datatype.m_ptype == PT_SGOBJECT
		&& m_datatype.m_stype == ST_NONE
		&& m_datatype.m_ctype == CT_SCALAR
		&& *(CSGObject**) m_parameter != NULL) {
		char* p = new_prefix(prefix, m_name);
		(*(CSGObject**) m_parameter)->print_serializable(p);
		delete p;
	}
}

void
TParameter::delete_cont(void)
{
	if (*(void**) m_parameter != NULL) {
		index_t old_length = *m_datatype.m_length_y;
		switch (m_datatype.m_ctype) {
		case CT_MATRIX:
			old_length *= *m_datatype.m_length_x; break;
		case CT_SCALAR: case CT_VECTOR: break;
		}

		switch (m_datatype.m_stype) {
		case ST_NONE:
			switch (m_datatype.m_ptype) {
			case PT_BOOL:
				delete[] *(bool**) m_parameter; break;
			case PT_CHAR:
				delete[] *(char**) m_parameter; break;
			case PT_INT8:
				delete[] *(int8_t**) m_parameter; break;
			case PT_UINT8:
				delete[] *(uint8_t**) m_parameter; break;
			case PT_INT16:
				delete[] *(int16_t**) m_parameter; break;
			case PT_UINT16:
				delete[] *(uint16_t**) m_parameter; break;
			case PT_INT32:
				delete[] *(int32_t**) m_parameter; break;
			case PT_UINT32:
				delete[] *(uint32_t**) m_parameter; break;
			case PT_INT64:
				delete[] *(int64_t**) m_parameter; break;
			case PT_UINT64:
				delete[] *(uint64_t**) m_parameter; break;
			case PT_FLOAT32:
				delete[] *(float32_t**) m_parameter; break;
			case PT_FLOAT64:
				delete[] *(float64_t**) m_parameter; break;
			case PT_FLOATMAX:
				delete[] *(floatmax_t**) m_parameter; break;
			case PT_SGOBJECT:
				CSGObject** buf =
					*(CSGObject***) m_parameter;
				for (index_t i=0; i<old_length; i++)
					if (buf[i] != NULL) SG_UNREF(buf[i]);
				delete buf;
				break;
			}
			break;
		case ST_STRING:
			for (index_t i=0; i<old_length; i++) {
				SGString<char>* buf = (SGString<char>*) (*(char**)
						m_parameter + i *m_datatype.sizeof_stype());
				if (buf->length > 0) delete[] buf->string;
			}

			switch (m_datatype.m_ptype) {
			case PT_BOOL:
				delete[] *(SGString<bool>**) m_parameter; break;
			case PT_CHAR:
				delete[] *(SGString<char>**) m_parameter; break;
			case PT_INT8:
				delete[] *(SGString<int8_t>**) m_parameter; break;
			case PT_UINT8:
				delete[] *(SGString<uint8_t>**) m_parameter; break;
			case PT_INT16:
				delete[] *(SGString<int16_t>**) m_parameter; break;
			case PT_UINT16:
				delete[] *(SGString<uint16_t>**) m_parameter; break;
			case PT_INT32:
				delete[] *(SGString<int32_t>**) m_parameter; break;
			case PT_UINT32:
				delete[] *(SGString<uint32_t>**) m_parameter; break;
			case PT_INT64:
				delete[] *(SGString<int64_t>**) m_parameter; break;
			case PT_UINT64:
				delete[] *(SGString<uint64_t>**) m_parameter; break;
			case PT_FLOAT32:
				delete[] *(SGString<float32_t>**) m_parameter; break;
			case PT_FLOAT64:
				delete[] *(SGString<float64_t>**) m_parameter; break;
			case PT_FLOATMAX:
				delete[] *(SGString<floatmax_t>**) m_parameter; break;
			case PT_SGOBJECT:
				SG_SERROR("TParameter::delete_cont(): Implementation "
						 "error: Could not delete "
						 "String<SGSerializable*>");
				break;
			}
			break;
		case ST_SPARSE:
			for (index_t i=0; i<old_length; i++) {
				SGSparseVector<char>* buf = (SGSparseVector<char>*) (*(char**)
						m_parameter + i *m_datatype.sizeof_stype());
				if (buf->num_feat_entries > 0) delete[] buf->features;
			}

			switch (m_datatype.m_ptype) {
			case PT_BOOL:
				delete[] *(SGSparseVector<bool>**) m_parameter; break;
			case PT_CHAR:
				delete[] *(SGSparseVector<char>**) m_parameter; break;
			case PT_INT8:
				delete[] *(SGSparseVector<int8_t>**) m_parameter; break;
			case PT_UINT8:
				delete[] *(SGSparseVector<uint8_t>**) m_parameter; break;
			case PT_INT16:
				delete[] *(SGSparseVector<int16_t>**) m_parameter; break;
			case PT_UINT16:
				delete[] *(SGSparseVector<uint16_t>**) m_parameter; break;
			case PT_INT32:
				delete[] *(SGSparseVector<int32_t>**) m_parameter; break;
			case PT_UINT32:
				delete[] *(SGSparseVector<uint32_t>**) m_parameter; break;
			case PT_INT64:
				delete[] *(SGSparseVector<int64_t>**) m_parameter; break;
			case PT_UINT64:
				delete[] *(SGSparseVector<uint64_t>**) m_parameter; break;
			case PT_FLOAT32:
				delete[] *(SGSparseVector<float32_t>**) m_parameter; break;
			case PT_FLOAT64:
				delete[] *(SGSparseVector<float64_t>**) m_parameter; break;
			case PT_FLOATMAX:
				delete[] *(SGSparseVector<floatmax_t>**) m_parameter; break;
			case PT_SGOBJECT:
				SG_SERROR("TParameter::delete_cont(): Implementation "
						 "error: Could not delete "
						 "Sparse<SGSerializable*>");
				break;
			}
			break;
		} /* switch (m_datatype.m_stype)  */
	} /* if (*(void**) m_parameter != NULL)  */

	*(void**) m_parameter = NULL;
}

void
TParameter::new_cont(index_t new_len_y, index_t new_len_x)
{
	delete_cont();

	index_t new_length = new_len_y*new_len_x;
	if (new_length == 0) return;

	switch (m_datatype.m_stype) {
	case ST_NONE:
		switch (m_datatype.m_ptype) {
		case PT_BOOL:
			*(bool**) m_parameter
				= new bool[new_length]; break;
		case PT_CHAR:
			*(char**) m_parameter
				= new char[new_length]; break;
		case PT_INT8:
			*(int8_t**) m_parameter
				= new int8_t[new_length]; break;
		case PT_UINT8:
			*(uint8_t**) m_parameter
				= new uint8_t[new_length]; break;
		case PT_INT16:
			*(int16_t**) m_parameter
				= new int16_t[new_length]; break;
		case PT_UINT16:
			*(uint16_t**) m_parameter
				= new uint16_t[new_length]; break;
		case PT_INT32:
			*(int32_t**) m_parameter
				= new int32_t[new_length]; break;
		case PT_UINT32:
			*(uint32_t**) m_parameter
				= new uint32_t[new_length]; break;
		case PT_INT64:
			*(int64_t**) m_parameter
				= new int64_t[new_length]; break;
		case PT_UINT64:
			*(uint64_t**) m_parameter
				= new uint64_t[new_length]; break;
		case PT_FLOAT32:
			*(float32_t**) m_parameter
				= new float32_t[new_length]; break;
		case PT_FLOAT64:
			*(float64_t**) m_parameter
				= new float64_t[new_length]; break;
		case PT_FLOATMAX:
			*(floatmax_t**) m_parameter
				= new floatmax_t[new_length]; break;
		case PT_SGOBJECT:
			*(CSGObject***) m_parameter
				= new CSGObject*[new_length]();
			break;
		}
		break;
	case ST_STRING:
		switch (m_datatype.m_ptype) {
		case PT_BOOL:
			*(SGString<bool>**) m_parameter
				= new SGString<bool>[new_length]; break;
		case PT_CHAR:
			*(SGString<char>**) m_parameter
				= new SGString<char>[new_length]; break;
		case PT_INT8:
			*(SGString<int8_t>**) m_parameter
				= new SGString<int8_t>[new_length]; break;
		case PT_UINT8:
			*(SGString<uint8_t>**) m_parameter
				= new SGString<uint8_t>[new_length]; break;
		case PT_INT16:
			*(SGString<int16_t>**) m_parameter
				= new SGString<int16_t>[new_length]; break;
		case PT_UINT16:
			*(SGString<uint16_t>**) m_parameter
				= new SGString<uint16_t>[new_length]; break;
		case PT_INT32:
			*(SGString<int32_t>**) m_parameter
				= new SGString<int32_t>[new_length]; break;
		case PT_UINT32:
			*(SGString<uint32_t>**) m_parameter
				= new SGString<uint32_t>[new_length]; break;
		case PT_INT64:
			*(SGString<int64_t>**) m_parameter
				= new SGString<int64_t>[new_length]; break;
		case PT_UINT64:
			*(SGString<uint64_t>**) m_parameter
				= new SGString<uint64_t>[new_length]; break;
		case PT_FLOAT32:
			*(SGString<float32_t>**) m_parameter
				= new SGString<float32_t>[new_length]; break;
		case PT_FLOAT64:
			*(SGString<float64_t>**) m_parameter
				= new SGString<float64_t>[new_length]; break;
		case PT_FLOATMAX:
			*(SGString<floatmax_t>**) m_parameter
				= new SGString<floatmax_t>[new_length]; break;
		case PT_SGOBJECT:
			SG_SERROR("TParameter::new_cont(): Implementation "
					 "error: Could not allocate "
					 "String<SGSerializable*>");
			break;
		}
		memset(*(void**) m_parameter, 0, new_length
			   *m_datatype.sizeof_stype());
		break;
	case ST_SPARSE:
		switch (m_datatype.m_ptype) {
		case PT_BOOL:
			*(SGSparseVector<bool>**) m_parameter
				= new SGSparseVector<bool>[new_length]; break;
		case PT_CHAR:
			*(SGSparseVector<char>**) m_parameter
				= new SGSparseVector<char>[new_length]; break;
		case PT_INT8:
			*(SGSparseVector<int8_t>**) m_parameter
				= new SGSparseVector<int8_t>[new_length]; break;
		case PT_UINT8:
			*(SGSparseVector<uint8_t>**) m_parameter
				= new SGSparseVector<uint8_t>[new_length]; break;
		case PT_INT16:
			*(SGSparseVector<int16_t>**) m_parameter
				= new SGSparseVector<int16_t>[new_length]; break;
		case PT_UINT16:
			*(SGSparseVector<uint16_t>**) m_parameter
				= new SGSparseVector<uint16_t>[new_length]; break;
		case PT_INT32:
			*(SGSparseVector<int32_t>**) m_parameter
				= new SGSparseVector<int32_t>[new_length]; break;
		case PT_UINT32:
			*(SGSparseVector<uint32_t>**) m_parameter
				= new SGSparseVector<uint32_t>[new_length]; break;
		case PT_INT64:
			*(SGSparseVector<int64_t>**) m_parameter
				= new SGSparseVector<int64_t>[new_length]; break;
		case PT_UINT64:
			*(SGSparseVector<uint64_t>**) m_parameter
				= new SGSparseVector<uint64_t>[new_length]; break;
		case PT_FLOAT32:
			*(SGSparseVector<float32_t>**) m_parameter
				= new SGSparseVector<float32_t>[new_length]; break;
		case PT_FLOAT64:
			*(SGSparseVector<float64_t>**) m_parameter
				= new SGSparseVector<float64_t>[new_length]; break;
		case PT_FLOATMAX:
			*(SGSparseVector<floatmax_t>**) m_parameter
				= new SGSparseVector<floatmax_t>[new_length]; break;
		case PT_SGOBJECT:
			SG_SERROR("TParameter::new_cont(): Implementation "
					 "error: Could not allocate "
					 "Sparse<SGSerializable*>");
			break;
		}
		memset(*(void**) m_parameter, 0, new_length
			   *m_datatype.sizeof_stype());
		break;
	} /* switch (m_datatype.m_stype)  */
}

bool
TParameter::new_sgserial(CSGObject** param,
						 EPrimitiveType generic,
						 const char* sgserializable_name,
						 const char* prefix)
{
	if (*param != NULL)
		SG_UNREF(*param);

	*param = new_sgserializable(sgserializable_name, generic);

	if (*param == NULL) {
		string_t buf = {'\0'};

		if (generic != PT_NOT_GENERIC) {
			buf[0] = '<';
			TSGDataType::ptype_to_string(buf+1, generic,
										 STRING_LEN - 3);
			strcat(buf, ">");
		}

		SG_SWARNING("TParameter::new_sgserial(): "
				   "Class `C%s%s' was not listed during compiling Shogun"
				   " :( ...  Can not construct it for `%s%s'!",
				   sgserializable_name, buf, prefix, m_name);

		return false;
	}

	SG_REF(*param);
	return true;
}

bool
TParameter::save_ptype(CSerializableFile* file, const void* param,
					   const char* prefix)
{
	if (m_datatype.m_ptype == PT_SGOBJECT) {
		const char* sgserial_name = "";
		EPrimitiveType generic = PT_NOT_GENERIC;

		if (*(CSGObject**) param != NULL) {
			sgserial_name = (*(CSGObject**) param)->get_name();
			(*(CSGObject**) param)->is_generic(&generic);
		}

		if (!file->write_sgserializable_begin(
				&m_datatype, m_name, prefix, sgserial_name, generic))
			return false;
		if (*sgserial_name != '\0') {
			char* p = new_prefix(prefix, m_name);
			bool result = (*(CSGObject**) param)
				->save_serializable(file, p);
			delete p;
			if (!result) return false;
		}
		if (!file->write_sgserializable_end(
				&m_datatype, m_name, prefix, sgserial_name, generic))
			return false;
	} else
		if (!file->write_scalar(&m_datatype, m_name, prefix,
								param)) return false;

	return true;
}

bool
TParameter::load_ptype(CSerializableFile* file, void* param,
					   const char* prefix)
{
	if (m_datatype.m_ptype == PT_SGOBJECT) {
		string_t sgserial_name = {'\0'};
		EPrimitiveType generic = PT_NOT_GENERIC;

		if (!file->read_sgserializable_begin(
				&m_datatype, m_name, prefix, sgserial_name, &generic))
			return false;
		if (*sgserial_name != '\0') {
			if (!new_sgserial((CSGObject**) param, generic,
							  sgserial_name, prefix))
				return false;

			char* p = new_prefix(prefix, m_name);
			bool result = (*(CSGObject**) param)
				->load_serializable(file, p);
			delete p;
			if (!result) return false;
		}
		if (!file->read_sgserializable_end(
				&m_datatype, m_name, prefix, sgserial_name, generic))
			return false;
	} else
		if (!file->read_scalar(&m_datatype, m_name, prefix,
							   param)) return false;

	return true;
}

bool
TParameter::save_stype(CSerializableFile* file, const void* param,
					   const char* prefix)
{
	SGString<char>* str_ptr = (SGString<char>*) param;
	SGSparseVector<char>* spr_ptr = (SGSparseVector<char>*) param;
	index_t len_real;

	switch (m_datatype.m_stype) {
	case ST_NONE:
		if (!save_ptype(file, param, prefix)) return false;
		break;
	case ST_STRING:
		len_real = str_ptr->length;
		if (str_ptr->string == NULL && len_real != 0) {
			SG_SWARNING("Inconsistency between data structure and "
					   "len during saving string `%s%s'!  Continuing"
					   " with len=0.\n",
					   prefix, m_name);
			len_real = 0;
		}
		if (!file->write_string_begin(
				&m_datatype, m_name, prefix, len_real)) return false;
		for (index_t i=0; i<len_real; i++) {
			if (!file->write_stringentry_begin(
					&m_datatype, m_name, prefix, i)) return false;
			if (!save_ptype(file, (char*) str_ptr->string
							+ i *m_datatype.sizeof_ptype(), prefix))
				return false;
			if (!file->write_stringentry_end(
					&m_datatype, m_name, prefix, i)) return false;
		}
		if (!file->write_string_end(
				&m_datatype, m_name, prefix, len_real)) return false;
		break;
	case ST_SPARSE:
		len_real = spr_ptr->num_feat_entries;
		if (spr_ptr->features == NULL && len_real != 0) {
			SG_SWARNING("Inconsistency between data structure and "
					   "len during saving sparse `%s%s'!  Continuing"
					   " with len=0.\n",
					   prefix, m_name);
			len_real = 0;
		}
		if (!file->write_sparse_begin(
				&m_datatype, m_name, prefix, spr_ptr->vec_index,
				len_real)) return false;
		for (index_t i=0; i<len_real; i++) {
			SGSparseVectorEntry<char>* cur = (SGSparseVectorEntry<char>*)
				((char*) spr_ptr->features + i *TSGDataType
				 ::sizeof_sparseentry(m_datatype.m_ptype));
			if (!file->write_sparseentry_begin(
					&m_datatype, m_name, prefix, spr_ptr->features,
					cur->feat_index, i)) return false;
			if (!save_ptype(file, (char*) cur + TSGDataType
							::offset_sparseentry(m_datatype.m_ptype),
							prefix)) return false;
			if (!file->write_sparseentry_end(
					&m_datatype, m_name, prefix, spr_ptr->features,
					cur->feat_index, i)) return false;
		}
		if (!file->write_sparse_end(
				&m_datatype, m_name, prefix, spr_ptr->vec_index,
				len_real)) return false;
		break;
	}

	return true;
}

bool
TParameter::load_stype(CSerializableFile* file, void* param,
					   const char* prefix)
{
	SGString<char>* str_ptr = (SGString<char>*) param;
	SGSparseVector<char>* spr_ptr = (SGSparseVector<char>*) param;
	index_t len_real = 0;

	switch (m_datatype.m_stype) {
	case ST_NONE:
		if (!load_ptype(file, param, prefix)) return false;
		break;
	case ST_STRING:
		if (!file->read_string_begin(
				&m_datatype, m_name, prefix, &len_real))
			return false;
		str_ptr->string = len_real > 0
			? new char[len_real*m_datatype.sizeof_ptype()]: NULL;
		for (index_t i=0; i<len_real; i++) {
			if (!file->read_stringentry_begin(
					&m_datatype, m_name, prefix, i)) return false;
			if (!load_ptype(file, (char*) str_ptr->string
							+ i *m_datatype.sizeof_ptype(), prefix))
				return false;
			if (!file->read_stringentry_end(
					&m_datatype, m_name, prefix, i)) return false;
		}
		if (!file->read_string_end(
				&m_datatype, m_name, prefix, len_real))
			return false;
		str_ptr->length = len_real;
		break;
	case ST_SPARSE:
		if (!file->read_sparse_begin(
				&m_datatype, m_name, prefix, &spr_ptr->vec_index,
				&len_real)) return false;
		spr_ptr->features = len_real > 0? (SGSparseVectorEntry<char>*)
			new char[len_real *TSGDataType::sizeof_sparseentry(
				m_datatype.m_ptype)]: NULL;
		for (index_t i=0; i<len_real; i++) {
			SGSparseVectorEntry<char>* cur = (SGSparseVectorEntry<char>*)
				((char*) spr_ptr->features + i *TSGDataType
				 ::sizeof_sparseentry(m_datatype.m_ptype));
			if (!file->read_sparseentry_begin(
					&m_datatype, m_name, prefix, spr_ptr->features,
					&cur->feat_index, i)) return false;
			if (!load_ptype(file, (char*) cur + TSGDataType
							::offset_sparseentry(m_datatype.m_ptype),
							prefix)) return false;
			if (!file->read_sparseentry_end(
					&m_datatype, m_name, prefix, spr_ptr->features,
					&cur->feat_index, i)) return false;
		}
		if (!file->read_sparse_end(
				&m_datatype, m_name, prefix, &spr_ptr->vec_index,
				len_real)) return false;
		spr_ptr->num_feat_entries = len_real;
		break;
	}

	return true;
}

bool
TParameter::save(CSerializableFile* file, const char* prefix)
{
	const int32_t buflen=100;
	char* buf=new char[buflen];
	m_datatype.to_string(buf, buflen);
	SG_SDEBUG("Saving parameter '%s' of type '%s'\n", m_name, buf);
	delete[] buf;

	if (!file->write_type_begin(&m_datatype, m_name, prefix))
		return false;

	switch (m_datatype.m_ctype) {
	case CT_SCALAR:
		if (!save_stype(file, m_parameter, prefix)) return false;
		break;
	case CT_VECTOR: case CT_MATRIX:
		index_t len_real_y = 0, len_real_x = 0;

		len_real_y = *m_datatype.m_length_y;
		if (*(void**) m_parameter == NULL && len_real_y != 0) {
			SG_SWARNING("Inconsistency between data structure and "
					   "len_y during saving `%s%s'!  Continuing with "
					   "len_y=0.\n",
					   prefix, m_name);
			len_real_y = 0;
		}

		switch (m_datatype.m_ctype) {
		case CT_VECTOR:
			len_real_x = 1; break;
		case CT_MATRIX:
			len_real_x = *m_datatype.m_length_x;
			if (*(void**) m_parameter == NULL && len_real_x != 0) {
				SG_SWARNING("Inconsistency between data structure and "
						   "len_x during saving `%s%s'!  Continuing "
						   "with len_x=0.\n",
						   prefix, m_name);
				len_real_x = 0;
			}

			if (len_real_x *len_real_y == 0)
				len_real_x = len_real_y = 0;

			break;
		case CT_SCALAR: break;
		}

		if (!file->write_cont_begin(&m_datatype, m_name, prefix,
									len_real_y, len_real_x))
			return false;

		/* ******************************************************** */

		for (index_t x=0; x<len_real_x; x++)
			for (index_t y=0; y<len_real_y; y++) {
				if (!file->write_item_begin(
						&m_datatype, m_name, prefix, y, x))
					return false;
				if (!save_stype(
						file, (*(char**) m_parameter)
						+ (x*len_real_y + y)*m_datatype.sizeof_stype(),
						prefix)) return false;
				if (!file->write_item_end(
						&m_datatype, m_name, prefix, y, x))
					return false;
			}

		/* ******************************************************** */

		if (!file->write_cont_end(&m_datatype, m_name, prefix,
								  len_real_y, len_real_x))
			return false;

		break;
	}

	if (!file->write_type_end(&m_datatype, m_name, prefix))
		return false;

	return true;
}

bool
TParameter::load(CSerializableFile* file, const char* prefix)
{
	const int32_t buflen=100;
	char* buf=new char[buflen];
	m_datatype.to_string(buf, buflen);
	SG_SDEBUG("Loading parameter '%s' of type '%s'\n", m_name, buf);
	delete[] buf;

	if (!file->read_type_begin(&m_datatype, m_name, prefix))
		return false;

	switch (m_datatype.m_ctype)
	{
		case CT_SCALAR:
			if (!load_stype(file, m_parameter, prefix))
				return false;
			break;

		case CT_VECTOR: case CT_MATRIX:
			index_t len_read_y = 0, len_read_x = 0;

			if (!file->read_cont_begin(&m_datatype, m_name, prefix,
						&len_read_y, &len_read_x))
				return false;

			switch (m_datatype.m_ctype)
			{
				case CT_VECTOR:
					len_read_x = 1;
					new_cont(len_read_y, len_read_x);
					break;
				case CT_MATRIX:
					new_cont(len_read_y, len_read_x);
					break;
				case CT_SCALAR:
					break;
			}

			for (index_t x=0; x<len_read_x; x++)
			{
				for (index_t y=0; y<len_read_y; y++)
				{
					if (!file->read_item_begin(
								&m_datatype, m_name, prefix, y, x))
						return false;
					if (!load_stype(
								file, (*(char**) m_parameter)
								+ (x*len_read_y + y)*m_datatype.sizeof_stype(),
								prefix)) return false;
					if (!file->read_item_end(
								&m_datatype, m_name, prefix, y, x))
						return false;
				}
			}

			switch (m_datatype.m_ctype)
			{
				case CT_VECTOR:
					*m_datatype.m_length_y = len_read_y;
					break;
				case CT_MATRIX:
					*m_datatype.m_length_y = len_read_y;
					*m_datatype.m_length_x = len_read_x;
					break;
				case CT_SCALAR:
					break;
			}

			if (!file->read_cont_end(&m_datatype, m_name, prefix,
						len_read_y, len_read_x))
				return false;

			break;
	}

	if (!file->read_type_end(&m_datatype, m_name, prefix))
		return false;

	return true;
}

Parameter::Parameter(void)
{
	SG_REF(sg_io);
}

Parameter::~Parameter(void)
{
	for (int32_t i=0; i<get_num_parameters(); i++)
		delete m_params.get_element(i);

	SG_UNREF(sg_io);
}

void
Parameter::add_type(const TSGDataType* type, void* param,
					 const char* name, const char* description)
{
	if (name == NULL || *name == '\0')
		SG_SERROR("FATAL: Parameter::add_type(): `name' is empty!");

	for (int32_t i=0; i<get_num_parameters(); i++)
		if (strcmp(m_params.get_element(i)->m_name, name) == 0)
			SG_SERROR("FATAL: Parameter::add_type(): "
					 "Double parameter `%s'!", name);

	m_params.append_element(
		new TParameter(type, param, name, description)
		);
}

void
Parameter::print(const char* prefix)
{
	for (int32_t i=0; i<get_num_parameters(); i++)
		m_params.get_element(i)->print(prefix);
}

bool
Parameter::save(CSerializableFile* file, const char* prefix)
{
	for (int32_t i=0; i<get_num_parameters(); i++)
	{
		if (!m_params.get_element(i)->save(file, prefix))
			return false;
	}

	return true;
}

bool
Parameter::load(CSerializableFile* file, const char* prefix)
{
	for (int32_t i=0; i<get_num_parameters(); i++)
		if (!m_params.get_element(i)->load(file, prefix))
			return false;

	return true;
}

void Parameter::set_from_parameters(Parameter* params)
{
	/* iterate over parameters in the given list */
	for (index_t i=0; i<params->get_num_parameters(); ++i)
	{
		TParameter* current=params->get_parameter(i);
		TSGDataType current_type=current->m_datatype;

		/* search for own parameter with same name and check types if found */
		TParameter* own=NULL;
		for (index_t j=0; j<m_params.get_num_elements(); ++j)
		{
			own=m_params.get_element(j);
			if (!strcmp(own->m_name, current->m_name))
			{
				if (own->m_datatype==current_type)
				{
					own=m_params.get_element(j);
					break;
				}
				else
				{
					SG_SERROR("given parameter name %s has a different type"
							" than existing one\n", current->m_name);
				}
			}
			else
				own=NULL;
		}

		if (!own)
		{
			SG_SERROR("parameter with name %s does not exist\n",
					current->m_name);
		}

		/* check if parameter contained CSGobjects (update reference counts) */
		if (current_type.m_ptype==PT_SGOBJECT)
		{
			/* PT_SGOBJECT only occurs for ST_NONE */
			if (own->m_datatype.m_stype==ST_NONE)
			{
				if (own->m_datatype.m_ctype==CT_SCALAR)
				{
					CSGObject** to_unref=(CSGObject**) own->m_parameter;
					CSGObject** to_ref=(CSGObject**) current->m_parameter;

					if ((*to_ref)!=(*to_unref))
					{
						SG_REF((*to_ref));
						SG_UNREF((*to_unref));
					}

				}
				else
				{
					/* unref all SGObjects and reference the new ones */
					CSGObject*** to_unref=(CSGObject***) own->m_parameter;
					CSGObject*** to_ref=(CSGObject***) current->m_parameter;

					for (index_t j=0; j<own->m_datatype.get_num_elements(); ++j)
					{
						if ((*to_ref)[j]!=(*to_unref)[j])
						{
							SG_REF(((*to_ref)[j]));
							SG_UNREF(((*to_unref)[j]));
						}
					}
				}
			}
			else
				SG_SERROR("primitive type PT_SGOBJECT occurred with structure "
						"type other than ST_NONE");
		}

		/* construct pointers to the to be copied parameter data */
		void* dest;
		void* source;
		if (current_type.m_ctype==CT_SCALAR)
		{
			/* for scalar values, just copy content the pointer points to */
			dest=own->m_parameter;
			source=current->m_parameter;

			/* in case of CSGObject, pointers are not equal if CSGObjects are
			 * equal, so check. For other values, the pointers are equal and
			 * the not-copying is handled below before the memcpy call */
			if (own->m_datatype.m_ptype==PT_SGOBJECT)
			{
				if (*((CSGObject**)dest) == *((CSGObject**)source))
				{
					dest=NULL;
					source=NULL;
				}
			}
		}
		else
		{
			/* for matrices and vectors, sadly m_parameter has to be
			 * de-referenced once, because a pointer to the array address is
			 * saved, but the array address itself has to be copied.
			 * consequently, for dereferencing, a type distinction is needed */
			switch (own->m_datatype.m_ptype)
			{
			case PT_FLOAT64:
				dest=*((float64_t**) own->m_parameter);
				source=*((float64_t**) current->m_parameter);
				break;
			case PT_SGOBJECT:
				dest=*((CSGObject**) own->m_parameter);
				source=*((CSGObject**) current->m_parameter);
				break;
			default:
				SG_SNOTIMPLEMENTED;
				break;
			}
		}

		/* copy parameter data, size in memory is equal because of same type */
		if (dest!=source)
			memcpy(dest, source, own->m_datatype.get_size());
	}
}

void Parameter::add_parameters(Parameter* params)
{
	for (index_t i=0; i<params->get_num_parameters(); ++i)
	{
		TParameter* current=params->get_parameter(i);
		add_type(&(current->m_datatype), current->m_parameter, current->m_name,
				current->m_description);
	}
}

bool Parameter::contains_parameter(const char* name)
{
	for (index_t i=0; i<m_params.get_num_elements(); ++i)
	{
		if (!strcmp(name, m_params[i]->m_name))
			return true;
	}

	return false;
}
