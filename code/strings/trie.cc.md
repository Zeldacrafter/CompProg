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
    \ << \"] \"\n#line 2 \"code/strings/trie.cc\"\ntemplate <typename T, int E = 26,\
    \ typename V = char, V base = 'a'>\nstruct Trie {\n  using str = basic_string<V>;\n\
    \  vector<array<int, E>> nxt;\n  vector<T> v;\n  Trie() : nxt{array<int, E>{}},\
    \ v(1, -1) {}\n  void set(const str& s, T val) {\n    int it = 0;\n    for (V\
    \ c : s) {\n      if (!nxt[it][c - base]) {\n        nxt[it][c - base] = SZ(nxt);\n\
    \        nxt.eb();\n        v.eb();\n      }\n      it = nxt[it][c - base];\n\
    \    }\n    v[it] = val;\n  }\n  T get(const str& s) {\n    int it = 0;\n    for\
    \ (V c : s) {\n      if (!nxt[it][c - base]) return T();\n      it = nxt[it][c\
    \ - base];\n    }\n    return v[it];\n  }\n};\n"
  code: "#include \"../template.hh\"\ntemplate <typename T, int E = 26, typename V\
    \ = char, V base = 'a'>\nstruct Trie {\n  using str = basic_string<V>;\n  vector<array<int,\
    \ E>> nxt;\n  vector<T> v;\n  Trie() : nxt{array<int, E>{}}, v(1, -1) {}\n  void\
    \ set(const str& s, T val) {\n    int it = 0;\n    for (V c : s) {\n      if (!nxt[it][c\
    \ - base]) {\n        nxt[it][c - base] = SZ(nxt);\n        nxt.eb();\n      \
    \  v.eb();\n      }\n      it = nxt[it][c - base];\n    }\n    v[it] = val;\n\
    \  }\n  T get(const str& s) {\n    int it = 0;\n    for (V c : s) {\n      if\
    \ (!nxt[it][c - base]) return T();\n      it = nxt[it][c - base];\n    }\n   \
    \ return v[it];\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/strings/trie.cc
  requiredBy: []
  timestamp: '2020-10-29 00:10:29+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/strings/trie.cc
layout: document
redirect_from:
- /library/code/strings/trie.cc
- /library/code/strings/trie.cc.html
title: code/strings/trie.cc
---
