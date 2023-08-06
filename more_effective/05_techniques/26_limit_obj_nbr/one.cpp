// g++ one.cpp -o one && ./one

#include <iostream>

using namespace std;

class PrintJob; // forward declaration

class Printer
{
public:
    void submitJob(const PrintJob &job){};
    void reset(){};
    void performSelfTest(){};
    friend Printer &thePrinter();

private:
    Printer(){};
    Printer(const Printer &rhs){};
};

Printer &thePrinter()
{
    static Printer p; // the single printer object
    return p;
}

class PrintJob
{
public:
    PrintJob(const string &whatToPrint){};
};

int main()
{
    string buffer;

    // put stuff in buffer
    thePrinter().reset();
    thePrinter().submitJob(buffer);
}
