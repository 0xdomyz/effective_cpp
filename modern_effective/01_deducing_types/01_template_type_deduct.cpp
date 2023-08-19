// g++ 01_template_type_deduct.cpp -o 01_template_type_deduct && ./01_template_type_deduct

// summary:
//  During template type deduction, arguments that are references are treated as
// non-references, i.e., their reference-ness is ignored.
// • When deducing types for universal reference parameters, lvalue arguments get
// special treatment.
// • When deducing types for by-value parameters, const and/or volatile argu‐
// ments are treated as non-const and non-volatile.
// • During template type deduction, arguments that are array or function names
// decay to pointers, unless they’re used to initialize references.

//  we can think of a function tem‐
// plate as looking like this:
// template<typename T>
// void f(ParamType param);
// A call can look like this:
// f(expr); // call f with some expression

// During compilation, compilers use expr to deduce two types: one for T and one for
// ParamType. These types are frequently different, because ParamType often contains
// adornments,
namespace example1
{
    template <typename T>
    void f(const T &param){}; // ParamType is const T&
}

void f1()
{
    int x = 0;
    example1::f(x); // call f with an int
}

// The type deduced for T is dependent not just on the type of expr, but also on the
// form of ParamType. There are three cases

// • ParamType is a pointer or reference type, but not a universal reference.
// ###########################################################################
//
// 1. If expr’s type is a reference, ignore the reference part.
// 2. Then pattern-match expr’s type against ParamType to determine T.
namespace case1
{
    template <typename T>
    void f(T &param){}; // param is a reference

}

void f_1()
{
    using namespace case1;
    int x = 27;        // x is an int
    const int cx = x;  // cx is a const int
    const int &rx = x; // rx is a reference to x as a const int
    // the deduced types for param and T in various calls are as follows:
    f(x);  // T is int, param's type is int&
    f(cx); // T is const int,
           // param's type is const int&
    f(rx); // T is const int,
           // param's type is const int&
}

// If we change the type of f’s parameter from T& to const T&, things change a little, but
// not in any really surprising ways

// If param were a pointer (or a pointer to const) instead of a reference, things would
// work essentially the same way

// • ParamType is a universal reference.
// ###########################################################################

// If expr is an lvalue, both T and ParamType are deduced to be lvalue references.
// If expr is an rvalue, the “normal” (i.e., Case 1) rules apply.

namespace case2
{
    template <typename T>
    void f(T &&param){}; // param is a universal reference
}

void f_2()
{
    using namespace case2;
    int x = 27;        // as before
    const int cx = x;  // as before
    const int &rx = x; // as before
    f(x);              // x is lvalue, so T is int&,
                       // param's type is also int&
    f(cx);             // cx is lvalue, so T is const int&,
                       // param's type is also const int&
    f(rx);             // rx is lvalue, so T is const int&,
                       // param's type is also const int&
    f(27);             // 27 is rvalue, so T is int,
                       // param's type is therefore int&&
}

// • ParamType is neither a pointer nor a reference.
// ###########################################################################

namespace case3
{
    template <typename T>
    void f(T param){}; // param is now passed by value
}

// That means that param will be a copy of whatever is passed in—a completely new
// object.

void f_3()
{
    using namespace case3;
    int x = 27;        // as before
    const int cx = x;  // as before
    const int &rx = x; // as before
    f(x);              // T's and param's types are both int
    f(cx);             // T's and param's types are again both int
    f(rx);             // T's and param's types are still both int
}

#include <array>
namespace niche_case
{

    // return size of an array as a compile-time constant. (The
    // array parameter has no name, because we care only about
    // the number of elements it contains.)
    template <typename T, std::size_t N>               // see info
    constexpr std::size_t arraySize(T (&)[N]) noexcept // below on
    {                                                  // constexpr
        return N;                                      // and
    }                                                  // noexcept
    template <typename T>
    void f1(T param){}; // in f1, param passed by value

    template <typename T>
    void f2(T &param){}; // in f2, param passed by ref

    void someFunc(int, double){}; // someFunc is a function;
                                  // type is void(int, double)
}

void f_4()
{
    using namespace niche_case;
    int keyVals[] = {1, 3, 7, 9, 11, 22, 35}; // keyVals has
                                              // 7 elements
    int mappedVals[arraySize(keyVals)];       // so does
                                              // mappedVals

    std::array<int, arraySize(keyVals)> mappedVals2; // mappedVals'
    // size is 7

    f1(someFunc); // param deduced as ptr-to-func;
                  // type is void (*)(int, double)
    f2(someFunc); // param deduced as ref-to-func;
                  // type is void (&)(int, double)
}

int main()
{
    return 0;
}
