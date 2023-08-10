// g++ make_shared.cpp -o make_shared && ./make_shared

#include <memory>
#include <iostream>

class MyClass
{
public:
    MyClass(int value) : m_value(value) {}
    void print() const
    {
        std::cout << "MyClass(" << m_value << ")" << std::endl;
    }

private:
    int m_value;
};

int main()
{
    // If the control block is not properly deallocated, it can lead to memory leaks.
    // This is because the control block contains the reference count and other information
    // needed to manage the shared pointer, and if it is not properly deallocated, the
    // reference count may not be decremented correctly, leading to memory leaks and other
    //  memory-related issues.

    // Using `std::make_shared` can help avoid these issues by ensuring that both the
    // control block and the managed object are deallocated together when the shared pointer
    //  is no longer needed. This can help prevent memory leaks and other memory-related
    //  issues, and can also improve performance and reduce memory fragmentation by avoiding
    //   separate memory allocation for the control block and the managed object.

    // create a shared pointer to a new MyClass object without using std::make_shared
    // std::shared_ptr<MyClass> ptr(new MyClass(42));

    // create a shared pointer to a new MyClass object using std::make_shared
    std::shared_ptr<MyClass> ptr = std::make_shared<MyClass>(42);

    // manually delete the managed object, but not the control block
    // delete ptr.get();

    // use the shared pointer to call a member function
    // ptr->print(); // undefined behavior

    return 0;
}