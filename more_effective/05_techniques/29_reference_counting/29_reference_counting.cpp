// g++ 29_reference_counting.cpp -o 29_reference_counting && ./29_reference_counting

// copy on write
//
// how to implement index access
// - const version easy
// - non-const version via copy on write
//
// it is idea of sharing a value with other objects until we have to
//  write on our own copy of the value
//
// Example: in operating systems, where processes are routinely
// allowed to share pages until they want to modify
//  data on their own copy of a page.
//
// It’s a specific example of a more general
//  approach to efficiency, that of lazy evaluation

// pointer, ref and copy on write
//
// problem:
// if someone had saved a reference to the result of a call to String’s
// nonconst operator[].
//  then multiple object could be affected by changes via the reference
//
// solution:
// 1 - ignore
// 2 - define out of existence
// 3 - add sharability flag that is turned off when a non-const operator[] is
//     performed. Once false, the flag can never be turned on again.
//
// std mix of 2 and 3
// The reference returned from the non-const operator[] is
// guaranteed to be valid until the next function call that might modify the string.
