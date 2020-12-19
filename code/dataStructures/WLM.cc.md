---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: code/dataStructures/BV.cc
    title: code/dataStructures/BV.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \      data[i].sum = data[i - 1].sum + data[i - 1].rank();\n  }\n};\n#line 2 \"\
    code/dataStructures/WLM.cc\"\ntemplate<typename T = int>\nstruct WLM {\n  static\
    \ inline int bit(T n, int i) { return n >> i & 1; }\n  T H;\n  vector<BV<uint64_t>>\
    \ bvs;\n  vi zs;\n  WLM(vector<T> v, T hi) : H{64 - __builtin_clzll(hi)}, bvs(H),\
    \ zs(H) {\n    int n = SZ(v);\n    for (int h = H - 1; ~h; --h) {\n      bvs[h].resize(n);\n\
    \      F0R (i, n) if (bit(v[i], h)) bvs[h].set(i); \n      bvs[h].build();\n \
    \     auto it = stable_partition(ALL(v), [=](T i){ return !bit(i, h); });\n  \
    \    zs[h] = distance(v.begin(), it);\n    }\n  }\n  T kthsmallest(int l, int\
    \ r, int k) { // k-th smallest in [l, r)\n    T lo = 0, hi = (T)1 << H;\n    for\
    \ (int h = H - 1; ~h; --h) {\n      int have = bvs[h].rank0(r) - bvs[h].rank0(l);\n\
    \      if (k < have) {\n        hi -= (T)1 << h;\n        l = bvs[h].rank0(l);\
    \ r = bvs[h].rank0(r);\n      } else {\n        lo += (T)1 << h; k -= have;\n\
    \        l = zs[h] + bvs[h].rank1(l); r = zs[h] + bvs[h].rank1(r);\n      }\n\
    \    }\n    return lo;\n  }\n  int greater(int l, int r, int k) { // elements\
    \ >= k in [l, r)\n    T lo = 0, hi = (T)1 << H;\n    int ans = 0;\n    for (int\
    \ h = H - 1; ~h; --h) {\n      T d = (T)1 << h;\n      if (k <= lo + d) {\n  \
    \      hi -= d;\n        ans += bvs[h].rank1(r) - bvs[h].rank1(l);\n        l\
    \ = bvs[h].rank0(l); r = bvs[h].rank0(r);\n      } else {\n        lo += d;\n\
    \        l = zs[h] + bvs[h].rank1(l); r = zs[h] + bvs[h].rank1(r);\n      }\n\
    \    }\n    return ans;\n  };\n};\n"
  code: "#include \"BV.cc\"\ntemplate<typename T = int>\nstruct WLM {\n  static inline\
    \ int bit(T n, int i) { return n >> i & 1; }\n  T H;\n  vector<BV<uint64_t>> bvs;\n\
    \  vi zs;\n  WLM(vector<T> v, T hi) : H{64 - __builtin_clzll(hi)}, bvs(H), zs(H)\
    \ {\n    int n = SZ(v);\n    for (int h = H - 1; ~h; --h) {\n      bvs[h].resize(n);\n\
    \      F0R (i, n) if (bit(v[i], h)) bvs[h].set(i); \n      bvs[h].build();\n \
    \     auto it = stable_partition(ALL(v), [=](T i){ return !bit(i, h); });\n  \
    \    zs[h] = distance(v.begin(), it);\n    }\n  }\n  T kthsmallest(int l, int\
    \ r, int k) { // k-th smallest in [l, r)\n    T lo = 0, hi = (T)1 << H;\n    for\
    \ (int h = H - 1; ~h; --h) {\n      int have = bvs[h].rank0(r) - bvs[h].rank0(l);\n\
    \      if (k < have) {\n        hi -= (T)1 << h;\n        l = bvs[h].rank0(l);\
    \ r = bvs[h].rank0(r);\n      } else {\n        lo += (T)1 << h; k -= have;\n\
    \        l = zs[h] + bvs[h].rank1(l); r = zs[h] + bvs[h].rank1(r);\n      }\n\
    \    }\n    return lo;\n  }\n  int greater(int l, int r, int k) { // elements\
    \ >= k in [l, r)\n    T lo = 0, hi = (T)1 << H;\n    int ans = 0;\n    for (int\
    \ h = H - 1; ~h; --h) {\n      T d = (T)1 << h;\n      if (k <= lo + d) {\n  \
    \      hi -= d;\n        ans += bvs[h].rank1(r) - bvs[h].rank1(l);\n        l\
    \ = bvs[h].rank0(l); r = bvs[h].rank0(r);\n      } else {\n        lo += d;\n\
    \        l = zs[h] + bvs[h].rank1(l); r = zs[h] + bvs[h].rank1(r);\n      }\n\
    \    }\n    return ans;\n  };\n};\n"
  dependsOn:
  - code/dataStructures/BV.cc
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/WLM.cc
  requiredBy: []
  timestamp: '2020-12-19 23:25:36+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/dataStructures/WLM.cc
layout: document
redirect_from:
- /library/code/dataStructures/WLM.cc
- /library/code/dataStructures/WLM.cc.html
title: code/dataStructures/WLM.cc
---
