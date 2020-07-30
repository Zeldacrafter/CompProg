#include "../template.cc"
// Returns one plus the index of the least significant 1-bit of x, or
// if x is zero, returns zero.
int __builtin_ffs(unsigned int x);
int __builtin_clz(unsigned int x); // count leading zeroes
int __builtin_ctz(unsigned int x); // count trailing zeroes
int __builtin_popcount(unsigned int x);
// unsigned long: Postfix 'l', unsigned long long: Postfix 'll'

// Rotate bits of x left by n places.
unsigned int rotl(unsigned int x, int n);
// Rotate bits of x right by n places.
unsigned int rotr(unsigned int x, int n);
