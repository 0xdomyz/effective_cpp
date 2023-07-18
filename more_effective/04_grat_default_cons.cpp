// g++ 04_grat_default_cons.cpp -o 04_grat_default_cons.out && ./04_grat_default_cons.out

// defualt cons makes sense for some classes, but not for others
// Objects that act like numbers may reasonably be initialized to zero
// an object representing an entry in an address book need name

// if a class lacks a default constructor,
// there are restrictions on how you can use that class:
// 1. you can't create an array of objects of that class, there are workarounds
// 2. default constructor is required for some containers

// forcing a class to have a default constructor has drawbacks

#include <iostream>
#include <vector>
#include <array>

using namespace std;

class EquipmentPiece
{
public:
    EquipmentPiece(int IDNumber) : IDNumber(IDNumber) {}

private:
    int IDNumber;
};

class EquipmentPiece2
{
public:
    EquipmentPiece2(int IDNumber = UNSPECIFIED)
        : IDNumber(IDNumber)
    {
    }

private:
    static const int UNSPECIFIED; // magic ID number value
    int IDNumber;
    // meaning no ID was
}; // specified

const int EquipmentPiece2::UNSPECIFIED = -1;

int main()
{

    // restriction: creation of arrays
    // EquipmentPiece bestPieces[10]; // error! No way to call
    // EquipmentPiece ctors
    // EquipmentPiece *bestPieces =
    //     new EquipmentPiece[10]; // error! same problem

    // ways to get around

    {                 // non heap
        int ID1, ID2; // variables to hold
        // equipment ID numbers
        EquipmentPiece bestPieces[] = {
            // fine, ctor arguments
            EquipmentPiece(ID1), // are provided
            EquipmentPiece(ID2),
        };
    }

    {
        // array of p
        typedef EquipmentPiece *PEP; // a PEP is a pointer to
        // an EquipmentPiece
        PEP bestPieces[10]; // fine, no ctors called
        for (int i = 0; i < 10; ++i)
            bestPieces[i] = new EquipmentPiece(1);
        // dtor
        for (int i = 0; i < 10; ++i)
            delete bestPieces[i];

        PEP *bestPieces2 = new PEP[10]; // also fine
    }

    {
        // alloc raw mem then palcement new
        // allocate enough raw memory for an array of 10
        // EquipmentPiece objects; see Item 8 for details on
        // the operator new[] function
        void *rawMemory =
        operator new[](10 * sizeof(EquipmentPiece));
        // make bestPieces point to it so it can be treated as an
        // EquipmentPiece array
        EquipmentPiece *bestPieces =
            static_cast<EquipmentPiece *>(rawMemory);
        // construct the EquipmentPiece objects in the memory
        // using "placement new" (see Item 8)
        // for (int i = 0; i < 10; ++i)
        //     new (bestPieces + i) EquipmentPiece(1);
        // to-do: placement new

        // destruct the objects in bestPieces in the inverse
        // order in which they were constructed
        for (int i = 9; i >= 0; --i)
            bestPieces[i].~EquipmentPiece();
        // deallocate the raw memory
        operator delete[](rawMemory);
    }

    // prob: ineligible for containers
    {
        // Array<EquipmentPiece> bestPieces(10);
        // vector<EquipmentPiece> bestPieces(10);
        // error! no default ctor

        vector<EquipmentPiece> bestPieces;
        // Array<EquipmentPiece> bestPieces2;
    }

    // opinion:
    // all classes should have default ctors
    // member functions has to check if the object is in a valid state
    // cons: default ctor may be expensive
    // cons: throw exception or terminate do not improve the situation
    {
        EquipmentPiece2 bestPieces[10]; // fine, default ctors
    }
}