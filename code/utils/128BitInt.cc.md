---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ << \"] \"\n#line 2 \"code/utils/128BitInt.cc\"\nostream& operator<<(ostream&\
    \ o, __int128_t n) {\n  if (n < 0) {\n    o << '-';\n    n *= -1;\n  }\n  ll mod\
    \ = 1e18;\n  string s;\n  do {\n    unsigned long long digits = n % mod;\n   \
    \ string dStr = to_string(digits);\n    if (digits != n)\n      s = string(18\
    \ - dStr.length(), '0') + dStr + s;\n    else\n      s = dStr + s;\n    n = (n\
    \ - digits) / mod;\n  } while (n);\n  return o << s;\n}\n"
  code: "#include \"../template.hh\"\nostream& operator<<(ostream& o, __int128_t n)\
    \ {\n  if (n < 0) {\n    o << '-';\n    n *= -1;\n  }\n  ll mod = 1e18;\n  string\
    \ s;\n  do {\n    unsigned long long digits = n % mod;\n    string dStr = to_string(digits);\n\
    \    if (digits != n)\n      s = string(18 - dStr.length(), '0') + dStr + s;\n\
    \    else\n      s = dStr + s;\n    n = (n - digits) / mod;\n  } while (n);\n\
    \  return o << s;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/utils/128BitInt.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/utils/128BitInt.cc
layout: document
redirect_from:
- /library/code/utils/128BitInt.cc
- /library/code/utils/128BitInt.cc.html
title: code/utils/128BitInt.cc
---
