// g++ 33_make_non_leaf_classes_abstract.cpp -o 33_make_non_leaf_classes_abstract && ./33_make_non_leaf_classes_abstract

// most animals can be treated pretty much
// the same, but two kinds of animals — lizards and chickens — require
// special handling.

// not uncommon to make assignments to objects through pointers

// One approach to the problem is to make the assignment operators virtual

// declare identical parameter types for a virtual function in every class in which it is
// declared

// mixed-type assignment

// to allow same-type assignments through pointers, but we’d like to forbid
// mixed-type assignments through those same pointers.

// type-based runtime errors. In
// particular, we need to signal an error inside operator= if we’re faced
// with a mixed-type assignment, but if the types are the same, we want
// to perform the assignment in the usual fashion.

// use a dynamic_cast, throw std::bad_cast if the cast fails
//
// implement assigbment from Animal interms of assignment from a specific animal
// throw std::bad_cast if the cast fails

// make operator=
// private in Animal. That way, lizards can be assigned to lizards and
// chickens can be assigned to chickens, but partial and mixed-type assignments are forbidden
//
// Animal is a concrete class
//
// t impossible to implement the Lizard and
// Chicken assignment operators correctly, because assignment operators in derived
// classes are responsible for calling assignment operators
// in their base classes
// could solve via declaring protected

// create a new class — AbstractAnimal, say
// — consisting of the common features of Animal, Lizard, and Chicken
// objects, and we make that class abstract. Then we have each of our
// concrete classes inherit from AbstractAnimal

// pure virtual destructors must be implemented, because they
// are called whenever a derived class destructor is invoked.

// replacing concrete base classes with abstract base classes
// forces you to explicitly recognize the existence of useful abstractions

// goal is to identify useful abstractions and to force them — and only
// them — into existence as abstract classes

// Useful abstractions, then, are
// those that are needed in more than one context. That is, they correspond to
//  classes that are useful in their own right (i.e., it is useful to
// have objects of that type) and that are also useful for purposes of one
// or more derived classes.

// save you from having to recompile packet-using applications if you add new packet types

// not to define an abstract class for
// packets, adding one later only if you find a need to inherit from the
// concrete packet class

// what are you to do if you find yourself
// wanting to create a concrete class that inherits from a concrete class
// in a library to which you have only read access?

// Derive your concrete class from the existing concrete class, and
// put up with the assignment-related problems.
// watch out for the arrayrelated pitfalls described in Item 3.

// Try to find an abstract class higher in the library hierarchy that
// does most of what you need, then inherit from that class.
// duplicate a lot of effort that has already been put into
// the implementation of the concrete class

// Implement your new class in terms of the library class you’d like
// to inherit from.
// For example, you could have an object of the library class as a data member,
// then reimplement the library class’s interface in your new class
// update class each time the lib updates
//  forgo the ability to redefine virtual functions

// Use the concrete class that’s in the
// library and modify your software so that the class suffices. Write
// non-member functions to provide the functionality you’d like to
// add to the class, but can’t

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    return 0;
}