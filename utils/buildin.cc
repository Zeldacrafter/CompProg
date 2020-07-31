#include "../template.cc"
// Returns one plus the index of the least significant 1-bit of x, or
// if x is zero, returns zero.
int __builtin_ffs(unsigned int x);
int __builtin_clz(unsigned int x); // count leading zeroes
int __builtin_ctz(unsigned int x); // count trailing zeroes
int __builtin_popcount(unsigned int x); // count set one bits
// unsigned long: Postfix 'l', unsigned long long: Postfix 'll'

// Rotate bits of x (left|right) by n places.
unsigned int rotl(unsigned int x, int n);
unsigned int rotr(unsigned int x, int n);
