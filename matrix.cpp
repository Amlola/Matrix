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
        int size3 = 0;
        Input_size_Triangularmatrix(&size3);


        int* matrix_triangle = (int*) calloc((1 + size3) * size3 / 2, sizeof(int));
        InputTriangleMatrix(matrix_triangle, size3);


        PrintTriangleMatrix(matrix_triangle, size3, file);
        }
    else
        {
        int y_1 = 0, x_1 = 0;
        Input_size_Rectanglematrix(&y_1, &x_1);


        double* matrix_rectangle = (double*) calloc(y_1 * x_1, sizeof(double));
        InputRectangleMatrix(matrix_rectangle, y_1, x_1);


        int y_2 = 0, x_2 = 0;
        Input_size_Rectanglematrix2(&y_2, &x_2);


        Check_multi(x_1, x_2, y_2);


        double* matrix_rectangle2 = (double*) calloc(y_2 * x_2, sizeof(double));
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
            scanf("%lf", GetSetMatrixRectangle(matrix_rectangle, y, x, x_max));
            }
        }
    }


int* GetSetMatrix3(int matrix_triangle[], size_t y, size_t x)
    {
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


void Check_multi(int x_1, int x_2, int y_2)
    {
    if (x_1 != y_2)
        {
        printf("Matrices cannot be multiplied\n");
        printf("The number of columns of one matrix must equal the number of rows of another (x2 == y1)\n");
        printf("Try again\n");
        exit(0);
        }
    }


void Input_size_Rectanglematrix(int* y_1, int* x_1)
    {
    printf("Enter the size of the rectangular matrix1: y1 = , x1 = \n");
    scanf("%d %d", y_1, x_1);
    }


void Input_size_Rectanglematrix2(int* y_2, int* x_2)
    {
    printf("Enter the size of the rectangular matrix2: y2 = , x2 = \n");
    scanf("%d %d", y_2, x_2);
    }


void Input_size_Triangularmatrix(int* size3)
    {
    printf("Enter the size of the triangular matrix:\n");
    scanf("%d", size3);
    }


