// g++ 17_consider_using_lazy_evaluation.cpp -o 17_consider_using_lazy_evaluation && ./17_consider_using_lazy_evaluation

// to avoid unnecessary copying of objects
// to distinguish reads from writes using operator[]
// to avoid unnecessary reads from databases
// to avoid unnecessary numerical computations.

// lazy evaluation won't save your program any work if all your
// computations are necessary.
// Lazy evaluation is only useful when there's a reasonable chance your
// software will be asked to perform computations that can be avoided.
