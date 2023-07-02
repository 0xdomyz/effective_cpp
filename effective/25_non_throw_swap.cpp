// g++ 25_non_throw_swap.cpp -o non_throw_swap -std=c++14 && ./non_throw_swap

// namespace std
// {
//     template <typename T> // typical implementation of std::swap;
//     void swap(T &a, T &b) // swaps a’s and b’s values
//     {
//         T temp(a);
//         a = b;
//         b = temp;
//     }
// }

#include <iostream>
#include <vector>

using namespace std;

class WidgetImpl
{       // class for Widget data;
public: // details are unimportant
private:
    int a, b, c;           // possibly lots of data —
    std::vector<double> v; // expensive to copy!
};

class Widget
{ // class using the pimpl idiom
public:
    Widget() = default;
    Widget(const Widget &rhs) = default; // default copy ctor
    ~Widget() = default;
    Widget &operator=(const Widget &rhs) // to copy a Widget, copy its
    {                                    // WidgetImpl object. For ... // details on implementing
        *pImpl = *(rhs.pImpl);           // operator= in general, ... // see Items 10, 11, and 12. }
        return *this;
    }
    void swap(Widget &other)
    {
        using std::swap; // the need for this declaration
        // is explained later in this Item
        swap(pImpl, other.pImpl); // to swap Widgets, swap their
    }                             // pImpl pointer

private:
    WidgetImpl *pImpl; // ptr to object with this
};

// namespace std
// {
//     template <>                  // this is a specialized version
//     void swap<Widget>(Widget &a, // of std::swap for when T is
//                       Widget &b) // Widget
//     {
//         swap(a.pImpl, b.pImpl); // to swap Widgets, swap their
//     }                           // pImpl pointers; this won’t compile
// }

namespace std
{
    template <>                  // revised specialization of
    void swap<Widget>(Widget &a, // std::swap
                      Widget &b)
    {
        a.swap(b); // to swap Widgets, call their
    }              // swap member function
}

namespace WidgetStuff
{
    // templatized WidgetImpl, etc.
    template <typename T> // as before, including the swap
    class Widget
    {
    public:
        Widget() = default;
        Widget(const Widget &rhs) = default; // default copy ctor
        ~Widget() = default;
        Widget &operator=(const Widget &rhs) // to copy a Widget, copy its
        {                                    // WidgetImpl object. For ... // details on implementing
            *pImpl = *(rhs.pImpl);           // operator= in general, ... // see Items 10, 11, and 12. }
            return *this;
        }
        void swap(Widget &other)
        {
            using std::swap; // the need for this declaration
            // is explained later in this Item
            swap(pImpl, other.pImpl); // to swap Widgets, swap their
        }                             // pImpl pointer

    private:
        T *pImpl; // ptr to object with this
    };            // member function

    template <typename T>   // non-member swap function;
    void swap(Widget<T> &a, // not part of the std namespace
              Widget<T> &b)
    {
        a.swap(b);
    }
}

int main()
{
    {
        Widget w1, w2;
        swap(w1, w2); // calls std::swap
    }

    {
        Widget w1, w2;
        using std::swap;
        swap(w1, w2); // calls std::swap
    }

    {
        WidgetStuff::Widget<int> w1, w2;
        swap(w1, w2); // calls WidgetStuff::swap
    }
}
