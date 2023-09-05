/*!
\file
\brief main file of the program.
*/

/*! \mainpage matrix program.
*
*
*   meow
*/


#include "header.h"


/*!
 * \brief Runs a program that prints matrices.
 */
int main()
    {
    FILE* file;
    file  = fopen("MatrixOutput.txt", "w");

    printf("Choose which matrix you want to display:\n");
    printf("1 - product of square matrices\n");
    printf("2 - triangular matrix\n");

    if (ChooseMatrix() == 2)
        {
        printf("Enter the size of the triangular matrix:\n");
        int size3 = 0;
        scanf("%d", &size3);
        int* matrix_triangle = (int*) calloc((1 + size3) * size3 / 2, sizeof(int));
        InputTriangleMatrix(matrix_triangle, size3);
        PrintTriangleMatrix(matrix_triangle, size3, file);
        }
    else
        {
        printf("Enter the size of the rectangular matrix1:\n");
        int y_1 = 0, x_1 = 0;
        scanf("y1 = %d, x1 = %d", &y_1, &x_1);
        printf("Enter the size of the rectangular matrix2:\n");
        int y_2 = 0, x_2 = 0;
        scanf("y2 = %d, x2 = %d", &y_2, &x_2);

        double* matrix_rectangle = (double*) calloc(y_1 * x_1, sizeof(double));
        double* matrix_rectangle2 = (double*) calloc(y_2 * x_2, sizeof(double));
        InputRectangleMatrix(matrix_rectangle, y_1, x_1);
        InputRectangleMatrix(matrix_rectangle2, y_2, x_2);

        double* result = (double*) calloc(y_1 * x_2, sizeof(double));
        Multi_Matrix(matrix_rectangle, matrix_rectangle2, result, y_1, x_2, x_1);

        fprintf(file, "Матрица, полученная из произведения двух матриц:\n");
        PrintMatrix2((double*) result, file, y_1, x_2);
        }

    fclose(file);
    }






void InputTriangleMatrix(int matrix_triangle[], size_t size1)
    {
    assert(matrix_triangle);

    for (size_t y = 0; y < size1; y++)
        {
        for (size_t x = 0; x < y + 1; x++)
            {
            printf("Enter [%zu][%zu]:\n", y, x);
            scanf("%d", GetSetMatrix3(matrix_triangle, y, x));
            }
        }
    }


void InputRectangleMatrix(double* matrix_rectangle, size_t y_max, size_t x_max)
    {
    assert(matrix_rectangle);

    for (size_t y = 0; y < y_max; y++)
        {
        for (size_t x = 0; x < x_max; x++)
            {
            printf("Enter [%zu][%zu]:\n", y, x);
            scanf("%d", GetSetMatrixRectangle(matrix_rectangle, y, x, x_max));
            }
        }
    }


int* GetSetMatrix3(int matrix_triangle[], size_t y, size_t x)
    {
    //Sort(y, x);
    return matrix_triangle + (1 + y) * y / 2 + x;
    }


int ChooseMatrix()
    {
    int answer = 0;
    scanf("%d", &answer);
    return answer;
    }


double* GetSetMatrixRectangle(double* matrix_rectangle, size_t y, size_t x, size_t x_max)
    {
    return matrix_rectangle + y * x_max + x;
    }



