// g++ 28_smart_pointers.cpp -o 28_smart_pointers && ./28_smart_pointers

// Summary: Smart Pointers
// ------------------------------

// The chapter "Smart Pointers" from the book "More Effective C++" discusses the
// use of smart pointers to manage heap-based objects. The chapter covers the
// following topics:

// - The difference between raw pointers and smart pointers
// - The use of unique_ptr to manage exclusive ownership of heap-based objects
// - The use of shared_ptr to manage shared ownership of heap-based objects
// - The use of weak_ptr to break circular references in shared ownership scenarios
// - The use of custom deleters to manage resources other than heap-based objects

// The chapter provides guidelines for choosing the appropriate smart pointer type
// for a given scenario, and explains the advantages and disadvantages of each
// type. The chapter also provides examples of how to use each type, and discusses
// common pitfalls and best practices for smart pointer usage.