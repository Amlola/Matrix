#include "header.h"


void PrintMatrix2(double* matrix, FILE* file, size_t y_1, size_t x_1)
    {
    assert(matrix);

    for (size_t y = 0; y < y_1; y++)
        {
        for (size_t x = 0; x < x_1; x++)
            {
            fprintf(file, "matrix[%d][%d]: %lg;  ", y, x, *(matrix + y * x_1 + x));
            }
        fprintf(file, "\n");
        }
    }


void Multi_Matrix(double* matrix, double* matrix2, double* multi_matrix, size_t y_1, size_t x_2, size_t x_1)
    {
    assert(matrix && matrix2);

    for (size_t y = 0; y < y_1; y++)
        {
        for (size_t x = 0; x < x_2; x++)
            {
            *(multi_matrix + y * x_2 + x) = One_operation(y, x, matrix, matrix2, x_1, x_2);
            }
        }
    }


double One_operation(int y_pos, int x_pos, double* matrix, double* matrix2, size_t x_1, size_t x_2)
    {
    assert(matrix && matrix2);

    double sol = 0;

    for (int i = 0; i < x_1; i++)
        {

        sol += *(matrix + y_pos * x_1 + i) * *(matrix2 + i * x_2 + x_pos);
        }
    return sol;
    }


/* void PrintMatrix(const double matrix[][5])
    {
    for (int y = 0; y < 5; y++)
        {
        for (int x = 0; x < 5; x++)
            {
            printf("matrix[%d][%d]: %lg;  ", y, x, matrix[y][x]);
            }
        printf("\n");
        }
    }*/
