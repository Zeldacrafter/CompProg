---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy:
  - icon: ':warning:'
    path: code/dataStructures/WLM.cc
    title: code/dataStructures/WLM.cc
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
    \ << \"] \"\n#line 2 \"code/dataStructures/BV.cc\"\ntemplate <typename T>\nstruct\
    \ BV {\n  static constexpr int sz = sizeof(T) * 8;\n  struct BLK {\n    T bits\
    \ = 0;\n    int sum = 0;\n    int rank() { return __builtin_popcountll(bits);\
    \ }\n    int rank(int i) {\n      return __builtin_popcountll(bits & (((T)1 <<\
    \ i) - (T)1));\n    }\n  };\n  vector<BLK> data;\n  void resize(int n) { data.resize(n\
    \ / sz + 1); }\n  int rank1(int idx) { // ones in [0, idx)\n    return data[idx\
    \ / sz].sum + data[idx / sz].rank(idx % sz);\n  }\n  int rank0(int idx) { return\
    \ idx - rank1(idx); } // zeroes in [0, idx)\n  void set(int i) { data[i / sz].bits\
    \ |= (T)1 << (i % sz); }\n  int get(int i) { return data[i / sz].bits >> (i %\
    \ sz) & 1; }\n  void build() {\n    data[0].sum = 0;\n    FOR (i, 1, SZ(data))\n\
    \      data[i].sum = data[i - 1].sum + data[i - 1].rank();\n  }\n};\n"
  code: "#include \"../template.cc\"\ntemplate <typename T>\nstruct BV {\n  static\
    \ constexpr int sz = sizeof(T) * 8;\n  struct BLK {\n    T bits = 0;\n    int\
    \ sum = 0;\n    int rank() { return __builtin_popcountll(bits); }\n    int rank(int\
    \ i) {\n      return __builtin_popcountll(bits & (((T)1 << i) - (T)1));\n    }\n\
    \  };\n  vector<BLK> data;\n  void resize(int n) { data.resize(n / sz + 1); }\n\
    \  int rank1(int idx) { // ones in [0, idx)\n    return data[idx / sz].sum + data[idx\
    \ / sz].rank(idx % sz);\n  }\n  int rank0(int idx) { return idx - rank1(idx);\
    \ } // zeroes in [0, idx)\n  void set(int i) { data[i / sz].bits |= (T)1 << (i\
    \ % sz); }\n  int get(int i) { return data[i / sz].bits >> (i % sz) & 1; }\n \
    \ void build() {\n    data[0].sum = 0;\n    FOR (i, 1, SZ(data))\n      data[i].sum\
    \ = data[i - 1].sum + data[i - 1].rank();\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/BV.cc
  requiredBy:
  - code/dataStructures/WLM.cc
  timestamp: '2020-12-19 23:25:36+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/dataStructures/BV.cc
layout: document
redirect_from:
- /library/code/dataStructures/BV.cc
- /library/code/dataStructures/BV.cc.html
title: code/dataStructures/BV.cc
---
