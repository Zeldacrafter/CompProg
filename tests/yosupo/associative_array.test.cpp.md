---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"tests/yosupo/associative_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line 1 \"code/template.cc\"\
    \n// this line is here for a reason\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef pair<int, int> ii;\ntypedef vector<int>\
    \ vi;\ntypedef vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii> vvii;\n\
    #define fi first\n#define se second\n#define eb emplace_back\n#define pb push_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define endl '\\n'\n#define ALL(x)\
    \ (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x)\
    \ (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))\n\
    #define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T& a, const\
    \ T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\nbool ckmax(T&\
    \ a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef DEBUG\n#define\
    \ DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__\
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 4 \"tests/yosupo/associative_array.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int q;\n\
    \  cin >> q;\n\n  map<ll, ll> arr;\n  while(q--) {\n    bool c;\n    cin >> c;\n\
    \    if(!c) {\n      ll k, v;\n      cin >> k >> v;\n      arr[k] = v;\n    }\
    \ else {\n      ll k;\n      cin >> k;\n      cout << arr[k] << endl;\n    }\n\
    \  }\n}\n\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../code/template.cc\"\n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\
    \n  int q;\n  cin >> q;\n\n  map<ll, ll> arr;\n  while(q--) {\n    bool c;\n \
    \   cin >> c;\n    if(!c) {\n      ll k, v;\n      cin >> k >> v;\n      arr[k]\
    \ = v;\n    } else {\n      ll k;\n      cin >> k;\n      cout << arr[k] << endl;\n\
    \    }\n  }\n}\n\n\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/associative_array.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/associative_array.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/associative_array.test.cpp
- /verify/tests/yosupo/associative_array.test.cpp.html
title: tests/yosupo/associative_array.test.cpp
---
