// g++ -std=c++17 const.cpp -o const && ./const

#include <iostream>
#include <memory>

using namespace std;

class CD
{
};

int main()
{
    {
        // 4 combinations of pointers and objects
        CD *p1 = new CD;         // pointer to non-const object
        const CD *p2 = p1;       // pointer to const object
        CD *const p3 = p1;       // const pointer to non-const object
        const CD *const p4 = p1; // const pointer to const object

        delete p1;
    }

    {
        // 4 combinations of smart pointers and objects
        shared_ptr<CD> p1(new CD);          // pointer to non-const object
        shared_ptr<const CD> p2 = p1;       // pointer to const object
        const shared_ptr<CD> p3 = p1;       // const pointer to non-const object
        const shared_ptr<const CD> p4 = p1; // const pointer to const object

        // conversion could be achieved by using member templates
    }

    //     Conversions involving const are a one-way street: it’s safe to go from
    // non-const to const, but it’s not safe to go from const to non-const.

    // similiar to public inheritance
    // so can have smart pointer to non-const object inherit from smart pointer to const object
    // can have protected union of dumb pointers to non-const and const objects
}