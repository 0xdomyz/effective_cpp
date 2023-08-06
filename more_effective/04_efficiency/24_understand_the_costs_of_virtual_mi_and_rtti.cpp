// g++ 24_understand_the_costs_of_virtual_mi_and_rtti.cpp -o 24_understand_the_costs_of_virtual_mi_and_rtti && ./24_understand_the_costs_of_virtual_mi_and_rtti

// Summary: Understand the Costs of Virtual Functions, Multiple Inheritance, Virtual Base Classes, and RTTI
// --------------------------------------------------------------------------------------------------------

// The chapter "Understand the Costs of Virtual Functions, Multiple Inheritance,
// Virtual Base Classes, and RTTI" from the book "More Effective C++" discusses the
// performance costs and design trade-offs associated with virtual functions,
// multiple inheritance, virtual base classes, and runtime type identification
// (RTTI) in C++. The chapter covers the following topics:

// - The motivation for using virtual functions, multiple inheritance, virtual base classes, and RTTI
// - The performance costs of virtual functions, multiple inheritance, virtual base classes, and RTTI
// - The design trade-offs associated with virtual functions, multiple inheritance, virtual base classes, and RTTI
// - The use of alternative techniques to achieve similar functionality
// - The trade-offs between performance and functionality

// The chapter provides guidelines for designing and implementing classes that use
// virtual functions, multiple inheritance, virtual base classes, and RTTI, and
// explains the advantages and disadvantages of using these features. The chapter
// also provides examples of how to use these features, and discusses common
// pitfalls and best practices for using these features effectively.

//                      | increases       |Increases        |Reduces
// Feature              | Size of Objects |Per-Class Data   |Inlining
// Virtual Functions    | Yes             |Yes              |Yes
// Multiple Inheritance | Yes             |Yes              |No
// Virtual Base Classes |Often            |Sometimes        |No
// RTTI                 |No               |Yes              |No

// From the point of view of efficiency,
// however, you are unlikely to do better than the compiler
// generated implementations by coding these features yourself
