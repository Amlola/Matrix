/*!
\file
\brief Program header file.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>



/*!
 * \brief Matrix output.
 *
 * The function outputs the matrix to the file test3.txt
 */
void PrintMatrix2(double* matrix, FILE* file, size_t y_1, size_t x_1);


/*!
 * \brief Matrix product.
 *
 * The function takes two matrices and assigns the value of their product to the third.
 */
void Multi_Matrix(double* matrix, double* matrix2, double* multi_matrix, size_t y_1, size_t x_2, size_t x_1);


/*!
 * \brief Filling one cell.
 *
 * The function takes the coordinates of a cell in the output matrix and assigns a value to it.
 * \param[in] y_pos, x_pos - output matrix cell coordinates;
 */
double One_operation(int y_pos, int x_pos, double* matrix, double* matrix2, size_t x_1, size_t x_2);


/*!
 * \brief Triangle matrix output.
 *
 * The function outputs the triangle matrix to the file test3.txt
 * \param[in] size1 - number of rows in a triangular matrix.
 */
void PrintTriangleMatrix(const int matrix_triangle[], size_t size1, FILE* file);


/*!
 * \brief Triangular matrix filling.
 *
 * The function outputs the triangle matrix to the file test3.txt
 * \param[in] y, x - triangular matrix output coordinates.
 */
int GetMatrixTriangle(const int matrix_triangle[], size_t y, size_t x);


/*!
 * \brief Passing an address to fscanf.
 *
 * The function returns the address of the cell.
 * \param[in] y, x - triangular matrix input coordinates.
 */
int* GetSetMatrix3(int matrix_triangle[], size_t y, size_t x);


/*!
 * \brief Triangle matrix input.
 *
 * The function inputs the triangle matrix in the file InputFile.txt
 * \param[in] size1 - number of rows in a triangular matrix.
 */
void InputTriangleMatrix(int matrix_triangle[], size_t size1);


int ChooseMatrix();


//void Sort(size_t y, size_t x);


void InputRectangleMatrix(double* matrix_rectangle, size_t y_max, size_t x_max);


double* GetSetMatrixRectangle(double* matrix_rectangle, size_t y, size_t x, size_t x_max);

