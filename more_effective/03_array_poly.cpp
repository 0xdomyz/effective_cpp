// g++ 03_array_poly.cpp -o 03_array_poly && ./03_array_poly

// Polymorphism and
// pointer arithmetic simply don’t mix. Array operations almost always
// involve pointer arithmetic, so arrays and polymorphism don’t mix.

#include <iostream>

using namespace std;

class BST
{
public:
    int data;
};
class BalancedBST : public BST
{
private:
    int height;
};

ostream &operator<<(ostream &s, const BST &bst)
{
    s << bst.data;
    return s;
}

void printBSTArray(ostream &s,
                   const BST array[],
                   int numElements)
{
    for (int i = 0; i < numElements; ++i)
    {
        s << array[i]; // this assumes an
    }                  // operator<< is defined
}

int main()
{
    BST BSTArray[10];
    printBSTArray(cout, BSTArray, 10); // works fine

    BalancedBST bBSTArray[10];
    printBSTArray(cout, bBSTArray, 10); // works fine?
    cout << endl;
}