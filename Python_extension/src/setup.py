#
from distutils.core import setup, Extension

ymath_module = Extension("ymath", sources = [ "ymath_lib.c", "ymath_ext.c" ])

setup(name             = "ymath",
      version          = "0.1",
      author           = "yasper",
      author_email     = "yasper@pm.me",
      maintainer       = "yasper",
      maintainer_email = "yasper@pm.me",
      
      description = "ymath library", 

      ext_modules = [ ymath_module ])
