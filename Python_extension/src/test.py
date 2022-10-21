import ymath
import time
import array
import numpy as np

#Number of array elements (4 Bytes x n = size in Bytes)
n = 100

#
print("Array size (B):   ", (n * 4))
print("Array size (KiB): ", (n * 4.0) / (1024.0))
print("Array size (MiB): ", (n * 4.0) / pow(2, 20))
print("\n")

#
a = np.ones(n)
b = np.ones(n)
c = np.zeros(n)

#
aa = array.array('f', a)
bb = array.array('f', b)
cc = array.array('f', c)

print("a: ", a)
print("b: ", b)
print("c: ", c)
print("\n")

print("reduc       : ", ymath.reduc_f32(aa))
print("reduc opt.  : ", ymath.reduc_f32_optimized(aa))

print("\n")

print("dotprod     : ", ymath.dotprod_f32(aa, bb))
print("dotprod opt.: ", ymath.dotprod_f32_optimized(aa, bb))

print("\n")

ymath.vadd_f32(aa, bb, cc)
print(cc, "\n")

ymath.vadd_f32_optimized(aa, bb, cc)
print(cc)
