---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy:
  - icon: ':warning:'
    path: code/utils/stresstestbigint.cc
    title: code/utils/stresstestbigint.cc
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/bigint.addition_bigint.test.cpp
    title: tests/aoj/bigint.addition_bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/bigint.multiplication_bigint_1.test.cpp
    title: tests/aoj/bigint.multiplication_bigint_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/bigint.multiplication_bigint_2.test.cpp
    title: tests/aoj/bigint.multiplication_bigint_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/aoj/bigint.subtraction_bigint.test.cpp
    title: tests/aoj/bigint.subtraction_bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/hackerrank/aho_corasick.two_two.test.cpp
    title: tests/hackerrank/aho_corasick.two_two.test.cpp
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
    \ << \"] \"\n#line 2 \"code/utils/bigint.cc\"\ntemplate <class T>\nint sign(T\
    \ a) {\n  return (a > 0) - (0 > a);\n}\nusing vll = vector<ll>;\nusing vit = vll::const_iterator;\n\
    struct bigint {\n  static const ll base = 1e9;\n  int signum;\n  vll mag;\n  bigint()\
    \ : signum(0), mag() {}\n  bigint(ll val) : signum(sign(val)), mag() {\n    val\
    \ = abs(val);\n    while (val) mag.pb(val % base), val /= base;\n  }\n  bigint(int\
    \ sig, vll&& m) : signum(sig), mag(m) {\n    if (!sig) mag.clear();\n    trim();\n\
    \  }\n  bigint(string s) {\n    if (s.empty() || s == \"0\")\n      signum = 0;\n\
    \    else {\n      signum = s[0] == '-' ? -1 : 1;\n      for (int i = SZ(s) -\
    \ 1, j = 0, b = 1; ~i && isdigit(s[i]);\n           --i, ++j, b *= 10) {\n   \
    \     if (b == base) j = 0, b = 1;\n        if (!j) mag.pb(0);\n        mag.back()\
    \ += (s[i] - '0') * b;\n      }\n    }\n  }\n  size_t size() const { return mag.size();\
    \ }\n  static void trim(vll& v) {\n    while (SZ(v) && !v.back()) v.pop_back();\n\
    \  }\n  void trim() {\n    trim(mag);\n    if (mag.empty()) signum = 0;\n  }\n\
    \  ll val(int index) { return index < SZ(mag) ? mag[index] : 0; }\n  friend bigint\
    \ operator-(bigint a) {\n    a.signum *= -1;\n    return a;\n  }\n  bigint& operator+=(ll\
    \ val) {\n    bigint t{val};\n    return (*this) += t;\n  }\n  bigint& operator+=(const\
    \ bigint& other) {\n    if (!other.signum) return *this;\n    if (!signum) return\
    \ *this = other;\n    if (signum == other.signum)\n      add_to(mag, ALL(other.mag));\n\
    \    else if (less(ALL(mag), ALL(other.mag)))\n      signum *= -1, mag = sub(ALL(other.mag),\
    \ ALL(mag));\n    else\n      sub_from(mag, ALL(other.mag));\n    trim();\n  \
    \  return *this;\n  }\n  friend bigint operator+(bigint a, const bigint& b) {\
    \ return a += b; }\n  friend bigint operator+(bigint a, ll val) { return a +=\
    \ val; }\n  friend bigint operator+(ll val, bigint a) { return a += val; }\n \
    \ static vll add(vit ab, vit ae, vit bb, vit be) {\n    vll out(ab, ae);\n   \
    \ add_to(out, bb, be);\n    return out;\n  }\n  static void add_to(vll& v, vit\
    \ ob, vit oe) {\n    v.resize(max(SZ(v), (int)distance(ob, oe)) + 1);\n    for\
    \ (int i = 0, c = 0; ob != oe || c; ++i) {\n      v[i] += (ob != oe ? *ob : 0)\
    \ + c;\n      c = v[i] >= base;\n      v[i] %= base;\n      if (ob != oe) ++ob;\n\
    \    }\n    trim(v);\n  }\n  bigint& operator-=(ll val) {\n    bigint t{val};\n\
    \    return (*this) -= t;\n  }\n  bigint& operator-=(const bigint& other) {\n\
    \    if (!other.signum) return *this;\n    if (!signum) {\n      mag = other.mag;\n\
    \      signum = -1 * other.signum;\n      return *this;\n    }\n    if (signum\
    \ != other.signum)\n      add_to(mag, ALL(other.mag));\n    else if (less(ALL(mag),\
    \ ALL(other.mag)))\n      signum *= -1, mag = sub(ALL(other.mag), ALL(mag));\n\
    \    else\n      sub_from(mag, ALL(other.mag));\n    trim();\n    return *this;\n\
    \  }\n  friend bigint operator-(bigint a, const bigint& b) { return a -= b; }\n\
    \  friend bigint operator-(bigint a, ll val) { return a -= val; }\n  friend bigint\
    \ operator-(ll val, bigint a) { return a -= val; }\n  static vll sub(vit ab, vit\
    \ ae, vit bb, vit be) {\n    // assert(!less(ab, ae, bb, be));\n    vll out(ab,\
    \ ae);\n    sub_from(out, bb, be);\n    return out;\n  }\n  static void sub_from(vll&\
    \ v, vit ob, vit oe) {\n    // assert(!less(ALL(v), ob, oe));\n    if (ob == oe)\
    \ return;\n    for (int i = 0, c = 0; ob != oe || c; ++i) {\n      ll sub = (ob\
    \ != oe ? *ob : 0) + c;\n      c = 0;\n      if (v[i] < sub) c = 1, v[i] += base;\n\
    \      v[i] -= sub;\n      if (ob != oe) ++ob;\n    }\n    trim(v);\n  }\n  bigint&\
    \ operator*=(ll val) {\n    if (!signum || !val) {\n      signum = 0, mag.clear();\n\
    \      return *this;\n    }\n    mag = small_mult(ALL(mag), val);\n    signum\
    \ *= sign(val);\n    return *this;\n  }\n  bigint& operator*=(const bigint& other)\
    \ {\n    if (!signum || !other.signum) {\n      signum = 0, mag.clear();\n   \
    \   return *this;\n    }\n    mag = karat_mult(ALL(mag), ALL(other.mag));\n  \
    \  signum *= other.signum;\n    return *this;\n  }\n  friend bigint operator*(bigint\
    \ a, const bigint& b) { return a *= b; }\n  friend bigint operator*(bigint a,\
    \ ll val) { return a *= val; }\n  friend bigint operator*(ll val, bigint a) {\
    \ return a *= val; }\n  static vll karat_mult(vit ab, vit ae, vit bb, vit be)\
    \ {\n    if (ab == ae || bb == be) return vll();\n    if (distance(ab, ae) < distance(bb,\
    \ be))\n      swap(ab, bb), swap(ae, be);\n    if (distance(bb, be) == 1) return\
    \ small_mult(ab, ae, *bb);\n    int split = distance(ab, ae) / 2;\n    vit amid\
    \ = ab + split,\n        bmid = bb + min(split, (int)distance(bb, be));\n    vll\
    \ z0 = karat_mult(ab, amid, bb, bmid);\n    vll z2 = karat_mult(amid, ae, bmid,\
    \ be);\n    vll x1x0 = add(ab, amid, amid, ae);\n    vll y1y0 = add(bb, bmid,\
    \ bmid, be);\n    vll z1 = karat_mult(ALL(x1x0), ALL(y1y0));\n    sub_from(z1,\
    \ ALL(z2));\n    sub_from(z1, ALL(z0));\n    vll out(max({SZ(z0), split + SZ(z1),\
    \ split * 2 + SZ(z2)}) + 1);\n    auto add = [&](vll& v, int offset) {\n     \
    \ for (int i = 0, c = 0; i < SZ(v) || c; ++i) {\n        out[i + offset] += (i\
    \ < SZ(v) ? v[i] : 0) + c;\n        c = out[i + offset] >= base;\n        out[i\
    \ + offset] %= base;\n      }\n    };\n    add(z0, 0);\n    add(z1, split);\n\
    \    add(z2, split * 2);\n    trim(out);\n    return out;\n  }\n  static vll small_mult(vit\
    \ ab, vit ae, ll fac) {\n    if (ab == ae || fac == 0) return vll();\n    vll\
    \ out(ab, ae);\n    ll c = 0;\n    for (int i = 0; i < SZ(out) || c; ++i) {\n\
    \      if (i == SZ(out)) out.pb(0);\n      out[i] = out[i] * fac + c;\n      c\
    \ = out[i] / base;\n      out[i] %= base;\n    }\n    trim(out);\n    return out;\n\
    \  }\n  friend bool operator<(const bigint& a, const bigint& b) {\n    if (a.signum\
    \ != b.signum) return a.signum < b.signum;\n    if (!a.signum) return false;\n\
    \    int c = cmp(ALL(a.mag), ALL(b.mag));\n    return a.signum > 0 ? c < 0 : c\
    \ > 0;\n  }\n  static int less(vit ab, vit ae, vit bb, vit be) {\n    return cmp(ab,\
    \ ae, bb, be) < 0;\n  }\n  static int cmp(vit ab, vit ae, vit bb, vit be) {\n\
    \    if (ab == ae && bb == be) return 0;\n    auto cmp = sign(distance(ab, ae)\
    \ - distance(bb, be));\n    if (cmp) return cmp;\n    do {\n      ae = prev(ae),\
    \ be = prev(be);\n      cmp = sign(*ae - *be);\n    } while (!cmp && ae != ab);\n\
    \    return cmp;\n  }\n  friend string to_string(const bigint& bi) {\n    if (!bi.signum)\
    \ return \"0\";\n    stringstream ss;\n    ss << bi.signum * bi.mag.back();\n\
    \    for (int i = SZ(bi) - 2; ~i; --i)\n      ss << setfill('0') << setw(9) <<\
    \ bi.mag[i];\n    return ss.str();\n  }\n  friend istream& operator>>(istream&\
    \ i, bigint& bi) {\n    string s;\n    i >> s;\n    bi = bigint(s);\n    return\
    \ i;\n  }\n  friend ostream& operator<<(ostream& o, const bigint& bi) {\n    return\
    \ o << to_string(bi);\n  }\n};\n"
  code: "#include \"../template.hh\"\ntemplate <class T>\nint sign(T a) {\n  return\
    \ (a > 0) - (0 > a);\n}\nusing vll = vector<ll>;\nusing vit = vll::const_iterator;\n\
    struct bigint {\n  static const ll base = 1e9;\n  int signum;\n  vll mag;\n  bigint()\
    \ : signum(0), mag() {}\n  bigint(ll val) : signum(sign(val)), mag() {\n    val\
    \ = abs(val);\n    while (val) mag.pb(val % base), val /= base;\n  }\n  bigint(int\
    \ sig, vll&& m) : signum(sig), mag(m) {\n    if (!sig) mag.clear();\n    trim();\n\
    \  }\n  bigint(string s) {\n    if (s.empty() || s == \"0\")\n      signum = 0;\n\
    \    else {\n      signum = s[0] == '-' ? -1 : 1;\n      for (int i = SZ(s) -\
    \ 1, j = 0, b = 1; ~i && isdigit(s[i]);\n           --i, ++j, b *= 10) {\n   \
    \     if (b == base) j = 0, b = 1;\n        if (!j) mag.pb(0);\n        mag.back()\
    \ += (s[i] - '0') * b;\n      }\n    }\n  }\n  size_t size() const { return mag.size();\
    \ }\n  static void trim(vll& v) {\n    while (SZ(v) && !v.back()) v.pop_back();\n\
    \  }\n  void trim() {\n    trim(mag);\n    if (mag.empty()) signum = 0;\n  }\n\
    \  ll val(int index) { return index < SZ(mag) ? mag[index] : 0; }\n  friend bigint\
    \ operator-(bigint a) {\n    a.signum *= -1;\n    return a;\n  }\n  bigint& operator+=(ll\
    \ val) {\n    bigint t{val};\n    return (*this) += t;\n  }\n  bigint& operator+=(const\
    \ bigint& other) {\n    if (!other.signum) return *this;\n    if (!signum) return\
    \ *this = other;\n    if (signum == other.signum)\n      add_to(mag, ALL(other.mag));\n\
    \    else if (less(ALL(mag), ALL(other.mag)))\n      signum *= -1, mag = sub(ALL(other.mag),\
    \ ALL(mag));\n    else\n      sub_from(mag, ALL(other.mag));\n    trim();\n  \
    \  return *this;\n  }\n  friend bigint operator+(bigint a, const bigint& b) {\
    \ return a += b; }\n  friend bigint operator+(bigint a, ll val) { return a +=\
    \ val; }\n  friend bigint operator+(ll val, bigint a) { return a += val; }\n \
    \ static vll add(vit ab, vit ae, vit bb, vit be) {\n    vll out(ab, ae);\n   \
    \ add_to(out, bb, be);\n    return out;\n  }\n  static void add_to(vll& v, vit\
    \ ob, vit oe) {\n    v.resize(max(SZ(v), (int)distance(ob, oe)) + 1);\n    for\
    \ (int i = 0, c = 0; ob != oe || c; ++i) {\n      v[i] += (ob != oe ? *ob : 0)\
    \ + c;\n      c = v[i] >= base;\n      v[i] %= base;\n      if (ob != oe) ++ob;\n\
    \    }\n    trim(v);\n  }\n  bigint& operator-=(ll val) {\n    bigint t{val};\n\
    \    return (*this) -= t;\n  }\n  bigint& operator-=(const bigint& other) {\n\
    \    if (!other.signum) return *this;\n    if (!signum) {\n      mag = other.mag;\n\
    \      signum = -1 * other.signum;\n      return *this;\n    }\n    if (signum\
    \ != other.signum)\n      add_to(mag, ALL(other.mag));\n    else if (less(ALL(mag),\
    \ ALL(other.mag)))\n      signum *= -1, mag = sub(ALL(other.mag), ALL(mag));\n\
    \    else\n      sub_from(mag, ALL(other.mag));\n    trim();\n    return *this;\n\
    \  }\n  friend bigint operator-(bigint a, const bigint& b) { return a -= b; }\n\
    \  friend bigint operator-(bigint a, ll val) { return a -= val; }\n  friend bigint\
    \ operator-(ll val, bigint a) { return a -= val; }\n  static vll sub(vit ab, vit\
    \ ae, vit bb, vit be) {\n    // assert(!less(ab, ae, bb, be));\n    vll out(ab,\
    \ ae);\n    sub_from(out, bb, be);\n    return out;\n  }\n  static void sub_from(vll&\
    \ v, vit ob, vit oe) {\n    // assert(!less(ALL(v), ob, oe));\n    if (ob == oe)\
    \ return;\n    for (int i = 0, c = 0; ob != oe || c; ++i) {\n      ll sub = (ob\
    \ != oe ? *ob : 0) + c;\n      c = 0;\n      if (v[i] < sub) c = 1, v[i] += base;\n\
    \      v[i] -= sub;\n      if (ob != oe) ++ob;\n    }\n    trim(v);\n  }\n  bigint&\
    \ operator*=(ll val) {\n    if (!signum || !val) {\n      signum = 0, mag.clear();\n\
    \      return *this;\n    }\n    mag = small_mult(ALL(mag), val);\n    signum\
    \ *= sign(val);\n    return *this;\n  }\n  bigint& operator*=(const bigint& other)\
    \ {\n    if (!signum || !other.signum) {\n      signum = 0, mag.clear();\n   \
    \   return *this;\n    }\n    mag = karat_mult(ALL(mag), ALL(other.mag));\n  \
    \  signum *= other.signum;\n    return *this;\n  }\n  friend bigint operator*(bigint\
    \ a, const bigint& b) { return a *= b; }\n  friend bigint operator*(bigint a,\
    \ ll val) { return a *= val; }\n  friend bigint operator*(ll val, bigint a) {\
    \ return a *= val; }\n  static vll karat_mult(vit ab, vit ae, vit bb, vit be)\
    \ {\n    if (ab == ae || bb == be) return vll();\n    if (distance(ab, ae) < distance(bb,\
    \ be))\n      swap(ab, bb), swap(ae, be);\n    if (distance(bb, be) == 1) return\
    \ small_mult(ab, ae, *bb);\n    int split = distance(ab, ae) / 2;\n    vit amid\
    \ = ab + split,\n        bmid = bb + min(split, (int)distance(bb, be));\n    vll\
    \ z0 = karat_mult(ab, amid, bb, bmid);\n    vll z2 = karat_mult(amid, ae, bmid,\
    \ be);\n    vll x1x0 = add(ab, amid, amid, ae);\n    vll y1y0 = add(bb, bmid,\
    \ bmid, be);\n    vll z1 = karat_mult(ALL(x1x0), ALL(y1y0));\n    sub_from(z1,\
    \ ALL(z2));\n    sub_from(z1, ALL(z0));\n    vll out(max({SZ(z0), split + SZ(z1),\
    \ split * 2 + SZ(z2)}) + 1);\n    auto add = [&](vll& v, int offset) {\n     \
    \ for (int i = 0, c = 0; i < SZ(v) || c; ++i) {\n        out[i + offset] += (i\
    \ < SZ(v) ? v[i] : 0) + c;\n        c = out[i + offset] >= base;\n        out[i\
    \ + offset] %= base;\n      }\n    };\n    add(z0, 0);\n    add(z1, split);\n\
    \    add(z2, split * 2);\n    trim(out);\n    return out;\n  }\n  static vll small_mult(vit\
    \ ab, vit ae, ll fac) {\n    if (ab == ae || fac == 0) return vll();\n    vll\
    \ out(ab, ae);\n    ll c = 0;\n    for (int i = 0; i < SZ(out) || c; ++i) {\n\
    \      if (i == SZ(out)) out.pb(0);\n      out[i] = out[i] * fac + c;\n      c\
    \ = out[i] / base;\n      out[i] %= base;\n    }\n    trim(out);\n    return out;\n\
    \  }\n  friend bool operator<(const bigint& a, const bigint& b) {\n    if (a.signum\
    \ != b.signum) return a.signum < b.signum;\n    if (!a.signum) return false;\n\
    \    int c = cmp(ALL(a.mag), ALL(b.mag));\n    return a.signum > 0 ? c < 0 : c\
    \ > 0;\n  }\n  static int less(vit ab, vit ae, vit bb, vit be) {\n    return cmp(ab,\
    \ ae, bb, be) < 0;\n  }\n  static int cmp(vit ab, vit ae, vit bb, vit be) {\n\
    \    if (ab == ae && bb == be) return 0;\n    auto cmp = sign(distance(ab, ae)\
    \ - distance(bb, be));\n    if (cmp) return cmp;\n    do {\n      ae = prev(ae),\
    \ be = prev(be);\n      cmp = sign(*ae - *be);\n    } while (!cmp && ae != ab);\n\
    \    return cmp;\n  }\n  friend string to_string(const bigint& bi) {\n    if (!bi.signum)\
    \ return \"0\";\n    stringstream ss;\n    ss << bi.signum * bi.mag.back();\n\
    \    for (int i = SZ(bi) - 2; ~i; --i)\n      ss << setfill('0') << setw(9) <<\
    \ bi.mag[i];\n    return ss.str();\n  }\n  friend istream& operator>>(istream&\
    \ i, bigint& bi) {\n    string s;\n    i >> s;\n    bi = bigint(s);\n    return\
    \ i;\n  }\n  friend ostream& operator<<(ostream& o, const bigint& bi) {\n    return\
    \ o << to_string(bi);\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/utils/bigint.cc
  requiredBy:
  - code/utils/stresstestbigint.cc
  timestamp: '2020-10-29 21:53:40+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/bigint.multiplication_bigint_1.test.cpp
  - tests/aoj/bigint.addition_bigint.test.cpp
  - tests/aoj/bigint.multiplication_bigint_2.test.cpp
  - tests/aoj/bigint.subtraction_bigint.test.cpp
  - tests/hackerrank/aho_corasick.two_two.test.cpp
documentation_of: code/utils/bigint.cc
layout: document
redirect_from:
- /library/code/utils/bigint.cc
- /library/code/utils/bigint.cc.html
title: code/utils/bigint.cc
---
