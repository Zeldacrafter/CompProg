---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/strings/AHC.cc
    title: code/strings/AHC.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  - icon: ':heavy_check_mark:'
    path: code/utils/bigint.cc
    title: code/utils/bigint.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/challenges/two-two/problem
    links:
    - https://www.hackerrank.com/challenges/two-two/problem
  bundledCode: "#line 1 \"tests/hackerrank/aho_corasick.two_two.test.cpp\"\n#define\
    \ PROBLEM \"https://www.hackerrank.com/challenges/two-two/problem\"\n\n#line 1\
    \ \"code/template.cc\"\n// this line is here for a reason\n#include <bits/stdc++.h>\n\
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
    \ \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/strings/AHC.cc\"\
    \n\ntemplate <typename T, int E = 26, typename V = char, V base = 'a'>\nstruct\
    \ AHC {\n  using str = basic_string<V>;\n  T e;\n  vector<array<int, E>> nxt;\n\
    \  vi fail;\n  vector<T> val;\n  AHC(T _e) : e{_e}, nxt(1, array<int, E>()), fail(1,\
    \ 0), val(1, e) {}\n  AHC(T _e, const vector<pair<str, T>>& strs) \n      : e{_e},\
    \ nxt(1, array<int, E>()), fail(1, 0), val(1, e) {\n    for (const auto& [s, v]\
    \ : strs) insert(s, v);\n    build();\n  }\n  void reserve(size_t sz) {\n    nxt.reserve(sz);\n\
    \    fail.reserve(sz);\n    val.reserve(sz);\n  }\n  void insert(const str& s,\
    \ T v) {\n    int curr = 0;\n    for (V c : s) {\n      if (!nxt[curr][c - base])\
    \ {\n        nxt[curr][c - base] = SZ(nxt);\n        nxt.eb();\n        val.pb(e);\n\
    \      }\n      curr = nxt[curr][c - base];\n    }\n    val[curr] += v;\n  }\n\
    \  void build() {\n    fail.assign(SZ(nxt), 0);\n    queue<int> q;\n    F0R (i,\
    \ E)\n      if (nxt[0][i]) q.push(nxt[0][i]);\n    while (!q.empty()) {\n    \
    \  int curr = q.front();\n      q.pop();\n      F0R (i, E) {\n        if (nxt[curr][i])\
    \ {\n          fail[nxt[curr][i]] = nxt[fail[curr]][i];\n          val[nxt[curr][i]]\
    \ += val[nxt[fail[curr]][i]];\n          q.push(nxt[curr][i]);\n        } else\n\
    \          nxt[curr][i] = nxt[fail[curr]][i];\n      }\n    }\n  }\n  T query(const\
    \ str& s) {\n    int curr = 0;\n    T res = e;\n    for (V c : s) {\n      if\
    \ (nxt[curr][c - base])\n        curr = nxt[curr][c - base];\n      else\n   \
    \     while (curr && !nxt[curr][c - base]) curr = fail[curr];\n      res += val[curr];\n\
    \    }\n    return res;\n  }\n};\n#line 2 \"code/utils/bigint.cc\"\ntemplate <class\
    \ T>\nint sign(T a) {\n  return (a > 0) - (0 > a);\n}\nusing vll = vector<ll>;\n\
    using vit = vll::const_iterator;\nstruct bigint {\n  static const ll base = 1e9;\n\
    \  int signum;\n  vll mag;\n  bigint() : signum(0), mag() {}\n  bigint(ll val)\
    \ : signum(sign(val)), mag() {\n    val = abs(val);\n    while (val) mag.pb(val\
    \ % base), val /= base;\n  }\n  bigint(int sig, vll&& m) : signum(sig), mag(m)\
    \ {\n    if (!sig) mag.clear();\n    trim();\n  }\n  bigint(string s) {\n    if\
    \ (s.empty() || s == \"0\")\n      signum = 0;\n    else {\n      signum = s[0]\
    \ == '-' ? -1 : 1;\n      for (int i = SZ(s) - 1, j = 0, b = 1; ~i && isdigit(s[i]);\n\
    \           --i, ++j, b *= 10) {\n        if (b == base) j = 0, b = 1;\n     \
    \   if (!j) mag.pb(0);\n        mag.back() += (s[i] - '0') * b;\n      }\n   \
    \ }\n  }\n  size_t size() const { return mag.size(); }\n  static void trim(vll&\
    \ v) {\n    while (SZ(v) && !v.back()) v.pop_back();\n  }\n  void trim() {\n \
    \   trim(mag);\n    if (mag.empty()) signum = 0;\n  }\n  ll val(int index) { return\
    \ index < SZ(mag) ? mag[index] : 0; }\n  friend bigint operator-(bigint a) {\n\
    \    a.signum *= -1;\n    return a;\n  }\n  bigint& operator+=(ll val) {\n   \
    \ bigint t{val};\n    return (*this) += t;\n  }\n  bigint& operator+=(const bigint&\
    \ other) {\n    if (!other.signum) return *this;\n    if (!signum) return *this\
    \ = other;\n    if (signum == other.signum)\n      add_to(mag, ALL(other.mag));\n\
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
    \ bi.mag[i];\n    return ss.str();\n  }\n  friend ostream& operator<<(ostream&\
    \ o, const bigint& bi) {\n    return o << to_string(bi);\n  }\n};\n#line 5 \"\
    tests/hackerrank/aho_corasick.two_two.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios_base::sync_with_stdio(0);\n\n    vector<pair<string, int>> strs;\n\n\
    \    bigint x = 1;\n    F0R(i, 801) {\n        strs.eb(to_string(x), 1);\n   \
    \     x *= 2;\n    }\n\n    AHC<int, 10, char, '0'> ahc(0, strs);\n\n    int t;\n\
    \    cin >> t;\n    while(t--) {\n        string s;\n        cin >> s;\n     \
    \   cout << ahc.query(s);\n        if(t) cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/challenges/two-two/problem\"\
    \n\n#include \"../../code/strings/AHC.cc\"\n#include \"../../code/utils/bigint.cc\"\
    \n\nint main() {\n    cin.tie(0);\n    ios_base::sync_with_stdio(0);\n\n    vector<pair<string,\
    \ int>> strs;\n\n    bigint x = 1;\n    F0R(i, 801) {\n        strs.eb(to_string(x),\
    \ 1);\n        x *= 2;\n    }\n\n    AHC<int, 10, char, '0'> ahc(0, strs);\n\n\
    \    int t;\n    cin >> t;\n    while(t--) {\n        string s;\n        cin >>\
    \ s;\n        cout << ahc.query(s);\n        if(t) cout << endl;\n    }\n}\n"
  dependsOn:
  - code/strings/AHC.cc
  - code/template.cc
  - code/utils/bigint.cc
  isVerificationFile: true
  path: tests/hackerrank/aho_corasick.two_two.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 00:25:40+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/hackerrank/aho_corasick.two_two.test.cpp
layout: document
redirect_from:
- /verify/tests/hackerrank/aho_corasick.two_two.test.cpp
- /verify/tests/hackerrank/aho_corasick.two_two.test.cpp.html
title: tests/hackerrank/aho_corasick.two_two.test.cpp
---
