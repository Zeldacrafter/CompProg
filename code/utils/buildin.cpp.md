---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "code/template.cc"

    // this line is here for a reason

    #include <bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    typedef pair<int, int> ii;

    typedef vector<int> vi;

    typedef vector<ii> vii;

    typedef vector<vi> vvi;

    typedef vector<vii> vvii;

    #define fi first

    #define se second

    #define eb emplace_back

    #define pb push_back

    #define mp make_pair

    #define mt make_tuple

    #define endl ''\n''

    #define ALL(x) (x).begin(), (x).end()

    #define RALL(x) (x).rbegin(), (x).rend()

    #define SZ(x) (int)(x).size()

    #define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))

    #define F0R(a, b) FOR (a, 0, (b))

    template <typename T>

    bool ckmin(T& a, const T& b) { return a > b ? a = b, true : false; }

    template <typename T>

    bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

    #ifndef DEBUG

    #define DEBUG 0

    #endif

    #define dout if (DEBUG) cerr

    #define dvar(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

    #line 2 "code/utils/buildin.cpp"

    // Returns one plus the index of the least significant 1-bit of x, or

    // if x is zero, returns zero.

    int __builtin_ffs(unsigned int x);

    int __builtin_clz(unsigned int x); // count leading zeroes

    int __builtin_ctz(unsigned int x); // count trailing zeroes

    int __builtin_popcount(unsigned int x); // count set one bits

    // unsigned long: Postfix ''l'', unsigned long long: Postfix ''ll''


    // Rotate bits of x (left|right) by n places.

    unsigned int rotl(unsigned int x, int n);

    unsigned int rotr(unsigned int x, int n);

    '
  code: '#include "../template.cc" // cpp file because this file does not compile
    (more than one definition)

    // Returns one plus the index of the least significant 1-bit of x, or

    // if x is zero, returns zero.

    int __builtin_ffs(unsigned int x);

    int __builtin_clz(unsigned int x); // count leading zeroes

    int __builtin_ctz(unsigned int x); // count trailing zeroes

    int __builtin_popcount(unsigned int x); // count set one bits

    // unsigned long: Postfix ''l'', unsigned long long: Postfix ''ll''


    // Rotate bits of x (left|right) by n places.

    unsigned int rotl(unsigned int x, int n);

    unsigned int rotr(unsigned int x, int n);

    '
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/utils/buildin.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/utils/buildin.cpp
layout: document
redirect_from:
- /library/code/utils/buildin.cpp
- /library/code/utils/buildin.cpp.html
title: code/utils/buildin.cpp
---
