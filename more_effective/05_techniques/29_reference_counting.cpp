// g++ 29_reference_counting.cpp -o 29_reference_counting && ./29_reference_counting

// Summary: Reference Counting
// ----------------------------

// The chapter "Reference Counting" from the book "More Effective C++" discusses
// the use of reference counting to manage shared ownership of heap-based objects.
// The chapter covers the following topics:

// - The use of reference counting to manage shared ownership of heap-based objects
// - The implementation of reference counting using shared_ptr
// - The use of weak_ptr to break circular references in shared ownership scenarios
// - The performance implications of reference counting
// - The use of custom deleters to manage resources other than heap-based objects

// The chapter provides guidelines for choosing the appropriate smart pointer type
// for a given scenario, and explains the advantages and disadvantages of each
// type. The chapter also provides examples of how to use each type, and discusses
// common pitfalls and best practices for smart pointer usage.