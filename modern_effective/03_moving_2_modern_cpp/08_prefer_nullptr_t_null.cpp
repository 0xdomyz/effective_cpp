// g++ 08_prefer_nullptr_t_null.cpp -o 08_prefer_nullptr_t_null && ./08_prefer_nullptr_t_null

// Prefer nullptr to 0 and NULL.

// Avoid overloading on integral and pointer types.

#include <iostream>

using namespace std;

namespace example_1
{
    void f(int)
    {
        cout << "f(int)" << endl;
    }; // three overloads of f
    void f(bool)
    {
        cout << "f(bool)" << endl;
    };
    void f(void *)
    { // f(void*) is the least-preferred overload
        cout << "f(void *)" << endl;
    };
    void test()
    {
        f(0); // calls f(int), not f(void*)
        // f(NULL); // might not compile, but typically calls
        // f(int). Never calls f(void*)
        f(nullptr); // calls f(void*)
    }
}

int main()
{

    {
        example_1::test();
    }
}