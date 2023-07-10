// g++ 41_impli_interf_compi_poly.cpp -o 41_impli_interf_compi_poly && ./41_impli_interf_compi_poly

#include <iostream>

using namespace std;

class Widget
{
public:
    Widget(){};
    virtual ~Widget(){};
    virtual std::size_t size() const
    {
        cout << "Widget::size()" << endl;
        return 20;
    };
    virtual void normalize()
    {
        cout << "Widget::normalize()" << endl;
    };
    void swap(Widget &other)
    {
        cout << "Widget::swap()" << endl;
    }; // see Item 25
};

bool operator==(const Widget &lhs, const Widget &rhs)
{
    cout << "operator==" << endl;
    return true;
}

bool operator!=(const Widget &lhs, const Widget &rhs)
{
    return !(lhs == rhs);
}

void doProcessing(Widget &w)
{
    static Widget someNastyWidget;

    if (w.size() > 10 && w != someNastyWidget)
    {
        Widget temp(w);
        temp.normalize();
        temp.swap(w);
    }
}

// template interaces are implicit and based on valid expressions
// template polymorphism occurs during compilation and through template instantiation and function overloading

bool operator!=(const Widget &lhs, const int &rhs)
{
    return true;
}

template <typename T>
void doProcessing2(T &w)
{
    static int someNastyWidget;

    if (w.size() > 10 && w != someNastyWidget)
    {
        T temp(w);
        temp.normalize();
        temp.swap(w);
    }
}

int main()
{
    Widget w;
    doProcessing(w);
    cout << "----------------" << endl;
    doProcessing2(w);
    return 0;
}
