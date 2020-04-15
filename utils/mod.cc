#include "../template.cc"
struct mod {
  static const ll p = 1e9 + 7;
  ll val;
  mod() : val(0) {}
  mod(ll val) : val(val % p) {}
  mod operator+(mod o) { return mod(val + o.val); }
  mod operator-(mod o) { return mod(val - o.val + p); }
  mod operator*(mod o) { return mod(val * o.val); }
  mod operator/(mod o) { return mod(*this * pow(o, p - 2)); }
  static mod pow(mod a, mod b) {
    mod res = 1;
    for (; b.val; b.val >>= 1, a = a * a)
      if (b.val & 1) res = res * a;
    return res;
  }
  friend istream& operator>>(istream& i, mod& m) {
      i >> m.val;
      m.val %= mod::p;
      if (m.val < 0) m.val += mod::p;
      return i;
  }
  friend ostream& operator<<(ostream& o, mod m) {
    return o << m.val;
  }
};
