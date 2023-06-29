// g++ 17_store_newd_obj_in_standalone.cpp -o 17_store_newd_obj_in_standalone && ./17_store_newd_obj_in_standalone

#include <memory>
#include <iostream>

using namespace std;

struct Widget
{
    Widget() : i(0) {}
    explicit Widget(int i_) : i(i_) {}
    int i;
};

int priority()
{
    throw std::runtime_error("priority");
    return 1;
}

void processWidget(std::shared_ptr<Widget> pw, int priority)
{
    std::cout << "processWidget" << std::endl;
}

int main()
{
    std::shared_ptr<int> p(new int(42));
    std::cout << *p << std::endl;

    // processWidget(new Widget, priority());

    // possible memory leak
    // processWidget(std::shared_ptr<Widget>(new Widget), priority());

    std::shared_ptr<Widget> pw(new Widget); // store newed object
    // in a smart pointer in a
    // standalone statement
    processWidget(pw, priority()); // this call won’t leak
}
