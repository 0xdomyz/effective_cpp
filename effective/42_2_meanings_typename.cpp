// g++ 42_2_meanings_typename.cpp -o 42_2_meanings_typename && ./42_2_meanings_typename

#include <iostream>
#include <vector>

using namespace std;

// typename is used to tell the compiler that a nested dependent type name is a type rather than a static member variable

template <typename C>             // print 2nd element in
void print2nd(const C &container) // container;
{                                 // this is not valid C++!
    if (container.size() >= 2)
    {
        typename C::const_iterator iter(container.begin()); // get iterator to 1st element
        ++iter;                                             // move iter to 2nd element
        int value = *iter;                                  // copy that element to an int
        std::cout << value;                                 // print the int
    }
}

// 2 cases where typename is not required

template <typename T>
class Base
{
public:
    class Nested
    {
    public:
        Nested(int x) {}
        Nested() {}
    };
};

template <typename T>
class Derived : public Base<T>::Nested
{       // base class list: typename not
public: // allowed
    explicit Derived(int x)
        : Base<T>::Nested(x)           // base class identifier in mem.
    {                                  // init. list: typename not allowed
        typename Base<T>::Nested temp; // use of nested dependent type
                                       // name not in a base class list or
    }                                  // as a base class identifier in a
                                       // mem. init. list: typename required
};

// typedef with typename

template <typename IterT>
void workWithIterator(IterT iter)
{
    typedef typename std::iterator_traits<IterT>::value_type value_type;
    value_type temp(*iter);
    cout << temp << endl;
}

int main()
{
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        print2nd(v);
        cout << endl;
    }

    {
        Derived<int> d(1);
    }

    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        workWithIterator(v.begin());
    }
    return 0;
}