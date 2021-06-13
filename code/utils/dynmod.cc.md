---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"code/template.cc\"\n// this line is here for a reason\n\
    #include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef\
    \ vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n\
    #define eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a,\
    \ b, c) for (auto a = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\n\
    template <typename T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true\
    \ : false; }\ntemplate <typename T>\nbool ckmax(T& a, const T& b) { return a <\
    \ b ? a = b, true : false; }\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define\
    \ dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__)\
    \ << \"] \"\n#line 2 \"code/utils/dynmod.cc\"\nstruct mint {\n  static ll p;\n\
    \  ll val;\n  mint() : val(0) {}\n  mint(ll v) : val(v % p) { if (val < 0) val\
    \ += p; }\n  mint& operator+=(const mint& o) {\n    val = (val + o.val) % p;\n\
    \    return *this;\n  }\n  mint& operator-=(const mint& o) {\n    val = (val -\
    \ o.val + p) % p;\n    return *this;\n  }\n  mint& operator*=(const mint& o) {\n\
    \    val = val * o.val % p;\n    return *this;\n  }\n  mint& operator/=(mint o)\
    \ { return (*this) *= pow(o, p - 2); }\n  mint& operator++() { return (*this)\
    \ += 1; }\n  mint operator++(int) { return ++(*this) - 1; }\n  mint& operator--()\
    \ { return (*this) -= 1; }\n  mint operator--(int) { return --(*this) + 1; }\n\
    \  mint friend operator+(mint a, const mint& b) { return a += b; }\n  mint friend\
    \ operator-(mint a, const mint& b) { return a -= b; }\n  mint friend operator*(mint\
    \ a, const mint& b) { return a *= b; }\n  mint friend operator/(mint a, const\
    \ mint& b) { return a /= b; }\n  static mint pow(mint a, mint b) {\n    mint res\
    \ = 1;\n    for (; b.val; b.val >>= 1, a = a * a)\n      if (b.val & 1) res =\
    \ res * a;\n    return res;\n  }\n  friend istream& operator>>(istream& i, mint&\
    \ m) {\n    i >> m.val;\n    m.val %= p;\n    if (m.val < 0) m.val += p;\n   \
    \ return i;\n  }\n  friend ostream& operator<<(ostream& o, const mint& m) { return\
    \ o << m.val; }\n};\nusing mod = mint;\nll mod::p = (ll)1e9 + 7ll;\n// ll mint::p\
    \ = 998244353ll;\n"
  code: "#include \"../template.hh\"\nstruct mint {\n  static ll p;\n  ll val;\n \
    \ mint() : val(0) {}\n  mint(ll v) : val(v % p) { if (val < 0) val += p; }\n \
    \ mint& operator+=(const mint& o) {\n    val = (val + o.val) % p;\n    return\
    \ *this;\n  }\n  mint& operator-=(const mint& o) {\n    val = (val - o.val + p)\
    \ % p;\n    return *this;\n  }\n  mint& operator*=(const mint& o) {\n    val =\
    \ val * o.val % p;\n    return *this;\n  }\n  mint& operator/=(mint o) { return\
    \ (*this) *= pow(o, p - 2); }\n  mint& operator++() { return (*this) += 1; }\n\
    \  mint operator++(int) { return ++(*this) - 1; }\n  mint& operator--() { return\
    \ (*this) -= 1; }\n  mint operator--(int) { return --(*this) + 1; }\n  mint friend\
    \ operator+(mint a, const mint& b) { return a += b; }\n  mint friend operator-(mint\
    \ a, const mint& b) { return a -= b; }\n  mint friend operator*(mint a, const\
    \ mint& b) { return a *= b; }\n  mint friend operator/(mint a, const mint& b)\
    \ { return a /= b; }\n  static mint pow(mint a, mint b) {\n    mint res = 1;\n\
    \    for (; b.val; b.val >>= 1, a = a * a)\n      if (b.val & 1) res = res * a;\n\
    \    return res;\n  }\n  friend istream& operator>>(istream& i, mint& m) {\n \
    \   i >> m.val;\n    m.val %= p;\n    if (m.val < 0) m.val += p;\n    return i;\n\
    \  }\n  friend ostream& operator<<(ostream& o, const mint& m) { return o << m.val;\
    \ }\n};\nusing mod = mint;\nll mod::p = (ll)1e9 + 7ll;\n// ll mint::p = 998244353ll;\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/utils/dynmod.cc
  requiredBy: []
  timestamp: '2020-12-20 22:09:43+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/utils/dynmod.cc
layout: document
redirect_from:
- /library/code/utils/dynmod.cc
- /library/code/utils/dynmod.cc.html
title: code/utils/dynmod.cc
---
