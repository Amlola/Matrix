#include "header.h"



void PrintTriangleMatrix(const int matrix_triangle[], size_t size1, FILE* file)
    {
    assert(matrix_triangle);

    for (size_t y = 0; y < size1; y++)
        {
        for (size_t x = 0; x < y + 1; x++)
            {
            fprintf(file, "%d ", GetMatrixTriangle(matrix_triangle, y, x));

            //  y * size1 + x - ((2 * (size1 - 1) - y + 1) * y) / 2  //
            }
        fprintf(file, "\n");
        }
    }


int GetMatrixTriangle(const int matrix_triangle[], size_t y, size_t x)
    {
    return *(matrix_triangle + (1 + y) * y / 2 + x);
    }

