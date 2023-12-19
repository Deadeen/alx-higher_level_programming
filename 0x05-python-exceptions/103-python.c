#include <Python.h>
#include <stdio.h>

/**
 * display_python_float - Displays information about PyFloatObject
 * @p: PyObject to be checked and printed
 */
void display_python_float(PyObject *p) {
    double value = 0;
    char *string = NULL;

    fflush(stdout);
    printf("[.] Float Object Information\n");

    if (!PyFloat_CheckExact(p)) {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    value = ((PyFloatObject *)p)->ob_fval;
    string = PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
    printf("  Value: %s\n", string);
}

/**
 * display_python_bytes - Displays information about PyBytesObject
 * @p: PyObject to be checked and printed
 */
void display_python_bytes(PyObject *p) {
    Py_ssize_t size = 0, i = 0;
    char *string = NULL;

    fflush(stdout);
    printf("[.] Bytes Object Information\n");

    if (!PyBytes_CheckExact(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    printf("  Size: %zd\n", size);
    string = (assert(PyBytes_Check(p)), (((PyBytesObject *)(p))->ob_sval));
    printf("  Trying String: %s\n", string);
    printf("  First %zd Bytes:", size < 10 ? size + 1 : 10);

    while (i < size + 1 && i < 10) {
        printf(" %02hhx", string[i]);
        i++;
    }
    printf("\n");
}

/**
 * display_python_list - Displays information about PyListObject
 * @p: PyObject to be checked and printed
 */
void display_python_list(PyObject *p) {
    Py_ssize_t size = 0;
    PyObject *item;
    int i = 0;

    fflush(stdout);
    printf("[*] Python List Information\n");

    if (PyList_CheckExact(p)) {
        size = PyList_GET_SIZE(p);
        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);

        while (i < size) {
            item = PyList_GET_ITEM(p, i);
            printf("Element %d: %s\n", i, item->ob_type->tp_name);

            if (PyBytes_Check(item)) {
                display_python_bytes(item);
            } else if (PyFloat_Check(item)) {
                display_python_float(item);
            }
            i++;
        }
    } else {
        printf("  [ERROR] Invalid List Object\n");
    }
}
