#!/usr/bin/python3


def square_matrix_simple(matrix=[]):
    new_matrix = []
    for colo in matrix:
        result = list(map(lambda x: x**2, colo))
        new_matrix.append(result)
    return new_matrix
