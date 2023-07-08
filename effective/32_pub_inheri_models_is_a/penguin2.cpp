// g++ penguin2.cpp -o penguin2 && ./penguin2

#include <iostream>
#include <string>

void error(const std::string &msg)
{
    std::cout << msg << std::endl;
}; // defined elsewhere

class Bird
{
    virtual void fly() = 0;
};

class Penguin : public Bird
{
public:
    virtual void fly() { error("Attempt to make a penguin fly!"); }
};

int main()
{
    Penguin p;
    p.fly();
    return 0;
}