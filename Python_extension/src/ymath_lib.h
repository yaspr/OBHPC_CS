//
#pragma once

//
#define YMATH_ALIGN 64

//Set up the ymath_lib data types 
typedef float              f32;
typedef unsigned long long u64;

//
void ymath_vadd_f32(f32 *a, f32 *b, f32 *c, u64 n);
void ymath_vadd_f32_AVX(f32 *a, f32 *b, f32 *c, u64 n);

//
f32 ymath_reduc_f32(f32 *a, u64 n);
f32 ymath_reduc_f32_AVX(f32 *a, u64 n);

//
f32 ymath_dotprod_f32(f32 *a, f32 *b, u64 n);
f32 ymath_dotprod_f32_AVX(f32 *a, f32 *b, u64 n);
