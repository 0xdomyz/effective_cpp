// g++ 32_program_in_the_future_tense.cpp -o 32_program_in_the_future_tense && ./32_program_in_the_future_tense

// things change

// new functions will be added to libraries
// new overloadings will occur, potentially ambiguous function calls
// new classes will be added to hierarchies
// present-day derived classes may be tomorrow’s base classes
// new applications will be written
// functions will be called in new contexts
// programmers charged with software maintenance are not the code’s original developers,
// hence to design and implement in a fashion that facilitates comprehension,
//  modification, and enhancement by others.

// express design constraints in C++ instead of
// (or in addition to) comments or other documentation
//
// use C++ to prevent derivation
// all instances be on the heap
// make cpy and assignment private

// Avoid “demand-paged”
// virtual functions, whereby you make no functions virtual unless somebody comes along
// and demands that you do it
//
// determine the
// meaning of a function and whether it makes sense to let it be redefined
// in derived classes

// Handle assignment and copy construction in every class,

//  strive to provide classes
// whose operators and functions have a natural syntax and an intuitive
// semantics. Preserve consistency with the behavior of the built-in
// types: when in doubt, do as the ints do.

// anything somebody can do, they will do
// design your
// classes so you can prevent, detect, or correct such errors

// Strive for portable code.

// Design your code so that when changes are necessary, the impact is
// localized.
//
// Encapsulate as much as you can; make implementation details private.
//
// Where applicable, use unnamed namespaces or filestatic objects and functions
// (see Item 31).
//
// Try to avoid designs that lead to virtual base classes,
//
// Avoid RTTI-based designs that make use of cascading ifthen-else
// statements (see Item 31 again).

// Provide complete classes, even if some parts aren’t currently used.
// When new demands are made on your classes, you’re less likely to
// have to go back and modify them.

// Design your interfaces to facilitate common operations and prevent common
// errors.
// Make the classes easy to use correctly, hard
// to use incorrectly. For example, prohibit copying and assignment
// for classes where those operations make no sense. Prevent partial
// assignments (see Item 33).

// If there is no great penalty for generalizing your code, generalize it.
// For example, if you are writing an algorithm for tree traversal, consider
//  generalizing it to handle any kind of directed acyclic graph.
