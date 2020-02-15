#include "template.cc"
int msbIndex(unsigned int x) {
  return 31 - __builtin_clz(x);
}

bool oppositeSign(int x, int y) {
  return (x ^ y) < 0;
}

bool isPowOf2(int x) {
  return x && !(x & (x - 1));
}

bool lsb(int x) { return x & (-x); }
