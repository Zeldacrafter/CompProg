#include "../template.hh"
template<int N>
struct SV : bitset<N + 1> {
  SV() {
    this->set(); (*this)[0] = (*this)[1] = false;
    FOR (i, 2, N + 1) {
      if ((*this)[i] && (ll)i * i <= N) {
        for (int j = i * i; j <= N; j += i) (*this)[j] = false; 
      }
    }
  }
  bool is_prime(int n) { return (*this)[n]; }
};
SV<(int)1e7> sv;

