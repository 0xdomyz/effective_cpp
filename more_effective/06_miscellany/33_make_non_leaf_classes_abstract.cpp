// g++ 33_make_non_leaf_classes_abstract.cpp -o 33_make_non_leaf_classes_abstract && ./33_make_non_leaf_classes_abstract

// Summary: Make Non-Leaf Classes Abstract
// ----------------------------------------

// The chapter "Make Non-Leaf Classes Abstract" from the book "More Effective C++"
// discusses the use of abstract classes to enforce a class hierarchy and prevent
// instantiation of non-leaf classes. The chapter covers the following topics:

// - The motivation for using abstract classes to enforce a class hierarchy
// - The use of pure virtual functions to make a class abstract
// - The use of virtual destructors in abstract classes
// - The use of protected constructors to prevent instantiation of non-leaf classes
// - The use of the Factory Method pattern to create objects of non-leaf classes

// The chapter provides guidelines for designing and implementing abstract classes,
// and explains the advantages and disadvantages of using abstract classes. The
// chapter also provides examples of how to use abstract classes, and discusses
// common pitfalls and best practices for abstract class usage.

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    return 0;
}