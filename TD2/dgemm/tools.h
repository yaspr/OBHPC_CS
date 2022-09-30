//
#pragma once

//
#include "types.h"

//
void print_f64(f64 *restrict a, u64 n);
void init_f64(f64 *restrict a, u64 n, const ascii m);
void sort_f64(f64 *restrict a, u64 n);
f64 mean_f64(f64 *restrict a, u64 n);
f64 stddev_f64(f64 *restrict a, u64 n);
