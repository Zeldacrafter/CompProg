---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"tests/yosupo/many_aplusb.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/many_aplusb\"\n\n#line 1 \"code/template.cc\"\n\
    // this line is here for a reason\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef\
    \ vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define\
    \ fi first\n#define se second\n#define eb emplace_back\n#define pb push_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define endl '\\n'\n#define ALL(x)\
    \ (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x)\
    \ (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))\n\
    #define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T& a, const\
    \ T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\nbool ckmax(T&\
    \ a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef DEBUG\n#define\
    \ DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__\
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 4 \"tests/yosupo/many_aplusb.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int t;\n\
    \  cin >> t;\n\n  while(t--) {\n    ll a, b;\n    cin >> a >> b;\n    cout <<\
    \ a + b << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ \"../../code/template.cc\"\n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\
    \n  int t;\n  cin >> t;\n\n  while(t--) {\n    ll a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << endl;\n  }\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/many_aplusb.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/many_aplusb.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/many_aplusb.test.cpp
- /verify/tests/yosupo/many_aplusb.test.cpp.html
title: tests/yosupo/many_aplusb.test.cpp
---