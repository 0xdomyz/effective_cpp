// g++ 21_overload_to_avoid_implicit_type_conversions.cpp -o 21_overload_to_avoid_implicit_type_conversions && ./21_overload_to_avoid_implicit_type_conversions

// The "Overload to Avoid Implicit Type Conversions" technique is a way to improve
// program safety and performance by using function overloading to avoid implicit
// type conversions. This technique is discussed in the book "More Effective C++"
// by Scott Meyers.

#include <iostream>

// Example: Overloading to Avoid Implicit Type Conversions
// -------------------------------------------------------

// Suppose we have a class that represents a complex number, and we want to define
// a function that adds two complex numbers. We could define the function as follows:

class Complex
{
public:
    Complex(double real, double imag) : real_(real), imag_(imag) {}
    double real() const { return real_; }
    double imag() const { return imag_; }

private:
    double real_;
    double imag_;
};

Complex operator+(const Complex &lhs, const Complex &rhs)
{
    return Complex(lhs.real() + rhs.real(), lhs.imag() + rhs.imag());
}

// This implementation works fine, but it allows implicit type conversions that
// can lead to unexpected behavior. For example, the following code compiles and
// runs without errors:

void test_add_complex()
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    Complex c3 = c1 + 5.0; // implicit conversion from double to Complex
    std::cout << "c3 = " << c3.real() << " + " << c3.imag() << "i" << std::endl;
}

// The result of this code is "c3 = 6 + 2i", which is not what we intended. To
// avoid this problem, we can overload the operator+ function to take a double
// as its second argument, and define it to return a Complex object that is the
// sum of the two arguments. This way, the compiler will not allow implicit type
// conversions, and we can be sure that the function behaves as expected.

Complex operator+(const Complex &lhs, double rhs)
{
    return Complex(lhs.real() + rhs, lhs.imag());
}

Complex operator+(double lhs, const Complex &rhs)
{
    return Complex(lhs + rhs.real(), rhs.imag());
}

// Now, if we try to add a Complex object and a double, the compiler will give
// an error, because there is no matching overload for the operator+ function.

void test_add_complex_overload()
{
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);
    // Complex c3 = c1 + 5.0;  // error: no matching function for call to 'operator+'
    Complex c4 = c1 + c2;
    std::cout << "c4 = " << c4.real() << " + " << c4.imag() << "i" << std::endl;
}

// By overloading the operator+ function, we have improved the safety and
// performance of our program, and made it easier to reason about the behavior
// of the function. This technique can be applied to other functions as well,
// such as constructors and conversion functions, to avoid implicit type
// conversions and improve program correctness and efficiency.