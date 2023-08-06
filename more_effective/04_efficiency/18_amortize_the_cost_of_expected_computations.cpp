// g++ 18_amortize_the_cost_of_expected_computations.cpp -o 18_amortize_the_cost_of_expected_computations && ./18_amortize_the_cost_of_expected_computations

// Summary: Amortize the Cost of Expected Computations
// ---------------------------------------------------

// The chapter "Amortize the Cost of Expected Computations" from the book "More
// Effective C++" discusses the use of amortization to improve program performance
// by spreading the cost of expected computations over time. The chapter covers the
// following topics:

// - The motivation for using amortization
// - The use of data structures that amortize the cost of expected computations
// - The use of dynamic programming to amortize the cost of expected computations
// - The use of lazy evaluation to amortize the cost of expected computations
// - The trade-offs between amortization and eager evaluation

// The chapter provides guidelines for designing and implementing data structures
// and algorithms that use amortization, and explains the advantages and
// disadvantages of using amortization. The chapter also provides examples of how
// to use amortization, and discusses common pitfalls and best practices for using
// amortization effectively.

// greater speed can often be purchased at a cost of increased memory
// usage.

// Keeping track of running minima, maxima, and averages requires extra space,
// but it saves time.

// Caching results necessitates greater memory usage but reduces the time needed to
// regenerate the results once they’ve been cached.

// Prefetching demands a place to put the things that are prefetched,
// but it reduces the time needed to access those things.

//

// Over-eager evaluation is a technique for
// improving the efficiency of programs when you must support operations
// whose results are almost always needed or whose results are
// often needed more than once
