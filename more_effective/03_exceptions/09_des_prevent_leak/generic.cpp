// In C++, destructors are used to clean up resources that were allocated by an object
// during its lifetime. Failure to properly clean up resources can result in resource
// leaks, which can cause a program to run out of memory or other system resources.

// There are several ways to use destructors to prevent resource leaks:

// 1. Use RAII (Resource Acquisition Is Initialization) to manage resources. RAII is a
// programming technique that involves acquiring resources in a constructor and releasing
// them in a destructor. This ensures that resources are always properly cleaned up,
// even in the presence of exceptions or other errors. For example:

#include <cstdio>
#include <string>
#include <memory> // add this line to fix the first error

class File
{
public:
    File(const std::string &filename) : fileHandle(fopen(filename.c_str(), "r")) {}
    ~File()
    {
        if (fileHandle)
            fclose(fileHandle);
    }

private:
    FILE *fileHandle;
};

// In this example, the File class acquires a file handle in its constructor and releases
// it in its destructor. This ensures that the file handle is always properly cleaned up,
// even if an exception is thrown or the object is destroyed prematurely.

// 2. Use smart pointers to manage resources. Smart pointers are objects that behave like
// pointers, but automatically clean up the resource they point to when they are destroyed.
// There are several types of smart pointers in C++, including std::unique_ptr, std::shared_ptr,
// and std::weak_ptr. For example:

std::unique_ptr<int> p(new int); // allocate an int and manage it with a unique_ptr

// In this example, the unique_ptr manages the lifetime of the int object. When the unique_ptr
// is destroyed, it automatically deallocates the memory used by the int.

// 3. Use a try-catch block to handle exceptions and clean up resources. If an exception is
// thrown during the execution of a function, the program may not reach the end of the function
// and may not execute the destructor. To ensure that resources are properly cleaned up in the
// presence of exceptions, a try-catch block can be used to catch the exception and clean up
// resources before re-throwing the exception. For example:

class Resource
{
public:
    Resource() {}
    ~Resource() {}
};

void foo()
{
    Resource *r = new Resource;
    try
    {
        // do something with r
    }
    catch (...)
    {
        delete r;
        throw;
    }
}

// In this example, the foo function allocates a Resource object and uses a try-catch block
// to ensure that the object is properly cleaned up in the presence of exceptions.

// By using these techniques, it is possible to prevent resource leaks and ensure that
// programs are safe and reliable.