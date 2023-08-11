// g++ -std=c++11 -o shared_ptr_cow shared_ptr_cow.cpp && ./shared_ptr_cow

#include <memory>
#include <cstring>
#include <iostream>

using namespace std;

class CowDeleter
{
public:
    CowDeleter() : count(new int(1)) {}
    CowDeleter(const CowDeleter &other) : count(other.count)
    {
        ++(*count);
    }
    void operator()(const char *ptr)
    {
        if (--(*count) == 0)
        {
            delete[] ptr;
            delete count;
        }
    }

private:
    int *count;
};

class CowString
{
public:
    CowString(const char *str) : data(str, CowDeleter()) {}
    CowString(const CowString &other) : data(other.data) {}
    const char &operator[](int index) const
    {
        return data.get()[index];
    }
    char &operator[](int index)
    {
        if (data.use_count() > 1)
        {
            char *newData = new char[size() + 1];
            std::copy(data.get(), data.get() + size() + 1, newData);
            data = std::shared_ptr<const char>(newData, CowDeleter());
        }
        return const_cast<char &>(data.get()[index]);
    }
    int size() const
    {
        return strlen(data.get());
    }
    const char *c_str() const { return data.get(); }

private:
    std::shared_ptr<const char> data;
};

int main()
{
    CowString s1("hello");
    CowString s2(s1);

    // show using same data
    cout << "should be the same: " << endl;
    cout << (void *)(s1.c_str()) << endl;
    cout << (void *)(s2.c_str()) << endl;

    s2[0] = 'H';
    cout << "should be different since s2 is copied on write: " << endl;
    cout << (void *)(s2.c_str()) << endl;

    return 0;
}
