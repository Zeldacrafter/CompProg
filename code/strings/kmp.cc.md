---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/kmp.string_matches.test.cpp
    title: tests/aoj/kmp.string_matches.test.cpp
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << \"] \"\n#line 2 \"code/strings/kmp.cc\"\nvi preprocess(string& s) {\n  vi\
    \ fail(SZ(s) + 1);\n  fail[0] = -1;\n  for (int i = 0, j = -1; i < SZ(s);) {\n\
    \    while (j >= 0 && s[i] != s[j]) j = fail[j];\n    ++i, ++j;\n    fail[i] =\
    \ j;\n  }\n  return fail;\n}\nvi match(string& text, string& pattern) {\n  vi\
    \ matches, fail(preprocess(pattern));\n  for (int i = 0, j = 0; i < SZ(text);)\
    \ {\n    while (j >= 0 && text[i] != pattern[j]) j = fail[j];\n    ++i; ++j;\n\
    \    if (j == SZ(pattern)) {\n      matches.pb(i - j);\n      j = fail[j];\n \
    \   }\n  }\n  return matches;\n}\n"
  code: "#include \"../template.hh\"\nvi preprocess(string& s) {\n  vi fail(SZ(s)\
    \ + 1);\n  fail[0] = -1;\n  for (int i = 0, j = -1; i < SZ(s);) {\n    while (j\
    \ >= 0 && s[i] != s[j]) j = fail[j];\n    ++i, ++j;\n    fail[i] = j;\n  }\n \
    \ return fail;\n}\nvi match(string& text, string& pattern) {\n  vi matches, fail(preprocess(pattern));\n\
    \  for (int i = 0, j = 0; i < SZ(text);) {\n    while (j >= 0 && text[i] != pattern[j])\
    \ j = fail[j];\n    ++i; ++j;\n    if (j == SZ(pattern)) {\n      matches.pb(i\
    \ - j);\n      j = fail[j];\n    }\n  }\n  return matches;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/strings/kmp.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/kmp.string_matches.test.cpp
documentation_of: code/strings/kmp.cc
layout: document
redirect_from:
- /library/code/strings/kmp.cc
- /library/code/strings/kmp.cc.html
title: code/strings/kmp.cc
---
