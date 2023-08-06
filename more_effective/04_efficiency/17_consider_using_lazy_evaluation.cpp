// g++ 17_consider_using_lazy_evaluation.cpp -o 17_consider_using_lazy_evaluation && ./17_consider_using_lazy_evaluation

// Summary: Consider Using Lazy Evaluation
// ----------------------------------------

// The chapter "Consider Using Lazy Evaluation" from the book "More Effective C++"
// discusses the use of lazy evaluation to improve program performance and reduce
// memory usage. The chapter covers the following topics:

// - The motivation for using lazy evaluation
// - The use of lazy evaluation to defer computation until it is needed
// - The use of lazy evaluation to avoid unnecessary computation and memory allocation
// - The use of lazy evaluation to implement caching and memoization
// - The use of lazy evaluation to implement infinite data structures
// - The trade-offs between lazy evaluation and eager evaluation

// The chapter provides guidelines for designing and implementing lazy evaluation,
// and explains the advantages and disadvantages of using lazy evaluation. The
// chapter also provides examples of how to use lazy evaluation, and discusses
// common pitfalls and best practices for using lazy evaluation effectively.

// to avoid unnecessary copying of objects
// to distinguish reads from writes using operator[]
// to avoid unnecessary reads from databases
// to avoid unnecessary numerical computations.

// lazy evaluation won't save your program any work if all your
// computations are necessary.
// Lazy evaluation is only useful when there's a reasonable chance your
// software will be asked to perform computations that can be avoided.
