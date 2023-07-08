// g++ penguin.cpp -o penguin && ./penguin

#include <iostream>

using namespace std;

class Bird
{
    // no fly function is declared
};

class FlyingBird : public Bird
{
public:
    virtual void fly()
    {
        cout << "I can fly" << endl;
    };
};

class Penguin : public Bird
{
    // no fly function is declared
};

int main()
{
    Bird p = Penguin();
    // error: ‘class Bird’ has no member named ‘fly’
    // p.fly();
    return 0;
}