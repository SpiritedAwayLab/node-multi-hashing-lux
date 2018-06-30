// Phi2 module

#include <Python.h>

#include "phi2.h"

static PyObject *phi2_hash_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    phi2_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    phi2_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef Phi2Methods[] = {
    { "getPoWHash", phi2_hash_getpowhash, METH_VARARGS, "Returns the proof of work hash using phi2 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef Phi2Module = {
    PyModuleDef_HEAD_INIT,
    "phi2_hash",
    "...",
    -1,
    Phi2Methods
};

PyMODINIT_FUNC PyInit_phi2_hash(void) {
    return PyModule_Create(&Phi2Module);
}

#else

PyMODINIT_FUNC initphi2_hash(void) {
    (void) Py_InitModule("phi2_hash", Phi2Methods);
}
#endif
