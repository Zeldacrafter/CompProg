#include "../template.cc" // https://codeforces.com/blog/entry/68953
template<int N>
struct XorBase : vector<bitset<N>> {
  using T = bitset<N>;
  static bool tryReduce(T& test, const T& other) {
    for (int i = N - 1; ~i; --i) {
      if (other[i]) {
        if (test[i]) return test ^= other, true;
        break;
      }
    }
    return false;
  }
  void apply(T& toApply) {
    for(const T& b : *this)
      tryReduce(toApply, b);
  }
  pair<bool, vector<bool>> to(T elem) {
    vector<bool> res(SZ(*this));
    F0R(i, SZ(*this))
      res[i] = tryReduce(elem, (*this)[i]);
    return mp(elem.none(), res);
  }
  bool isIn(T toCheck) {
    apply(toCheck);
    return toCheck.none();
  }
  bool add(T toAdd) {
    apply(toAdd);
    if(toAdd.any()) this->pb(toAdd);
    return toAdd.any();
  }
  XorBase(const vector<T>& elems) {
    for(const auto& e : elems) add(e);
  }
  XorBase() {};
};
