---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
    - https://stackoverflow.com/a/40873657
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
    \ << \"] \"\n#line 2 \"code/utils/y_combinator.cc\"\n// for c++14 and above; \
    \ explicitly specify the return type of the lambda\n// links:\n//  1. https://stackoverflow.com/a/40873657\n\
    //  2. http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html\n\
    template<typename F>\nstruct y_combinator_result {\n  F f;\n  template<typename\
    \ T>\n  explicit y_combinator_result(T&& fun): f(forward<T>(fun)) {}\n  template<typename...\
    \ Args>\n  decltype(auto) operator()(Args&&... args) {\n    return f(ref(*this),\
    \ forward<Args>(args)...);\n  }\n};\ntemplate<typename F>\ndecltype(auto) y_combinator(F&&\
    \ f) {\n  return y_combinator_result<decay_t<F>>(forward<F>(f));\n}\n"
  code: "#include \"../template.hh\"\n// for c++14 and above;  explicitly specify\
    \ the return type of the lambda\n// links:\n//  1. https://stackoverflow.com/a/40873657\n\
    //  2. http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html\n\
    template<typename F>\nstruct y_combinator_result {\n  F f;\n  template<typename\
    \ T>\n  explicit y_combinator_result(T&& fun): f(forward<T>(fun)) {}\n  template<typename...\
    \ Args>\n  decltype(auto) operator()(Args&&... args) {\n    return f(ref(*this),\
    \ forward<Args>(args)...);\n  }\n};\ntemplate<typename F>\ndecltype(auto) y_combinator(F&&\
    \ f) {\n  return y_combinator_result<decay_t<F>>(forward<F>(f));\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/utils/y_combinator.cc
  requiredBy: []
  timestamp: '2020-11-16 16:00:31+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/utils/y_combinator.cc
layout: document
redirect_from:
- /library/code/utils/y_combinator.cc
- /library/code/utils/y_combinator.cc.html
title: code/utils/y_combinator.cc
---
