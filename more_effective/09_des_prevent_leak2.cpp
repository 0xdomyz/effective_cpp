// g++ 09_des_prevent_leak2.cpp -o test && ./test

// By adhering to the rule that resources should be encapsulated inside
// objects, you can usually avoid resource leaks in the presence of exceptions.

#include <iostream>

using namespace std;

struct WINDOW_HANDLE
{
    int x;
};

WINDOW_HANDLE getWindow()
{
    WINDOW_HANDLE w;
    w.x = 1;
    return w;
}

void destroyWindow(WINDOW_HANDLE w)
{
    std::cout << "destroyWindow" << std::endl;
}

// class for acquiring and releasing a window handle
class WindowHandle
{
public:
    WindowHandle(WINDOW_HANDLE handle) : w(handle) {}
    ~WindowHandle() { destroyWindow(w); }
    operator WINDOW_HANDLE() { return w; } // see below
private:
    WINDOW_HANDLE w;
    // The following functions are declared private to prevent
    // multiple copies of a WINDOW_HANDLE from being created.
    // See Item 28 for a discussion of a more flexible approach.
    WindowHandle(const WindowHandle &);
    WindowHandle &operator=(const WindowHandle &);
};

struct Information
{
    int x;
};

// this function avoids leaking resources if an
// exception is thrown
void displayInfo(const Information &info)
{
    WindowHandle w(getWindow());
    // display info in window corresponding to w;
}

int main()
{
    displayInfo(Information());
    return 0;
}
