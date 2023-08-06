// g++ 22_consider_using_opequal_instead_of_stand_alone_op.cpp -o 22_consider_using_opequal_instead_of_stand_alone_op && ./22_consider_using_opequal_instead_of_stand_alone_op

// The "Using op= Instead of Stand-Alone op" technique is a way to improve program
// safety and performance by using the compound assignment operator (op=) instead
// of the stand-alone operator (op) to modify an object. This technique is discussed
// in the book "Effective C++" by Scott Meyers.

#include <iostream>

// Example: Using op= Instead of Stand-Alone op
// --------------------------------------------

// Suppose we have a class that represents a matrix, and we want to define a
// function that multiplies a matrix by a scalar. We could define the function
// as follows:

class Matrix
{
    friend Matrix operator*(Matrix m, double scalar);
    friend Matrix &operator*=(Matrix &m, double scalar);

public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(new double[rows * cols]) {}
    ~Matrix() { delete[] data_; }
    double &operator()(int i, int j) { return data_[i * cols_ + j]; }
    const double &operator()(int i, int j) const { return data_[i * cols_ + j]; }

private:
    int rows_;
    int cols_;
    double *data_;
};

// Matrix operator*(const Matrix &m, double scalar)
// {
//     Matrix result(m.rows_, m.cols_);
//     for (int i = 0; i < m.rows_; ++i)
//     {
//         for (int j = 0; j < m.cols_; ++j)
//         {
//             result(i, j) = m(i, j) * scalar;
//         }
//     }
//     return result;
// }

// This implementation works fine, but it creates a temporary object that is
// then copied to the result object. This can be inefficient if the matrix is
// large, and can also lead to unexpected behavior if the copy constructor or
// assignment operator is not defined correctly.

// To avoid these problems, we can define the operator*= function to modify
// the matrix in place, instead of creating a temporary object. We can then
// define the operator* function to call the operator*= function and return
// the modified matrix.

Matrix &operator*=(Matrix &m, double scalar)
{
    for (int i = 0; i < m.rows_; ++i)
    {
        for (int j = 0; j < m.cols_; ++j)
        {
            m(i, j) *= scalar;
        }
    }
    return m;
}

Matrix operator*(Matrix m, double scalar)
{
    m *= scalar;
    return m;
}

// Now, if we multiply a matrix by a scalar, the operator* function will call
// the operator*= function to modify the matrix in place, and then return the
// modified matrix. This way, we avoid creating a temporary object, and improve
// the performance and safety of our program.

void test_multiply_matrix()
{
    Matrix m(2, 2);
    m(0, 0) = 1.0;
    m(0, 1) = 2.0;
    m(1, 0) = 3.0;
    m(1, 1) = 4.0;
    Matrix result = m * 2.0;
    std::cout << "result(0, 0) = " << result(0, 0) << std::endl;
    std::cout << "result(0, 1) = " << result(0, 1) << std::endl;
    std::cout << "result(1, 0) = " << result(1, 0) << std::endl;
    std::cout << "result(1, 1) = " << result(1, 1) << std::endl;
}

// By using the operator*= function instead of the stand-alone operator* function,
// we have improved the performance and safety of our program, and made it easier
// to reason about the behavior of the function. This technique can be applied to
// other functions as well, such as addition, subtraction, and division, to avoid
// creating temporary objects and improve program efficiency and correctness.
