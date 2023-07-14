// g++ 26_postpone_defn.cpp -o 26_postpone_defn && ./26_postpone_defn

#include <string>
#include <iostream>

using namespace std;

const int MinimumPasswordLength = 10;

void encrypt(std::string &s)
{
    for (auto &c : s)
    {
        c = 'a' + (c - 'a' + 3) % 26;
    }
}

// finally, the best way to define and initialize encrypted
std::string encryptPassword(const std::string &password)
{
    if (password.length() < MinimumPasswordLength)
    {
        throw std::logic_error("Password is too short");
    }

    // import std and check length
    string encrypted(password); // define and initialize via copy
    // constructor
    encrypt(encrypted);
    return encrypted;
}

struct Widget
{
    Widget() {}
    Widget(int i) {}
};

int main()
{
    {
        string password = "password1111";
        string encrypted = encryptPassword(password);
        cout << "encrypted: " << encrypted << endl;
    }

    // loop aproaches
    // Approach A: 1 constructor + 1 destructor + n assignments.
    // ■ Approach B: n constructors + n destructors.
    const int n = 1000000;

    {
        // Approach A: define outside loop
        Widget w;
        for (int i = 0; i < n; ++i)
        {
            w = Widget(i);
        }
    }

    {
        // Approach B: define inside loop
        for (int i = 0; i < n; ++i)
        {
            Widget tmp(i);
            Widget w(tmp);
        }
    }

    return 0;
}
