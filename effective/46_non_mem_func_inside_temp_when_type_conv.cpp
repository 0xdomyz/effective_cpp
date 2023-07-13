// g++ 46_non_mem_func_inside_temp_when_type_conv.cpp -o 46_non_mem_func_inside_temp_when_type_conv && ./46_non_mem_func_inside_temp_when_type_conv

#include <iostream>

template <typename T>
class Rational
{
    friend const Rational<T> operator*(const Rational<T> &lhs,
                                       const Rational<T> &rhs)
    {
        return Rational<T>(lhs.numerator() * rhs.numerator(),
                           lhs.denominator() * rhs.denominator());
    }

    friend const Rational<T> operator+(const Rational<T> &lhs,
                                       const Rational<T> &rhs)
    {
        return doAddition(lhs, rhs);
    }

public:
    Rational(const T &numerator = 0,                                     // see Item 20 for why params
             const T &denominator = 1) : n(numerator), d(denominator){}; // are now passed by reference
    const T numerator() const
    {
        return n;
    }; // see Item 28 for why return
    const T denominator() const
    {
        return d;
    }; // values are still passed by value,
       // Item 3 for why they’re const
private:
    T n, d;
};

template <typename T>
const Rational<T> operator*(const Rational<T> &lhs,
                            const Rational<T> &rhs)
{
    return Rational<T>(lhs.numerator() * rhs.numerator(),
                       lhs.denominator() * rhs.denominator());
}

template <typename T>
const Rational<T> doAddition(const Rational<T> &lhs,
                             const Rational<T> &rhs)
{
    return Rational<T>(lhs.numerator() * rhs.denominator() +
                           rhs.numerator() * lhs.denominator(),
                       lhs.denominator() * rhs.denominator());
}

int main()
{
    Rational<int> oneHalf(1, 2);
    Rational<int> result = oneHalf * 2; // 2 is implicitly converted to Rational<int>
    std::cout << "shoud be 2/2: " << result.numerator() << "/" << result.denominator() << std::endl;

    Rational<int> result2 = 2 + oneHalf; // 2 is implicitly converted to Rational<int>
    std::cout << "shoud be 5/2: " << result2.numerator() << "/" << result2.denominator() << std::endl;

    return 0;
}
