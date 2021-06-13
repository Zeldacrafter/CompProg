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
    links:
    - https://codeforces.com/blog/entry/68953
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
    \ << \"] \"\n#line 2 \"code/dataStructures/XorBaseN.cc\"\ntemplate<int N>\nstruct\
    \ XorBase : vector<bitset<N>> {\n  using T = bitset<N>;\n  static bool tryReduce(T&\
    \ test, const T& other) {\n    for (int i = N - 1; ~i; --i) {\n      if (other[i])\
    \ {\n        if (test[i]) return test ^= other, true;\n        break;\n      }\n\
    \    }\n    return false;\n  }\n  void apply(T& toApply) {\n    for(const T& b\
    \ : *this)\n      tryReduce(toApply, b);\n  }\n  pair<bool, vector<bool>> to(T\
    \ elem) {\n    vector<bool> res(SZ(*this));\n    F0R(i, SZ(*this))\n      res[i]\
    \ = tryReduce(elem, (*this)[i]);\n    return mp(elem.none(), res);\n  }\n  bool\
    \ isIn(T toCheck) {\n    apply(toCheck);\n    return toCheck.none();\n  }\n  bool\
    \ add(T toAdd) {\n    apply(toAdd);\n    if(toAdd.any()) this->pb(toAdd);\n  \
    \  return toAdd.any();\n  }\n  XorBase(const vector<T>& elems) {\n    for(const\
    \ auto& e : elems) add(e);\n  }\n  XorBase() {};\n};\n"
  code: "#include \"../template.hh\" // https://codeforces.com/blog/entry/68953\n\
    template<int N>\nstruct XorBase : vector<bitset<N>> {\n  using T = bitset<N>;\n\
    \  static bool tryReduce(T& test, const T& other) {\n    for (int i = N - 1; ~i;\
    \ --i) {\n      if (other[i]) {\n        if (test[i]) return test ^= other, true;\n\
    \        break;\n      }\n    }\n    return false;\n  }\n  void apply(T& toApply)\
    \ {\n    for(const T& b : *this)\n      tryReduce(toApply, b);\n  }\n  pair<bool,\
    \ vector<bool>> to(T elem) {\n    vector<bool> res(SZ(*this));\n    F0R(i, SZ(*this))\n\
    \      res[i] = tryReduce(elem, (*this)[i]);\n    return mp(elem.none(), res);\n\
    \  }\n  bool isIn(T toCheck) {\n    apply(toCheck);\n    return toCheck.none();\n\
    \  }\n  bool add(T toAdd) {\n    apply(toAdd);\n    if(toAdd.any()) this->pb(toAdd);\n\
    \    return toAdd.any();\n  }\n  XorBase(const vector<T>& elems) {\n    for(const\
    \ auto& e : elems) add(e);\n  }\n  XorBase() {};\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/XorBaseN.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/dataStructures/XorBaseN.cc
layout: document
redirect_from:
- /library/code/dataStructures/XorBaseN.cc
- /library/code/dataStructures/XorBaseN.cc.html
title: code/dataStructures/XorBaseN.cc
---
