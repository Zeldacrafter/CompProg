#include "../template.cc"
// Returns one plus the index of the least
// significant 1-bit of x, or if x is zero,
// returns zero.
int __builtin_ffs(unsigned int x);

// Returns the number of leading 0-bits
// in x, starting at the most significant
// bit position. If x is 0, the result is
// undefined
int __builtin_clz(unsigned int x);

// Returns the number of trailing 0-bits in
// x, starting at the least significant bit
// position. If x is 0, the result is
// undefined.
int __builtin_ctz(unsigned int x);

// Returns the number of 1-bits in x.
int __builtin_popcount(unsigned int x);

// All above methods also exist for
// unsigned long: Postfix 'l'
// unsigned long long: Postfix 'll'

// Rotate bits of x left by n places.
unsigned int _rotl(unsigned int x, int n);
unsigned __int64 _rotl64(unsigned __int64 x,
                         int n);

// Rotate bits of x right by n places.
unsigned int _rotr(unsigned int x, int n);
unsigned __int64 _rotr64(unsigned __int64 x,
                         int n);
