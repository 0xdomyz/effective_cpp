// g++ 24_understand_the_costs_of_virtual_mi_and_rtti.cpp -o 24_understand_the_costs_of_virtual_mi_and_rtti && ./24_understand_the_costs_of_virtual_mi_and_rtti

//                      | increases       |Increases        |Reduces
// Feature              | Size of Objects |Per-Class Data   |Inlining
// Virtual Functions    | Yes             |Yes              |Yes
// Multiple Inheritance | Yes             |Yes              |No
// Virtual Base Classes |Often            |Sometimes        |No
// RTTI                 |No               |Yes              |No

// From the point of view of efficiency,
// however, you are unlikely to do better than the compiler
// generated implementations by coding these features yourself

// The "Understand the Costs of Virtual Functions, Multiple Inheritance, Virtual
// Base Classes, and RTTI" technique is a way to improve program performance and
// maintainability by understanding the costs and benefits of using virtual functions,
// multiple inheritance, virtual base classes, and RTTI (Run-Time Type Information).
// This technique is discussed in the book "Effective C++" by Scott Meyers.

#include <iostream>

// Example: Understand the Costs of Virtual Functions, Multiple Inheritance,
// Virtual Base Classes, and RTTI
// --------------------------------------------------------------------------

// Suppose we have a program that uses virtual functions to implement polymorphism,
// and we want to improve the performance of the program. We can do this by minimizing
// the use of virtual functions, and using non-virtual functions or templates instead
// where possible.

class Shape
{
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
};

class Circle : public Shape
{
public:
    Circle(double radius) : radius_(radius) {}
    double area() const override { return 3.14159 * radius_ * radius_; }

private:
    double radius_;
};

class Square : public Shape
{
public:
    Square(double side) : side_(side) {}
    double area() const override { return side_ * side_; }

private:
    double side_;
};

// In this implementation, the Shape class defines a virtual function area() that
// is overridden by the Circle and Square classes to compute the area of a circle
// or square. This implementation works fine, but it can be slow if the program
// needs to compute the area of many shapes, because virtual functions incur a
// performance penalty due to the need to look up the function at run time.

// To improve the performance of our program, we can use templates instead of virtual
// functions to compute the area of a shape. We can define a template function that
// takes a shape object as a parameter, and computes the area of the shape using the
// appropriate formula for the shape type.

template <typename T>
double area(const T &shape)
{
    return shape.area();
}

// Now, if we want to compute the area of a circle or square, we can call the area()
// function with a Circle or Square object, and the appropriate template specialization
// will be selected at compile time, avoiding the need for a virtual function lookup.

void test_compute_area()
{
    Circle c(2.0);
    Square s(3.0);
    std::cout << "Area of circle: " << area(c) << std::endl;
    std::cout << "Area of square: " << area(s) << std::endl;
}

// By using templates instead of virtual functions, we have improved the performance
// of our program, and made it easier to reason about the behavior of the program.
// This technique can be applied to other parts of the program as well, such as
// sorting, searching, and filtering, to improve program performance and maintainability.

// In addition to virtual functions, the book "Effective C++" also discusses the costs
// and benefits of multiple inheritance, virtual base classes, and RTTI, and provides
// guidelines for using these features effectively. By understanding the costs and
// benefits of these features, and using them judiciously, we can improve the quality
// and efficiency of our programs, and avoid common pitfalls and performance problems.