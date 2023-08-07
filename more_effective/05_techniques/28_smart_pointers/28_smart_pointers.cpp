// g++ 28_smart_pointers.cpp -o 28_smart_pointers && ./28_smart_pointers

#include <iostream>
#include <memory>
#include <string>
#include <cassert>

using namespace std;

int main()
{
    {
        // unique_ptr is used to manage ownership of a dynamically allocated object.
        // It ensures that the object is deleted when the unique_ptr goes out of scope.
        // unique_ptr cannot be copied, only moved.
        unique_ptr<int> myUniquePtr = make_unique<int>(42);

        assert(*myUniquePtr == 42);

        // unique_ptr<int> myUniquePtr2 = myUniquePtr; // Error: unique_ptr cannot be copied.
        unique_ptr<int> myUniquePtr2 = move(myUniquePtr); // OK: unique_ptr can be moved.

        myUniquePtr = nullptr; // The object is deleted.
    }

    {
        // shared_ptr is used to manage ownership of a dynamically allocated object
        // that may have multiple owners. It keeps track of the number of owners and
        // deletes the object when the last owner goes out of scope.
        // shared_ptr can be copied and moved.
        shared_ptr<int> mySharedPtr1 = make_shared<int>(42);
        {
            shared_ptr<int> mySharedPtr2 = mySharedPtr1;
            assert(*mySharedPtr2 == 42);
        }
        assert(*mySharedPtr1 == 42);

        // initialize with a raw pointer
        string str = "Hello";
        shared_ptr<string> mySharedPtr3(new string(str));
        assert(mySharedPtr3->compare("Hello") == 0);
    }

    {
        // weak_ptr is used to observe an object managed by a shared_ptr without
        // increasing its reference count. It is useful for preventing circular
        // references between shared_ptrs.
        shared_ptr<int> mySharedPtr1 = make_shared<int>(42);
        weak_ptr<int> myWeakPtr = mySharedPtr1;

        // *myWeakPtr = 42;                      // Error: weak_ptr cannot be dereferenced.
        assert(myWeakPtr.expired() == false); // expired() returns true if the object has been deleted.
        assert(*myWeakPtr.lock() == 42);      // lock() creates a shared_ptr from a weak_ptr.

        weak_ptr<int> myWeakPtr2 = myWeakPtr;
        assert(myWeakPtr2.expired() == false);
    }
}
