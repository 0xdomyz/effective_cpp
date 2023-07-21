// g++ 09_test_cin_to_string.cpp -o test && echo "Puppy Kitten Puppy Kitten" | ./test

#include <iostream>
#include <string>

int main()
{
    std::string word;
    while (std::cin >> word)
    {
        std::cout << word << std::endl;
    }
    return 0;
}
