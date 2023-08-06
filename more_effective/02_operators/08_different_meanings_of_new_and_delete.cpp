// In C++, new and delete are used for dynamic memory allocation and deallocation,
// respectively. However, they have different meanings and uses.

// new is used to allocate memory for a single object or an array of objects on the
// heap. It returns a pointer to the allocated memory, which can be used to access
// the object(s). For example:

int *p = new int;       // allocate memory for a single int
int *arr = new int[10]; // allocate memory for an array of 10 ints

// In both cases, new returns a pointer to the allocated memory, which can be used
// to access the object(s). It is important to note that new throws a std::bad_alloc
// exception if it fails to allocate memory.

// delete is used to deallocate memory that was allocated with new. It takes a pointer
// to the memory that should be deallocated. For example:

int main()
{

    delete p;     // deallocate memory for a single int
    delete[] arr; // deallocate memory for an array of 10 ints
}
// It is important to note that delete should only be used to deallocate memory that
// was allocated with new. Using delete on a pointer that was not allocated with new
// results in undefined behavior.

// In addition to new and delete, C++ also provides placement new and placement delete,
// which are used to construct and destruct objects in pre-allocated memory. Placement
// new and placement delete are used in advanced memory management scenarios and are
// not commonly used in everyday programming.