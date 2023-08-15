// g++ 34_understand_how_to_combine_cpp_and_c_in_the_same_program.cpp -o 34_understand_how_to_combine_cpp_and_c_in_the_same_program && ./34_understand_how_to_combine_cpp_and_c_in_the_same_program

// If you want to mix C++ and C in the same program, remember the following simple guidelines:
// ■ Make sure the C++ and C compilers produce compatible object
// files.
// ■ Declare functions to be used by both languages extern "C".
// ■ If at all possible, write main in C++.
// ■ Always use delete with memory from new; always use free with
// memory from malloc.
// ■ Limit what you pass between the two languages to data structures
// that compile under C; the C++ version of structs may contain nonvirtual member functions.
