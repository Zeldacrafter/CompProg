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
    \ << \"] \"\n#line 2 \"code/strings/manachers.cc\"\nvi manacher(string s) {\n\
    \  string T = \"#\";   // Assume that '#' is not in the alphabet\n  for (char\
    \ c : s) T += c, T += '#';\n  vi P(SZ(T));\n  int c = 0, R = 0;\n  FOR (i, 1,\
    \ SZ(T) - 1) {\n    if (R > i) P[i] = min(R - i, P[2 * c - i]);\n    for (int\
    \ r = i + 1 + P[i], l = i - 1 - P[i];\n         r < SZ(T) && l >= 0 && T[l] ==\
    \ T[r]; l--, r++)\n      P[i]++;\n    if (i + P[i] > R) c = i, R = i + P[i];\n\
    \  }\n  return P;\n}\n"
  code: "#include \"../template.hh\"\nvi manacher(string s) {\n  string T = \"#\"\
    ;   // Assume that '#' is not in the alphabet\n  for (char c : s) T += c, T +=\
    \ '#';\n  vi P(SZ(T));\n  int c = 0, R = 0;\n  FOR (i, 1, SZ(T) - 1) {\n    if\
    \ (R > i) P[i] = min(R - i, P[2 * c - i]);\n    for (int r = i + 1 + P[i], l =\
    \ i - 1 - P[i];\n         r < SZ(T) && l >= 0 && T[l] == T[r]; l--, r++)\n   \
    \   P[i]++;\n    if (i + P[i] > R) c = i, R = i + P[i];\n  }\n  return P;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/strings/manachers.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/strings/manachers.cc
layout: document
redirect_from:
- /library/code/strings/manachers.cc
- /library/code/strings/manachers.cc.html
title: code/strings/manachers.cc
---
