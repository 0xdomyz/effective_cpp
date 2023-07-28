// g++ 15_cost.cpp -o 15_1 -std=c++11 && ./15_1

#include <iostream>

using namespace std;

int main()
{
    try
    {
        throw 1;
    }
    catch (int e)
    {
        cout << "int exception" << endl;
    }
    catch (...)
    {
        cout << "other exception" << endl;
    }
    return 0;
}