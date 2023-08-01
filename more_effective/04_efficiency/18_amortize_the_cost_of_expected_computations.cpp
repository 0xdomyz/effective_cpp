// g++ 18_amortize_the_cost_of_expected_computations.cpp -o 18_amortize_the_cost_of_expected_computations && ./18_amortize_the_cost_of_expected_computations

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
