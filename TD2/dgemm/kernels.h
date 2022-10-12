//
#pragma once

//
#include "types.h"

//
void dgemm_ijk(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n);
void dgemm_ikj(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n);
void dgemm_iex(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n);
void dgemm_unroll(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n);
void dgemm_cblas(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n);
