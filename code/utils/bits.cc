#include "../template.cc"
int msb(unsigned int x) {
  for (int i = 1; i <= 16; i <<= 1) x |= x >> i;
  return x - (x >> 1);
}
int lsb(int x) { return x & -x; }
bool oppositeSign(int x, int y) { return (x ^ y) < 0; }
bool isPowOf2(int x) { return x && !(x & (x - 1)); }
void allSubsets(int m) {
  for(int i = m; i; --i &= m) { /* */ }
}
void allSupersets(int m, int nx) {
  for (int i = m; i < nx; ++i |= m) { /* */ }
}
