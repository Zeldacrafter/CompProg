#include "../template.cc"
int msbIndex(unsigned int x) {
  return 31 - __builtin_clz(x);
}

int msb(unsigned int x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x - (x >> 1);
}

bool oppositeSign(int x, int y) {
  return (x ^ y) < 0;
}

bool isPowOf2(int x) {
  return x && !(x & (x - 1));
}

bool lsb(int x) { return x & (-x); }

void allSubsetsOfM(int m) {
  for(int i = m; i; --i &= m) { /* */ }
}
