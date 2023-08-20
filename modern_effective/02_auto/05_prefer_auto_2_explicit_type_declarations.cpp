// g++ 05_prefer_auto_2_explicit_type_declarations.cpp -o 05_prefer_auto_2_explicit_type_declarations && ./05_prefer_auto_2_explicit_type_declarations

// auto variables must be initialized, are generally immune to type mismatches
// that can lead to portability or efficiency problems, can ease the process of
// refactoring, and typically require less typing than variables with explicitly
// specified types.
// • auto-typed variables are subject to the pitfalls described in Items 2 and 6.