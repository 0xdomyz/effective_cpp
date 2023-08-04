// g++ 25_virtualizing_constructors_and_non_member_functions.cpp -o 25_virtualizing_constructors_and_non_member_functions && ./25_virtualizing_constructors_and_non_member_functions

//  A virtual
// constructor is a function that creates different types of objects depending on the input it is given. Virtual constructors are useful in many
// contexts, only one of which is reading object information from disk (or
// off a network connection or from a tape

// As you can see, a class’s virtual copy constructor just calls its real copy
// constructor. The meaning of “copy” is hence the same for both functions

// Virtual-acting non-member functions, then, are easy. You write virtual
// functions to do the work, then write a non-virtual function that does
// nothing but call the virtual function. To avoid incurring the cost of a
// function call for this syntactic sleight-of-hand, of course, you inline the
// non-virtual function.