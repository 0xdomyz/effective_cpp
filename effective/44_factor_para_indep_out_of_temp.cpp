// g++ 44_factor_para_indep_out_of_temp.cpp -o 44_factor_para_indep_out_of_temp && ./44_factor_para_indep_out_of_temp

#include <iostream>

template <typename T> // size-independent base class for
class SquareMatrixBase
{ // square matrices
protected:
    void invert(std::size_t matrixSize)
    {
        std::cout << "SquareMatrixBase::invert" << std::endl;
    }; // invert matrix of the given size
};

template <typename T, std::size_t n>
class SquareMatrix : private SquareMatrixBase<T>
{
private:
    using SquareMatrixBase<T>::invert; // make base class version of invert
    // visible in this class; see Items 33
    // and 43
public:
    void invert() { invert(n); } // make inline call to base class
};                               // version of invert

int main()
{
    SquareMatrix<double, 5> sm1;
    sm1.invert(); // call SquareMatrix<double, 5>::invert
    SquareMatrix<double, 10> sm2;
    sm2.invert(); // call SquareMatrix<double, 10>::invert
}