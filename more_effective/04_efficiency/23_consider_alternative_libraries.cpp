// g++ 23_consider_alternative_libraries.cpp -o 23_consider_alternative_libraries && ./23_consider_alternative_libraries

// The "Consider Alternative Libraries" technique is a way to improve program
// quality and efficiency by exploring alternative libraries that provide similar
// functionality to the standard libraries. This technique is discussed in the book
// "Effective C++" by Scott Meyers.

#include <iostream>
#include <vector>
#include <boost/numeric/ublas/matrix.hpp>

// Example: Consider Alternative Libraries
// ---------------------------------------

// Suppose we have a program that uses the standard library vector class to store
// a large number of elements, and we need to perform matrix operations on the data.
// We could define a matrix class that uses the vector class to store the data, and
// define the matrix operations as member functions of the matrix class.

class Matrix
{
public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols), data_(rows * cols) {}
    double &operator()(int i, int j) { return data_[i * cols_ + j]; }
    const double &operator()(int i, int j) const { return data_[i * cols_ + j]; }
    Matrix operator*(const Matrix &rhs) const
    {
        Matrix result(rows_, rhs.cols_);
        for (int i = 0; i < rows_; ++i)
        {
            for (int j = 0; j < rhs.cols_; ++j)
            {
                double sum = 0.0;
                for (int k = 0; k < cols_; ++k)
                {
                    sum += (*this)(i, k) * rhs(k, j);
                }
                result(i, j) = sum;
            }
        }
        return result;
    }

private:
    int rows_;
    int cols_;
    std::vector<double> data_;
};

// This implementation works fine, but it can be inefficient if the matrix is large,
// because the vector class stores the data in a contiguous block of memory, which
// can lead to cache misses and slow performance.

// To improve the performance of our program, we can consider using an alternative
// library that provides optimized matrix operations. For example, the Boost uBLAS
// library provides a matrix class that uses expression templates to optimize matrix
// operations, and can be much faster than the standard library vector class.

void test_multiply_matrix()
{
    boost::numeric::ublas::matrix<double> m1(2, 2);
    m1(0, 0) = 1.0;
    m1(0, 1) = 2.0;
    m1(1, 0) = 3.0;
    m1(1, 1) = 4.0;
    boost::numeric::ublas::matrix<double> m2(2, 2);
    m2(0, 0) = 5.0;
    m2(0, 1) = 6.0;
    m2(1, 0) = 7.0;
    m2(1, 1) = 8.0;
    boost::numeric::ublas::matrix<double> result = boost::numeric::ublas::prod(m1, m2);
    std::cout << "result(0, 0) = " << result(0, 0) << std::endl;
    std::cout << "result(0, 1) = " << result(0, 1) << std::endl;
    std::cout << "result(1, 0) = " << result(1, 0) << std::endl;
    std::cout << "result(1, 1) = " << result(1, 1) << std::endl;
}

// By using the Boost uBLAS library instead of the standard library vector class,
// we have improved the performance and efficiency of our program, and made it
// easier to reason about the behavior of the matrix operations. This technique
// can be applied to other parts of the program as well, such as string processing,
// file I/O, and networking, to improve program quality and efficiency.