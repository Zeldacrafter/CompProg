---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/strings/kmp.cc
    title: code/strings/kmp.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"tests/aoj/kmp.string_matches.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #line 1 \"code/template.cc\"\n// this line is here for a reason\n#include <bits/stdc++.h>\n\
    using namespace std;\ntypedef long long ll;\ntypedef pair<int, int> ii;\ntypedef\
    \ vector<int> vi;\ntypedef vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii>\
    \ vvii;\n#define fi first\n#define se second\n#define eb emplace_back\n#define\
    \ pb push_back\n#define mp make_pair\n#define mt make_tuple\n#define endl '\\\
    n'\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n\
    #define SZ(x) (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c);\
    \ ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T&\
    \ a, const T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\n\
    bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef\
    \ DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...)\
    \ \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/strings/kmp.cc\"\
    \nvi preprocess(string& s) {\n  vi fail(SZ(s) + 1);\n  fail[0] = -1;\n  for (int\
    \ i = 0, j = -1; i < SZ(s);) {\n    while (j >= 0 && s[i] != s[j]) j = fail[j];\n\
    \    ++i, ++j;\n    fail[i] = j;\n  }\n  return fail;\n}\nvi match(string& text,\
    \ string& pattern) {\n  vi matches, fail(preprocess(pattern));\n  for (int i =\
    \ 0, j = 0; i < SZ(text);) {\n    while (j >= 0 && text[i] != pattern[j]) j =\
    \ fail[j];\n    ++i; ++j;\n    if (j == SZ(pattern)) {\n      matches.pb(i - j);\n\
    \      j = fail[j];\n    }\n  }\n  return matches;\n}\n#line 4 \"tests/aoj/kmp.string_matches.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  string s,\
    \ s2;\n  cin >> s >> s2;\n\n  vi res = match(s, s2);\n  for(int i : res)\n   \
    \   cout << i << endl;\n}\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"../../code/strings/kmp.cc\"\n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\
    \n  string s, s2;\n  cin >> s >> s2;\n\n  vi res = match(s, s2);\n  for(int i\
    \ : res)\n      cout << i << endl;\n}\n\n\n\n"
  dependsOn:
  - code/strings/kmp.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/kmp.string_matches.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 10:58:30+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/kmp.string_matches.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/kmp.string_matches.test.cpp
- /verify/tests/aoj/kmp.string_matches.test.cpp.html
title: tests/aoj/kmp.string_matches.test.cpp
---
