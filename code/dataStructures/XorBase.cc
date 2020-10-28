#include "../template.hh" // https://codeforces.com/blog/entry/68953
template<typename T = int>
struct XorBase : vector<T> {
  void apply(T& toApply) {
    for(const T& b : *this)
      ckmin(toApply, toApply ^ b);
  }
  pair<bool, vector<bool>> to(T elem) {
    vector<bool> res(SZ(*this));
    F0R(i, SZ(*this))
      res[i] = ckmin(elem, elem ^ (*this)[i]);
    return mp(!elem, res);
  }
  bool isIn(T toCheck) {
    apply(toCheck);
    return !toCheck;
  }
  bool add(T toAdd) {
    apply(toAdd);
    if(toAdd) this->pb(toAdd);
    return toAdd;
  }
  XorBase(const vector<T>& elems) {
    for(const auto& e : elems) add(e);
  }
  XorBase() {};
};
