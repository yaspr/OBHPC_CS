//
#include <Python.h>

//
#include "ymath_lib.h"

//
static PyObject *ymath_error = NULL;

//
static PyObject *ymath_version(PyObject *self)
{
  return Py_BuildValue("s", "ymath library version 0.1 - yaspr, 2022");
}

//Python wrapper for the vadd_f32 C function
static PyObject *vadd_f32(PyObject *self, PyObject *args)
{
  //Views and objects for the parameter arrays
  Py_buffer view1;
  Py_buffer view2;
  Py_buffer view3;
  PyObject *obj1 = NULL;
  PyObject *obj2 = NULL;
  PyObject *obj3 = NULL;

  //Get the parameters (2 1-dimensional arrays)
  if (!PyArg_ParseTuple(args, "OOO", &obj1, &obj2, &obj3))
    return NULL;

  //Get the first array memory view
  if (PyObject_GetBuffer(obj1, &view1, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //Get the second array memory view
  if (PyObject_GetBuffer(obj2, &view2, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //Get the third array memory view
  if (PyObject_GetBuffer(obj3, &view3, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;
  
  //
  if (view1.ndim != 1 || view2.ndim != 1 || view3.ndim != 1)
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      PyBuffer_Release(&view3);
      return NULL;
    }

  //
  if (strcmp(view1.format, "f") || strcmp(view2.format, "f") || strcmp(view3.format, "f"))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array of floats.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      PyBuffer_Release(&view3);
      return NULL;     
    }

  //
  if (view1.shape[0] != view2.shape[0] || view2.shape[0] != view3.shape[0])
    {
      PyErr_SetString(PyExc_TypeError, "Expecting two 1-dimensional arrays of the same size.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      PyBuffer_Release(&view3);      
      return NULL;     
    }

  //
  ymath_vadd_f32(view1.buf, view2.buf, view3.buf, view1.shape[0]);
  
  //
  Py_RETURN_NONE;
}

//Python wrapper for the vadd_f32_AVX C function
static PyObject *vadd_f32_AVX(PyObject *self, PyObject *args)
{
  //Views and objects for the parameter arrays
  Py_buffer view1;
  Py_buffer view2;
  Py_buffer view3;
  PyObject *obj1 = NULL;
  PyObject *obj2 = NULL;
  PyObject *obj3 = NULL;

  //Get the parameters (2 1-dimensional arrays)
  if (!PyArg_ParseTuple(args, "OOO", &obj1, &obj2, &obj3))
    return NULL;

  //Get the first array memory view
  if (PyObject_GetBuffer(obj1, &view1, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //Get the second array memory view
  if (PyObject_GetBuffer(obj2, &view2, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //Get the third array memory view
  if (PyObject_GetBuffer(obj3, &view3, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;
  
  //
  if (view1.ndim != 1 || view2.ndim != 1 || view3.ndim != 1)
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      PyBuffer_Release(&view3);
      return NULL;
    }
  
  //
  if (strcmp(view1.format, "f") || strcmp(view2.format, "f") || strcmp(view3.format, "f"))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array of floats.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      PyBuffer_Release(&view3);
      return NULL;     
    }

  //
  if (view1.shape[0] != view2.shape[0] || view2.shape[0] != view3.shape[0])
    {
      PyErr_SetString(PyExc_TypeError, "Expecting two 1-dimensional arrays of the same size.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      PyBuffer_Release(&view3);      
      return NULL;     
    }

  //
  ymath_vadd_f32_AVX(view1.buf, view2.buf, view3.buf, view1.shape[0]);
  
  //
  Py_RETURN_NONE;
}

//Python wrapper for the reduc_f32 C function
static PyObject *reduc_f32(PyObject *self, PyObject *args)
{
  Py_buffer view;
  PyObject *obj = NULL;

  //Get the parameter (expected: 1-dimensional array)
  if (!PyArg_ParseTuple(args, "O", &obj))
    return NULL;

  //Get the array memory view
  if (PyObject_GetBuffer(obj, &view, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //
  if (view.ndim != 1)
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array.");
      PyBuffer_Release(&view);
      return NULL;
    }

  //
  if (strcmp(view.format, "f"))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array of floats.");
      PyBuffer_Release(&view);
      return NULL;     
    }
  
  //Return the C function's return value as a Python float object 
  return Py_BuildValue("f", ymath_reduc_f32(view.buf, view.shape[0]));
}

//Python wrapper for the reduc_f32_AVX C function
static PyObject *reduc_f32_AVX(PyObject *self, PyObject *args)
{
  Py_buffer view;
  PyObject *obj = NULL;

  //Get the parameter (expected: 1-dimensional array)
  if (!PyArg_ParseTuple(args, "O", &obj))
    return NULL;

  //Get the array memory view
  if (PyObject_GetBuffer(obj, &view, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //
  if (view.ndim != 1)
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array.");
      PyBuffer_Release(&view);
      return NULL;
    }

  //
  if (strcmp(view.format, "f"))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array of floats.");
      PyBuffer_Release(&view);
      return NULL;     
    }

  //Return the C function's return value as a Python float object 
  return Py_BuildValue("f", ymath_reduc_f32_AVX(view.buf, view.shape[0]));
}

//Python wrapper for the dotprod_f32 C function
static PyObject *dotprod_f32(PyObject *self, PyObject *args)
{
  //Views and objects for the parameter arrays
  Py_buffer view1;
  Py_buffer view2;
  PyObject *obj1 = NULL;
  PyObject *obj2 = NULL;

  //Get the parameters (2 1-dimensional arrays)
  if (!PyArg_ParseTuple(args, "OO", &obj1, &obj2))
    return NULL;

  //Get the first array memory view
  if (PyObject_GetBuffer(obj1, &view1, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //Get the second array memory view
  if (PyObject_GetBuffer(obj2, &view2, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //
  if (view1.ndim != 1 || view2.ndim != 1)
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      return NULL;
    }

  //
  if (strcmp(view1.format, "f") || strcmp(view2.format, "f"))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array of floats.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
           return NULL;     
    }

  //
  if (view1.shape[0] != view2.shape[0])
    {
      PyErr_SetString(PyExc_TypeError, "Expecting two 1-dimensional arrays of the same size.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      return NULL;     
    }

  //Return the C function's return value as a Python float object
  return Py_BuildValue("f", ymath_dotprod_f32(view1.buf, view2.buf, view1.shape[0]));
}

//Python wrapper for the dotprod_f32_AVX C function
static PyObject *dotprod_f32_AVX(PyObject *self, PyObject *args)
{
  //Views and objects for the parameter arrays
  Py_buffer view1;
  Py_buffer view2;
  PyObject *obj1 = NULL;
  PyObject *obj2 = NULL;

  //Get the parameters (2 1-dimensional arrays)
  if (!PyArg_ParseTuple(args, "OO", &obj1, &obj2))
    return NULL;

  //Get the first array memory view
  if (PyObject_GetBuffer(obj1, &view1, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //Get the second array memory view
  if (PyObject_GetBuffer(obj2, &view2, PyBUF_ANY_CONTIGUOUS | PyBUF_FORMAT) == -1)
    return NULL;

  //
  if (view1.ndim != 1 || view2.ndim != 1)
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      return NULL;
    }

  //
  if (strcmp(view1.format, "f") || strcmp(view2.format, "f"))
    {
      PyErr_SetString(PyExc_TypeError, "Expecting a 1-dimensional array of floats.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
           return NULL;     
    }

  //
  if (view1.shape[0] != view2.shape[0])
    {
      PyErr_SetString(PyExc_TypeError, "Expecting two 1-dimensional arrays of the same size.");
      PyBuffer_Release(&view1);
      PyBuffer_Release(&view2);
      return NULL;     
    }

  //Return the C function's return value as a Python float object
  return Py_BuildValue("f", ymath_dotprod_f32_AVX(view1.buf, view2.buf, view1.shape[0]));
}

//Register the methods to be made available Python side
static PyMethodDef ymath_methods[] = {

  //C versions
  { "vadd_f32"   , vadd_f32  , METH_VARARGS, "Sums the elements of two arrays into a third array."},
  { "reduc_f32"   , reduc_f32  , METH_VARARGS, "Returns the sum of all the float elements of the given array."},
  { "dotprod_f32" , dotprod_f32, METH_VARARGS, "Returns the dotproduct of all the float elements of the given arrays."},

  //Assembly optimized versions
  { "vadd_f32_optimized"   , vadd_f32_AVX  , METH_VARARGS, "Sums the elements of two arrays into a third array (optimized for x86 with AVX)."},
  { "reduc_f32_optimized"   , reduc_f32_AVX  , METH_VARARGS, "Returns the sum of all the float elements of the given array (optimized for x86 with AVX)."},
  { "dotprod_f32_optimized" , dotprod_f32_AVX, METH_VARARGS, "Returns the dotproduct of all the float elements of the given arrays (optimized for x86 with AVX)."},
  
  //Library version
  { "version", (PyCFunction)ymath_version, METH_VARARGS, "Returns the version of the library." },
  
  { NULL, NULL, 0, NULL}
};

//
static PyModuleDef ymath_module = {
  
  PyModuleDef_HEAD_INIT,
  "ymath",
  "ymath - yasper's math library",
  -1,
  ymath_methods
};

//
PyMODINIT_FUNC PyInit_ymath()
{
  PyObject *obj = PyModule_Create(&ymath_module);

  if (!obj)
    return NULL;

  ymath_error = PyErr_NewException("ymath.error", NULL, NULL);
  Py_XINCREF(ymath_error);
  
  if (PyModule_AddObject(obj, "error", ymath_error) < 0)
    {
      Py_XDECREF(ymath_error);
      Py_CLEAR(ymath_error);
      Py_DECREF(obj);
      return NULL;
    }

  return obj;
}
