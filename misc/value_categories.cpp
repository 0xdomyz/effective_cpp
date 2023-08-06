// g++ value_categories.cpp -o value_categories && ./value_categories

// Each expression has some non-reference type, and each expression belongs to
// exactly one of the three primary value categories: prvalue, xvalue, and lvalue.
// Then there are two more mixed categories: glvalue and rvalue.

// prvalue               | rvalue
// xvalue    | glvalue   |
// lvalue    |

// prvalue
// ############################################################################
// A prvalue (“pure” rvalue) is an expression whose evaluation

// computes the value
// of an operand of a built-in operator (such prvalue has no result object), or

// initializes an object (such prvalue is said to have a result object).
// The result object may be a variable, an object created by new-expression, a
// temporary created by temporary materialization, or a member thereof.

// Note
// that non-void discarded expressions have a result object (the materialized
// temporary). Also, every class and array prvalue has a result object except
// when it is the operand of decltype;

// xvalue
// ############################################################################
// An xvalue (an “eXpiring” value) is a glvalue that denotes an object whose
// resources can be reused;

// lvalue
// ############################################################################

// An lvalue (so-called, historically, because lvalues could appear on the
// left-hand side of an assignment expression) is a glvalue that is not an
// xvalue;

// other mixed categories
// ############################################################################
// An rvalue (so-called, historically, because rvalues could appear on the
// right-hand side of an assignment expression) is a prvalue or an xvalue.

// A glvalue (“generalized” lvalue) is an expression whose evaluation determines
// the identity of an object or function;

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    {
        // prvalues expressions without result objects

        // Arithmetic expressions
        int x = 2 + 3; // 2 + 3 is a prvalue that computes the value 5, which initializes the variable x

        // Comparison expressions
        bool b = (2 < 3); // (2 < 3) is a prvalue that computes the value true, which initializes the variable b

        // Logical expressions
        bool c = (true && false); // (true && false) is a prvalue that computes the value false, which initializes the variable c

        // Bitwise expressions
        int d = (0x0F & 0xF0); // (0x0F & 0xF0) is a prvalue that computes the value 0, which initializes the variable d
    }

    {
        // prvalues that initialize objects

        // Object initialization with prvalues
        int x = 42;                // 42 is a prvalue that initializes the variable x
        double y = 3.14;           // 3.14 is a prvalue that initializes the variable y
        std::string str = "hello"; // "hello" is a prvalue that initializes the string object str

        // Object initialization with new-expression
        int *p = new int(42); // new int(42) is a prvalue that creates a new int object with value 42, which initializes the pointer p

        // Object initialization with temporary materialization
        std::string s = std::string("hello") + " world"; // std::string("hello") is a prvalue that creates a temporary string object with value "hello", which is then concatenated with " world" to create a new string object that initializes the string object s
    }

    {
        // xvalue

        int x = 42;
        int &&r1 = std::move(x);
        // std::move(x) is an xvalue that represents the value of x, which can be moved from
        int &&r2 = std::move(42);
        // std::move(42) is an xvalue that represents the value 42, which can be moved from
        std::vector<int>().push_back(42);

        struct Person
        {
            std::string name;
            int age;
        };

        // Create a temporary Person object using a prvalue
        Person p = {"Alice", 30};

        // Access the non-static data member 'name' of the temporary Person object using a member of object expression
        std::string name = std::move(p).name;
    }

    {
        // lvalue
        int x = 42;  // x is an lvalue that refers to an object that persists beyond the expression
        int *p = &x; // &x is an lvalue that refers to the address of the object x
        int &r = x;  // x is an lvalue that is bound to the reference r
        std::string s = "hello";
        // "hello" is a prvalue that creates a temporary string object,
        // but s is an lvalue that refers to the string object that persists beyond
        // the expression
    }

    {
        // another tute
        int x = 5;     // x is an lvalue
        int y = x + 3; // x + 3 is an rvalue
        int z = x;     // x is an lvalue, z is also an lvalue

        int &&r = x + 3; // x + 3 is an rvalue, r is a reference to an rvalue
        r;

        int &&r2 = move(x); // move(x) is an xvalue, r2 is a reference to an xvalue
        r2;

        // In C++, an lvalue is an expression that refers to an object that persists beyond the expression itself.
        // An rvalue is an expression that does not refer to an object that persists beyond the expression itself.

        // A prvalue is a pure rvalue, which is an expression that does not have an associated object.

        // In the code block above, `x` is an lvalue because it refers to an object that persists beyond the expression.
        // `x + 3` is an rvalue because it does not refer to an object that persists beyond the expression.

        // Understanding value categories is important in C++ because it affects how expressions can be used.
        // For example, an lvalue can be used as the target of an assignment, while an rvalue cannot.
        // Additionally, rvalues can be moved from, while lvalues cannot.
    }

    return 0;
}
