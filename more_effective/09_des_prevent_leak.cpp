// g++ 09_des_prevent_leak.cpp -o test && echo "Puppy Kitten Puppy Kitten" | ./test

#include <iostream>
#include <memory>
#include <string>
#include <fstream>

using namespace std;

// say sayonara to pointers that are used to manipulate local resources

class ALA
{
public:
    virtual void processAdoption() = 0;
};
class Puppy : public ALA
{
public:
    virtual void processAdoption()
    {
        cout << "Puppy" << endl;
    };
};
class Kitten : public ALA
{
public:
    virtual void processAdoption()
    {
        cout << "Kitten" << endl;
    };
};

// read animal information from s, then return a pointer
// to a newly allocated object of the appropriate type
ALA *readALA(istream &s)
{
    string type;
    s >> type;

    if (type == "Puppy")
    {
        return new Puppy;
    }
    else if (type == "Kitten")
    {
        return new Kitten;
    }
    else
    {
        cout << "Unknown animal type" << endl;
        return new Kitten;
    }
};

// void processAdoptions(istream &dataSource)
// {
//     while (dataSource)
//     {
//         ALA *pa = readALA(dataSource);
//         try
//         {
//             pa->processAdoption();
//         }
//         catch (...)
//         {              // catch all exceptions
//             delete pa; // avoid resource leak when an
//             // exception is thrown
//             throw; // propagate exception to caller
//         }
//         delete pa; // avoid resource leak when no
//     }              // exception is thrown
// }

// use smart pointers to prevent resource leak
void processAdoptions(istream &dataSource)
{
    while (dataSource)
    {
        if (dataSource.eof())
        {
            break;
        }
        if (dataSource.fail())
        {
            dataSource.clear();
            dataSource.ignore();
            continue;
        }
        // if no more string on the line
        if (dataSource.peek() == '\n')
        {
            break;
        }

        // auto_ptr<ALA> pa(readALA(dataSource));
        unique_ptr<ALA> pa(readALA(dataSource));
        pa->processAdoption();
    }
}

int main()
{
    // from a file
    // ifstream dataSource("animals.txt");

    processAdoptions(cin);

    return 0;
}