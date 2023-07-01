// g++ 20_pass_by_ref_const.cpp -o 20_pass_by_ref_const && ./20_pass_by_ref_const

#include <iostream>
#include <string>

using namespace std;

// by const ref
class Person
{
public:
    Person(){};          // parameters omitted for simplicity
    virtual ~Person(){}; // see Item 7 for why this is virtual
private:
    std::string name;
    std::string address;
};

class Student : public Person
{
public:
    Student(){}; // parameters again omitted
    virtual ~Student(){};

private:
    std::string schoolName;
    std::string schoolAddress;
};

bool validateStudent(Student s) { return 1; }; // function taking a Student

bool validateStudent2(const Student &s) { return 1; }; // function taking a const Student&

// slicing
class Window
{
private:
    std::string n;

public:
    std::string name() const { return n; }; // return name of window
    virtual void display() const
    {
        std::cout << "Window::display()" << std::endl;
    }; // draw window and contents
};

class WindowWithScrollBars : public Window
{
public:
    virtual void display() const
    {
        std::cout << "WindowWithScrollBars::display()" << std::endl;
    }; // draw window and contents
};

void printNameAndDisplay(Window w) // incorrect! parameter
{                                  // may be sliced!
    std::cout << w.name();
    w.display();
}

void printNameAndDisplay2(const Window &w) // fine, parameter won’t
{                                          // be sliced
    std::cout << w.name();
    w.display();
}

int main()
{
    {
        // by value
        Student plato;                           // Plato studied under Socrates
        bool platoIsOK = validateStudent(plato); // call the function

        // by const reference
        Student aristotle;                                // Aristotle studied under Plato
        bool aristotleIsOK = validateStudent2(aristotle); // call the function
    }

    {
        WindowWithScrollBars wwsb;
        printNameAndDisplay(wwsb);
        printNameAndDisplay2(wwsb);
    }
}
