// g++ 07_overload_and_or_comma.cpp -o test && ./test

// If you don’t have a
// good reason for overloading an operator, don’t overload it. In the case
// of &&, ||, and ,, it’s difficult to have a good reason, because no matter
// how hard you try, you can’t make them behave the way they’re supposed to

#include <iostream>
#include <cstring>

using namespace std;

// reverse string s in place
void reverse(char s[])
{
    for (int i = 0, j = strlen(s) - 1;
         i < j;
         ++i, --j) // aha! the comma operator!
    {
        int c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    char s[] = "hello";
    reverse(s);
    cout << s << endl;
    return 0;
}
