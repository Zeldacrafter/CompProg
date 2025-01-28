---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  - icon: ':warning:'
    path: code/utils/y_combinator.cc
    title: code/utils/y_combinator.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.sciencedirect.com/science/article/pii/0024379580901627
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
    \ T>\n  explicit y_combinator_result(T&& fun) : f(forward<T>(fun)) {}\n  template<typename...\
    \ Args>\n  decltype(auto) operator()(Args&&... args) {\n    return f(ref(*this),\
    \ forward<Args>(args)...);\n  }\n};\ntemplate<typename F>\ndecltype(auto) y_combinator(F&&\
    \ f) {\n  return y_combinator_result<decay_t<F>>(forward<F>(f));\n}\n#line 2 \"\
    code/math/2vareqs.cc\"\n\n// Solving linear equation systems were every equation\
    \ has at most 2 variables.\n// Implemented the algorithm from the paper 'A Fast\
    \ Algorithm for Solving\n// Systems of Linear Equatlons with Two Variables per\
    \ Equation' by Bengt Aspvall\n// and Yossi Shiloach\n// https://www.sciencedirect.com/science/article/pii/0024379580901627\n\
    \ntemplate <typename T>\nstruct linear {  // a * x + c\n  T a, c;\n  linear()\
    \ : a{1}, c{0} {}\n  linear(const T& _a) : a{_a}, c{0} {}\n  linear(const T& _a,\
    \ const T& _c) : a{_a}, c{_c} {}\n  T operator()(const T& x) const { return calc(x);\
    \ }\n  T calc(const T& x) const { return a * x + c; }\n  linear combine(const\
    \ linear& o) {  // o(this(x))\n    return linear(o.a * a, o.a * c + o.c);\n  }\n\
    \  linear combine(const T& oa, const T& oc) {\n    return combine(linear(oa, oc));\n\
    \  }\n};\n\ntemplate <typename T>\nostream& operator<<(ostream& o, const linear<T>&\
    \ l) {\n  return o << l.a << \" * x + \" << l.c;\n}\n\ntemplate <>\nostream& operator<<(ostream&\
    \ o, const linear<int>& l) {\n  if (l.a == 0) return o << l.c;\n  return o <<\
    \ l.a << \" * x + \" << l.c;\n}\n\ntemplate <typename T>\nstruct eqsystem {\n\
    \  int n;\n  eqsystem(int _n) : n{_n} {}\n  using eq = tuple<T, int, T, int, T>;\
    \  // a * x + b * y = c\n  vector<eq> eqs;\n  auto add(T a, int x, T b, int y,\
    \ T c) -> void {\n    eqs.eb(a, x, b, y, c);\n  }\n  auto add(T a, int x, T c)\
    \ -> void { eqs.eb(0, x, a, x, c); }\n  auto print() -> void {\n    for (const\
    \ auto& [a, x, b, y, c] : eqs) {\n      cout << a << \" * x_\" << x << \" + \"\
    \ << b << \" * x_\" << y << \" = \"\n           << c << endl;\n    }\n  }\n  //\
    \ number of blocks,\n  // vector with entries:\n  //  - free variable or -1 if\
    \ fixed value\n  //  - linear<T> yielding the value depend on the free variable\n\
    \  auto solve() -> optional<pair<vi, vector<pair<int, linear<T>>>>> {\n    vvi\
    \ adj(n);\n    F0R (i, SZ(eqs)) {\n      const auto& [a, x, b, y, c] = eqs[i];\n\
    \      adj[x].pb(i);\n      adj[y].pb(i);\n    }\n    vector<optional<linear<T>>>\
    \ seen(n);\n    vi found;\n    optional<T> p;\n    auto dfs = y_combinator([&](auto\
    \ self, int v, linear<T> val) -> bool {\n      found.pb(v);\n      seen[v] = val;\n\
    \n      for (int i : adj[v]) {\n        auto [a, x, b, y, c] = eqs[i];\n     \
    \   if (v != x) {\n          swap(x, y);\n          swap(a, b);\n        }\n \
    \       // a * x + b * y = c  <=>  y = c/b - a/b * x\n        auto yval = val.combine(-a\
    \ / b, c / b);\n        if (seen[y]) {                 // consistency check\n\
    \          if (yval.a != seen[y]->a) {  // TODO: add equality function\n     \
    \       T pp = -(yval.c - seen[y]->c) /\n                   (yval.a - seen[y]->a);\
    \  // TODO: evil for int\n            if (p and *p != pp) {\n              dout\
    \ << \"two different values for free variable!\" << endl;\n              return\
    \ false;\n            }\n            p = pp;\n          } else if (yval.c != seen[y]->c)\
    \ {\n            dout << \"contradiction for x_\" << y << \"!\" << endl;\n   \
    \         return false;\n          }\n        } else {\n          if (not self(y,\
    \ yval)) return false;\n        }\n      }\n      return true;\n    });\n    vector<pair<int,\
    \ linear<T>>> sols(n, {-1, {}});\n    vi fr;\n    F0R (i, n) {\n      if (not\
    \ seen[i]) {\n        if (not dfs(i, linear<T>{})) return {};\n        if (not\
    \ p) fr.pb(i);\n        for (auto j : found) {\n          if (p) {\n         \
    \   sols[j] = {-1, linear<T>{0, (*seen[j])(*p)}};\n          } else {\n      \
    \      sols[j] = {i, *seen[j]};\n          }\n        }\n        p.reset();\n\
    \        found.clear();\n      }\n    }\n    return pair{fr, sols};\n  }\n};\n\
    \n"
  code: "#include \"../utils/y_combinator.cc\"\n\n// Solving linear equation systems\
    \ were every equation has at most 2 variables.\n// Implemented the algorithm from\
    \ the paper 'A Fast Algorithm for Solving\n// Systems of Linear Equatlons with\
    \ Two Variables per Equation' by Bengt Aspvall\n// and Yossi Shiloach\n// https://www.sciencedirect.com/science/article/pii/0024379580901627\n\
    \ntemplate <typename T>\nstruct linear {  // a * x + c\n  T a, c;\n  linear()\
    \ : a{1}, c{0} {}\n  linear(const T& _a) : a{_a}, c{0} {}\n  linear(const T& _a,\
    \ const T& _c) : a{_a}, c{_c} {}\n  T operator()(const T& x) const { return calc(x);\
    \ }\n  T calc(const T& x) const { return a * x + c; }\n  linear combine(const\
    \ linear& o) {  // o(this(x))\n    return linear(o.a * a, o.a * c + o.c);\n  }\n\
    \  linear combine(const T& oa, const T& oc) {\n    return combine(linear(oa, oc));\n\
    \  }\n};\n\ntemplate <typename T>\nostream& operator<<(ostream& o, const linear<T>&\
    \ l) {\n  return o << l.a << \" * x + \" << l.c;\n}\n\ntemplate <>\nostream& operator<<(ostream&\
    \ o, const linear<int>& l) {\n  if (l.a == 0) return o << l.c;\n  return o <<\
    \ l.a << \" * x + \" << l.c;\n}\n\ntemplate <typename T>\nstruct eqsystem {\n\
    \  int n;\n  eqsystem(int _n) : n{_n} {}\n  using eq = tuple<T, int, T, int, T>;\
    \  // a * x + b * y = c\n  vector<eq> eqs;\n  auto add(T a, int x, T b, int y,\
    \ T c) -> void {\n    eqs.eb(a, x, b, y, c);\n  }\n  auto add(T a, int x, T c)\
    \ -> void { eqs.eb(0, x, a, x, c); }\n  auto print() -> void {\n    for (const\
    \ auto& [a, x, b, y, c] : eqs) {\n      cout << a << \" * x_\" << x << \" + \"\
    \ << b << \" * x_\" << y << \" = \"\n           << c << endl;\n    }\n  }\n  //\
    \ number of blocks,\n  // vector with entries:\n  //  - free variable or -1 if\
    \ fixed value\n  //  - linear<T> yielding the value depend on the free variable\n\
    \  auto solve() -> optional<pair<vi, vector<pair<int, linear<T>>>>> {\n    vvi\
    \ adj(n);\n    F0R (i, SZ(eqs)) {\n      const auto& [a, x, b, y, c] = eqs[i];\n\
    \      adj[x].pb(i);\n      adj[y].pb(i);\n    }\n    vector<optional<linear<T>>>\
    \ seen(n);\n    vi found;\n    optional<T> p;\n    auto dfs = y_combinator([&](auto\
    \ self, int v, linear<T> val) -> bool {\n      found.pb(v);\n      seen[v] = val;\n\
    \n      for (int i : adj[v]) {\n        auto [a, x, b, y, c] = eqs[i];\n     \
    \   if (v != x) {\n          swap(x, y);\n          swap(a, b);\n        }\n \
    \       // a * x + b * y = c  <=>  y = c/b - a/b * x\n        auto yval = val.combine(-a\
    \ / b, c / b);\n        if (seen[y]) {                 // consistency check\n\
    \          if (yval.a != seen[y]->a) {  // TODO: add equality function\n     \
    \       T pp = -(yval.c - seen[y]->c) /\n                   (yval.a - seen[y]->a);\
    \  // TODO: evil for int\n            if (p and *p != pp) {\n              dout\
    \ << \"two different values for free variable!\" << endl;\n              return\
    \ false;\n            }\n            p = pp;\n          } else if (yval.c != seen[y]->c)\
    \ {\n            dout << \"contradiction for x_\" << y << \"!\" << endl;\n   \
    \         return false;\n          }\n        } else {\n          if (not self(y,\
    \ yval)) return false;\n        }\n      }\n      return true;\n    });\n    vector<pair<int,\
    \ linear<T>>> sols(n, {-1, {}});\n    vi fr;\n    F0R (i, n) {\n      if (not\
    \ seen[i]) {\n        if (not dfs(i, linear<T>{})) return {};\n        if (not\
    \ p) fr.pb(i);\n        for (auto j : found) {\n          if (p) {\n         \
    \   sols[j] = {-1, linear<T>{0, (*seen[j])(*p)}};\n          } else {\n      \
    \      sols[j] = {i, *seen[j]};\n          }\n        }\n        p.reset();\n\
    \        found.clear();\n      }\n    }\n    return pair{fr, sols};\n  }\n};\n\
    \n"
  dependsOn:
  - code/utils/y_combinator.cc
  - code/template.cc
  isVerificationFile: false
  path: code/math/2vareqs.cc
  requiredBy: []
  timestamp: '2022-05-09 15:34:21+02:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/math/2vareqs.cc
layout: document
redirect_from:
- /library/code/math/2vareqs.cc
- /library/code/math/2vareqs.cc.html
title: code/math/2vareqs.cc
---
