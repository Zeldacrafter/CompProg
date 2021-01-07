#include "../template.hh"
template<int N>
struct SVL : array<int, N + 1> {
  vi ps;
  SVL() : array<int, N + 1>{} {
    FOR (i, 2, N + 1) {
      if ((*this)[i] == 0) ps.pb((*this)[i] = i);
      for (int j = 0; j < SZ(ps) && ps[j] <= (*this)[i] && i * ps[j] <= N; ++j) {
        (*this)[i * ps[j]] = ps[j];
      }
    }
  }
  bool is_prime(int n) { return n == (*this)[n]; };
};
SVL<(int)1e7> sv;
