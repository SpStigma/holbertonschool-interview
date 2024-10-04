#!/usr/bin/python3
'''This is a module'''


def rotate_2d_matrix(matrix):
    """Fonction to rotate the module"""
    #Transpose the matrix by swapping rows and columns
    n = len(matrix)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    

    for i in range(n):
        matrix[i].reverse()
