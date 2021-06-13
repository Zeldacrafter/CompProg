---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"code/math/combinatorics.cc\"\n/*\n *\n */\n#line 1 \"code/template.cc\"\
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
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 5 \"code/math/combinatorics.cc\"\n\n\
    template<typename T>\nstruct Combinatorics {\n    static vector<T> facs, der;\n\
    \    static vector<vector<T>> ch, eul, stir1, stir2;\n\n    static void precompFac(int\
    \ maxN) { fac(maxN); }\n\n    static T fac(int n) {\n        facs.reserve(n +\
    \ 1);\n        if(!SZ(facs)) facs.pb(1);\n        while(SZ(facs) <= n) facs.pb(facs.back()\
    \ * SZ(facs));\n        return facs[n];\n    }\n\n    static void precompChoose(int\
    \ maxN) {\n        int oldN = SZ(ch);\n        ch.resize(max(oldN, maxN)); \n\
    \        if(!oldN) ch[0].pb(1);\n        FOR(n, oldN + 1, maxN + 1) {\n      \
    \      ch[n].reserve(n + 1);\n            ch[n].pb(1);\n            FOR(k, 1,\
    \ n)\n                ch[n].pb(ch[n - 1][k - 1] + ch[n - 1][k]);\n           \
    \ ch[n].pb(1);\n        }\n    }\n\n    static T choose(int n, int k) {\n    \
    \    assert(n >= k);\n        if(SZ(ch) >= n) return ch[n][k];\n        if(SZ(facs)\
    \ >= n) return facs[n]/(facs[n - k]*facs[k]);\n        T res = 1;\n        FOR(i,\
    \ n - k + 1, n + 1) res *= i;\n        FOR(i, 2, k + 1) res /= i;\n        return\
    \ res;\n    }\n\n    static T catalan(int n) {\n        return choose(2*n, n)/(n\
    \ + 1);\n    }\n\n    static T precompEuler(int maxN) {\n        int oldN = SZ(eul);\n\
    \        eul.resize(max(oldN, maxN + 1));\n        if(!oldN) eul[0].pb(1);\n \
    \       FOR(n, oldN + 1, maxN + 1) {\n            eul[n].reserve(n + 1);\n   \
    \         eul[n].pb(1);\n            FOR(k, 1, n)\n                eul[n].pb(k*eul[n\
    \ - 1][k] + (n - k + 1)*eul[n - 1][k - 1]);\n            eul[n].pb(1);\n     \
    \   }\n    }\n\n    static T euler(int n, int k) {\n        assert(n >= k);\n\
    \        if(SZ(eul) <= n) precompEuler(n);\n        return eul[n][k];\n    }\n\
    \n    static void precompStirling1(int maxN) {\n        int oldN = SZ(stir1);\n\
    \        stir1.resize(max(oldN, maxN + 1));\n        if(!oldN) stir1[0].pb(1);\n\
    \        FOR(n, 1, maxN + 1) {\n            stir1[n].reserve(n + 1);\n       \
    \     stir1[n].pb(0);\n            FOR(k, 1, n)\n                stir1[n].pb(stir1[n\
    \ - 1][k - 1] + (n - 1)*stir1[n - 1][k]);\n            stir1[n].pb(1);\n     \
    \   }\n    }\n\n    static T stirling1(int n, int k) {\n        assert(n >= k);\n\
    \        if(SZ(stir1) <= n) precompStirling1(n);\n        return stir1[n][k];\n\
    \    }\n\n    static void precompStirling2(int maxN) {\n        int oldN = SZ(stir2);\n\
    \        stir2.resize(max(oldN, maxN + 1));\n        if(!oldN) stir2[0].pb(1);\n\
    \        FOR(n, 1, maxN + 1) {\n            stir2[n].reserve(n + 1);\n       \
    \     stir2[n].pb(0);\n            FOR(k, 1, n)\n                stir2[n].pb(stir2[n\
    \ - 1][k - 1] + k*stir2[n - 1][k]);\n            stir2[n].pb(1);\n        }\n\
    \    }\n\n    static T stirling2(int n, int k) {\n        if(SZ(stir2) <= n) precompStirling2(n);\n\
    \        return stir2[n][k];\n    }\n\n    static void precompDerangements(int\
    \ maxN) {\n        if(!SZ(der)) {\n            der.pb(1);\n            der.pb(0);\n\
    \        }\n        der.reserve(maxN + 1);\n        while(SZ(der) <= maxN) {\n\
    \            int n = SZ(der);\n            der.pb(n*(der[n - 1] + der[n - 2]));\n\
    \        }\n    }\n\n    static T derangements(int n) {\n        if(SZ(der) <=\
    \ n) precompDerangements(n);\n        return der[n];\n    }\n}; \n\nusing comb\
    \ = Combinatorics<ll>;\n"
  code: "/*\n *\n */\n#include \"../template.hh\"\n\ntemplate<typename T>\nstruct\
    \ Combinatorics {\n    static vector<T> facs, der;\n    static vector<vector<T>>\
    \ ch, eul, stir1, stir2;\n\n    static void precompFac(int maxN) { fac(maxN);\
    \ }\n\n    static T fac(int n) {\n        facs.reserve(n + 1);\n        if(!SZ(facs))\
    \ facs.pb(1);\n        while(SZ(facs) <= n) facs.pb(facs.back() * SZ(facs));\n\
    \        return facs[n];\n    }\n\n    static void precompChoose(int maxN) {\n\
    \        int oldN = SZ(ch);\n        ch.resize(max(oldN, maxN)); \n        if(!oldN)\
    \ ch[0].pb(1);\n        FOR(n, oldN + 1, maxN + 1) {\n            ch[n].reserve(n\
    \ + 1);\n            ch[n].pb(1);\n            FOR(k, 1, n)\n                ch[n].pb(ch[n\
    \ - 1][k - 1] + ch[n - 1][k]);\n            ch[n].pb(1);\n        }\n    }\n\n\
    \    static T choose(int n, int k) {\n        assert(n >= k);\n        if(SZ(ch)\
    \ >= n) return ch[n][k];\n        if(SZ(facs) >= n) return facs[n]/(facs[n - k]*facs[k]);\n\
    \        T res = 1;\n        FOR(i, n - k + 1, n + 1) res *= i;\n        FOR(i,\
    \ 2, k + 1) res /= i;\n        return res;\n    }\n\n    static T catalan(int\
    \ n) {\n        return choose(2*n, n)/(n + 1);\n    }\n\n    static T precompEuler(int\
    \ maxN) {\n        int oldN = SZ(eul);\n        eul.resize(max(oldN, maxN + 1));\n\
    \        if(!oldN) eul[0].pb(1);\n        FOR(n, oldN + 1, maxN + 1) {\n     \
    \       eul[n].reserve(n + 1);\n            eul[n].pb(1);\n            FOR(k,\
    \ 1, n)\n                eul[n].pb(k*eul[n - 1][k] + (n - k + 1)*eul[n - 1][k\
    \ - 1]);\n            eul[n].pb(1);\n        }\n    }\n\n    static T euler(int\
    \ n, int k) {\n        assert(n >= k);\n        if(SZ(eul) <= n) precompEuler(n);\n\
    \        return eul[n][k];\n    }\n\n    static void precompStirling1(int maxN)\
    \ {\n        int oldN = SZ(stir1);\n        stir1.resize(max(oldN, maxN + 1));\n\
    \        if(!oldN) stir1[0].pb(1);\n        FOR(n, 1, maxN + 1) {\n          \
    \  stir1[n].reserve(n + 1);\n            stir1[n].pb(0);\n            FOR(k, 1,\
    \ n)\n                stir1[n].pb(stir1[n - 1][k - 1] + (n - 1)*stir1[n - 1][k]);\n\
    \            stir1[n].pb(1);\n        }\n    }\n\n    static T stirling1(int n,\
    \ int k) {\n        assert(n >= k);\n        if(SZ(stir1) <= n) precompStirling1(n);\n\
    \        return stir1[n][k];\n    }\n\n    static void precompStirling2(int maxN)\
    \ {\n        int oldN = SZ(stir2);\n        stir2.resize(max(oldN, maxN + 1));\n\
    \        if(!oldN) stir2[0].pb(1);\n        FOR(n, 1, maxN + 1) {\n          \
    \  stir2[n].reserve(n + 1);\n            stir2[n].pb(0);\n            FOR(k, 1,\
    \ n)\n                stir2[n].pb(stir2[n - 1][k - 1] + k*stir2[n - 1][k]);\n\
    \            stir2[n].pb(1);\n        }\n    }\n\n    static T stirling2(int n,\
    \ int k) {\n        if(SZ(stir2) <= n) precompStirling2(n);\n        return stir2[n][k];\n\
    \    }\n\n    static void precompDerangements(int maxN) {\n        if(!SZ(der))\
    \ {\n            der.pb(1);\n            der.pb(0);\n        }\n        der.reserve(maxN\
    \ + 1);\n        while(SZ(der) <= maxN) {\n            int n = SZ(der);\n    \
    \        der.pb(n*(der[n - 1] + der[n - 2]));\n        }\n    }\n\n    static\
    \ T derangements(int n) {\n        if(SZ(der) <= n) precompDerangements(n);\n\
    \        return der[n];\n    }\n}; \n\nusing comb = Combinatorics<ll>;\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/math/combinatorics.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/math/combinatorics.cc
layout: document
redirect_from:
- /library/code/math/combinatorics.cc
- /library/code/math/combinatorics.cc.html
title: code/math/combinatorics.cc
---
