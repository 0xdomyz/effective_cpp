// In C++, constructors are used to initialize objects and allocate resources that
// are needed during the lifetime of the object. Failure to properly clean up resources
// that were allocated in a constructor can result in resource leaks, which can cause a
// program to run out of memory or other system resources.

// There are several ways to prevent resource leaks in constructors:

// 1. Use RAII (Resource Acquisition Is Initialization) to manage resources. RAII is a
// programming technique that involves acquiring resources in a constructor and releasing
// them in a destructor. This ensures that resources are always properly cleaned up,
// even in the presence of exceptions or other errors. For example:

#include <cstdio>
#include <stdexcept>
#include <string>
#include <memory>

class File
{
public:
    File(const std::string &filename) : fileHandle(fopen(filename.c_str(), "r"))
    {
        if (!fileHandle)
        {
            throw std::runtime_error("Failed to open file");
        }
    }
    ~File()
    {
        if (fileHandle)
            fclose(fileHandle);
    }

private:
    FILE *fileHandle;
};

// In this example, the File class acquires a file handle in its constructor and releases
// it in its destructor. If the file handle cannot be acquired, the constructor throws an
// exception to indicate the failure.

// 2. Use smart pointers to manage resources. Smart pointers are objects that behave like
// pointers, but automatically clean up the resource they point to when they are destroyed.
// There are several types of smart pointers in C++, including std::unique_ptr, std::shared_ptr,
// and std::weak_ptr. For example:

class Resource
{
public:
    Resource() : data(new int) {}

private:
    std::unique_ptr<int> data;
};

// In this example, the Resource class uses a unique_ptr to manage the lifetime of the int
// object that it allocates in its constructor. When the Resource object is destroyed, the
// unique_ptr automatically deallocates the memory used by the int.

// 3. Use a try-catch block to handle exceptions and clean up resources. If an exception is
// thrown during the execution of a constructor, the program may not reach the end of the
// constructor and may not execute the destructor. To ensure that resources are properly
// cleaned up in the presence of exceptions, a try-catch block can be used to catch the
// exception and clean up resources before re-throwing the exception. For example:

class Resource2
{
public:
    Resource2() : data(new int)
    {
        try
        {
            // do something that might throw an exception
        }
        catch (...)
        {
            delete data;
            throw;
        }
    }

private:
    int *data;
};

// In this example, the Resource2 class uses a try-catch block to ensure that the int object
// that it allocates in its constructor is properly cleaned up in the presence of exceptions.

// By using these techniques, it is possible to prevent resource leaks in constructors and
// ensure that programs are safe and reliable.