---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: code/utils/ops.cc
    title: code/utils/ops.cc
  _extendedVerifiedWith: []
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/Zeldacrafter/CompProg
    - https://xkcd.com/541/
  bundledCode: "#line 1 \"code/template_long.cc\"\n///////////////////////////////////////////////////////////////\n\
    // Long template from: https://github.com/Zeldacrafter/CompProg\n//\n// Feature\
    \ list:\n// * C++14 compatibility.\n// * Various 'define'-shorthands and typedefs.\n\
    // * Output stream that is only active with 'DEBUG'-flag set.\n// * Input and\
    \ output stream operators for...\n//   * any container with 'begin' and 'end'\
    \ iterator.\n//   * tuples with any amount of elements \n//     (Except for 0\
    \ elements tuples :'( ) Related: https://xkcd.com/541/\n//   * pairs.\n// * PrettyPrinting\
    \ a object with specified seperators.\n//   Each additional seperator specifies\
    \ the seperator for one level\n//   further into a nested structure. Pairs, tuples\
    \ and std-library-container\n//   cause the level to increase.\n//   If no seperator\
    \ is specified a default of \" \"(space) is used.\n//   For example a call \n\
    //      vii a(4, mp(1, 2));\n//      cout << pp(a, \" | \", \"-\");\n//   results\
    \ in the output (without trailing newline)\n//      1-2 | 1-2 | 1-2 | 1-2\n///////////////////////////////////////////////////////////////\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef\
    \ vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n\
    #define eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a,\
    \ b, c) for (auto a = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\n\
    template <typename T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true\
    \ : false; }\ntemplate <typename T>\nbool ckmax(T& a, const T& b) { return a <\
    \ b ? a = b, true : false; }\n\n// Output to 'cerr' if 'DEBUG' flag is set. Do\
    \ nothing otherwise.\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define dout if\
    \ (DEBUG) cerr\n// Output all passed variables with their corresponding name and\
    \ value.\n#define dvar(...) \" \\x1b[35m[\" << #__VA_ARGS__ \": \" << mt(__VA_ARGS__)\
    \ << \"]\\x1b[0m \"\n\n///////////////////////////////////////////////////////////////\n\
    // Utility functions.\n///////////////////////////////////////////////////////////////\n\
    \nnamespace impl {\n  template <typename T, typename F, size_t... Is>\n  F for_each(T&\
    \ t, F f, index_sequence<Is...>) {\n    auto l = { (f(get<Is>(t), Is), 0)... };\n\
    \    (void) l;\n    return f;\n  }\n}\n\ntemplate <typename... Ts, typename F>\n\
    F for_each(tuple<Ts...>& t, F f) { \n  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\ntemplate <typename... Ts, typename F>\nF for_each(const tuple<Ts...>& t,\
    \ F f) { \n  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\n// IsC indicates whether a type defines a 'const_iterator'.\n// IsC::value\
    \ is true if 'const_iterator' exists and false otherwise.\ntemplate <typename\
    \ T> true_type const_iterator_check(typename T::const_iterator*);\ntemplate <typename\
    \ T> false_type const_iterator_check(...);\ntemplate <typename T> struct IsC :\
    \ decltype(const_iterator_check<T>(nullptr)) {};\n// No new input/output for string\
    \ as those already exist.\ntemplate <> struct IsC<string> : false_type {};\n\n\
    ///////////////////////////////////////////////////////////////\n// Begin Output\
    \ \n///////////////////////////////////////////////////////////////\n\n// Forward\
    \ declarations.\ntemplate <typename T>\nenable_if_t<IsC<T>::value, ostream&> operator<<(ostream&,\
    \ const T&);\ntemplate <typename T1, typename T2>\nostream& operator<<(ostream&,\
    \ const pair<T1, T2>&);\n\n// Print each tuple element.\ntemplate <typename...\
    \ Ts>\nostream& operator<<(ostream& o, const tuple<Ts...>& t) {\n    o << '(';\n\
    \    for_each(t, [&](auto& x, size_t i) { if(i) o << \", \"; o << x; });\n   \
    \ return o << ')';\n}\n\n// Special case for 1-tuple to avoid confusing parentheses\n\
    template <typename T>\nostream& operator<<(ostream& o, const tuple<T>& t) {\n\
    \  return o << get<0>(t);\n}\n\n// Output for pairs via above defined tuple output\
    \ routine.\ntemplate <typename T1, typename T2>\nostream& operator<<(ostream&\
    \ o, const pair<T1, T2>& p) {\n  return o << '(' << p.fi << \", \" << p.se <<\
    \ ')';\n}\n\n// Output every element in a container with 'begin' and 'end' iterators.\n\
    template <typename T>\nenable_if_t<IsC<T>::value, ostream&> operator<<(ostream&\
    \ o, const T& c) {\n  o << '[';\n  for (auto it = c.cbegin(); it != c.cend();\
    \ ++it)\n    o << *it << (next(it) != c.cend() ? \", \" : \"\");\n  return o <<\
    \ ']';\n}\n\n///////////////////////////////////////////////////////////////\n\
    // Pretty output\n///////////////////////////////////////////////////////////////\n\
    \n// PrettyPrint struct that contains a value to be printed and\n// a list of\
    \ seperators which indicate how different dimensions\n// of multidimensional values\
    \ should be seperated.\ntemplate <typename T, size_t N>\nstruct PP {\n  // Value\
    \ to print.\n  const T& v; \n  // Pointer to seperator list.\n  shared_ptr<array<string,\
    \ N>> se;\n  // Index of next seperator.\n  size_t idx;\n  PP(const T& value,\
    \ shared_ptr<array<string, N>> p, size_t i = 0) \n      : v{value}, se{p}, idx{i}\
    \ {}\n};\n\n// If a value is not a pair, tuple or std-library-continer just print\
    \ it.\n// Pairs and tuples are implemented via template specialization further\
    \ down.\ntemplate <typename T, size_t M>\nenable_if_t<not IsC<T>::value, ostream&>\n\
    operator<<(ostream& o, const PP<T, M>& p) {\n  return o << p.v;\n}\n\n// Prints\
    \ every tuple element.\ntemplate <size_t M, typename... Ts>\nostream& operator<<(ostream&\
    \ o, const PP<tuple<Ts...>, M>& p) {\n  const string& sep = p.idx < M ? (*p.se)[p.idx]\
    \ : \" \";\n  for_each(p.v, [&](auto& x, size_t i) { \n    if(i) o << sep; \n\
    \    o << PP<decay_t<decltype(x)>, M>(x, p.se, p.idx + 1);\n  });\n  return o;\n\
    }\n\n// Print pairs with the specified seperator for that level.\ntemplate <typename\
    \ T1, typename T2, size_t M>\nostream& operator<<(ostream& o, const PP<pair<T1,\
    \ T2>, M>& p) {\n  const string& sep = p.idx < M ? (*p.se)[p.idx] : \" \";\n \
    \ return o << PP<T1, M>(p.v.fi, p.se, p.idx + 1) << sep\n           << PP<T2,\
    \ M>(p.v.se, p.se, p.idx + 1);\n}\n\n// Print std-library-container with the specified\
    \ seperator.\ntemplate <typename T, size_t M>\nenable_if_t<IsC<T>::value, ostream&>\n\
    operator<<(ostream& o, const PP<T, M>& p) {\n  // Seperator for the current layer\
    \ (or default)\n  const string& sep = p.idx < M ? (*p.se)[p.idx] : \" \";\n  //\
    \ Print every container element\n  for (auto it = p.v.cbegin(); it != p.v.cend();\
    \ ++it)\n    o << PP<typename T::value_type, M>(*it, p.se, p.idx + 1)\n      <<\
    \ (next(it) != p.v.cend() ? sep : \"\");\n  return o;\n}\n\n// This function is\
    \ the main way for a user to interface with the PrettyPrinter.\ntemplate <typename\
    \ T, typename... Ts, size_t N = sizeof...(Ts)>\nPP<T, N> pp(const T& value, Ts...\
    \ seps) {\n  return PP<T, N>(value, make_shared<array<string, N>>(array<string,\
    \ N>{seps...}));\n}\n\n///////////////////////////////////////////////////////////////\n\
    // Begin Input \n///////////////////////////////////////////////////////////////\n\
    \n// Forward declarations.\ntemplate <typename T>\nenable_if_t<IsC<T>::value,\
    \ istream&> operator>>(istream&, T&);\ntemplate <typename T1, typename T2>\nistream&\
    \ operator>>(istream&, pair<T1, T2>&);\n\n// Read a tuple.\ntemplate <typename...\
    \ Ts>\nistream& operator>>(istream& i, tuple<Ts...>& t) {\n  for_each(t, [&](auto&\
    \ x, int) { i >> x; });\n  return i;\n}\n\n// Read the contents of a 'pair' object.\n\
    template <typename T1, typename T2>\nistream& operator>>(istream& i, pair<T1,\
    \ T2>& p) {\n  return i >> p.fi >> p.se;\n}\n\n// Read containers with 'begin'\
    \ and 'end' iterators.\ntemplate <typename T>\nenable_if_t<IsC<T>::value, istream&>\
    \ operator>>(istream& i, T& v) {\n  for (auto& x : v) i >> x;\n  return i;\n}\n"
  code: "///////////////////////////////////////////////////////////////\n// Long\
    \ template from: https://github.com/Zeldacrafter/CompProg\n//\n// Feature list:\n\
    // * C++14 compatibility.\n// * Various 'define'-shorthands and typedefs.\n//\
    \ * Output stream that is only active with 'DEBUG'-flag set.\n// * Input and output\
    \ stream operators for...\n//   * any container with 'begin' and 'end' iterator.\n\
    //   * tuples with any amount of elements \n//     (Except for 0 elements tuples\
    \ :'( ) Related: https://xkcd.com/541/\n//   * pairs.\n// * PrettyPrinting a object\
    \ with specified seperators.\n//   Each additional seperator specifies the seperator\
    \ for one level\n//   further into a nested structure. Pairs, tuples and std-library-container\n\
    //   cause the level to increase.\n//   If no seperator is specified a default\
    \ of \" \"(space) is used.\n//   For example a call \n//      vii a(4, mp(1, 2));\n\
    //      cout << pp(a, \" | \", \"-\");\n//   results in the output (without trailing\
    \ newline)\n//      1-2 | 1-2 | 1-2 | 1-2\n///////////////////////////////////////////////////////////////\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef\
    \ vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n\
    #define eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a,\
    \ b, c) for (auto a = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\n\
    template <typename T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true\
    \ : false; }\ntemplate <typename T>\nbool ckmax(T& a, const T& b) { return a <\
    \ b ? a = b, true : false; }\n\n// Output to 'cerr' if 'DEBUG' flag is set. Do\
    \ nothing otherwise.\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define dout if\
    \ (DEBUG) cerr\n// Output all passed variables with their corresponding name and\
    \ value.\n#define dvar(...) \" \\x1b[35m[\" << #__VA_ARGS__ \": \" << mt(__VA_ARGS__)\
    \ << \"]\\x1b[0m \"\n\n///////////////////////////////////////////////////////////////\n\
    // Utility functions.\n///////////////////////////////////////////////////////////////\n\
    \nnamespace impl {\n  template <typename T, typename F, size_t... Is>\n  F for_each(T&\
    \ t, F f, index_sequence<Is...>) {\n    auto l = { (f(get<Is>(t), Is), 0)... };\n\
    \    (void) l;\n    return f;\n  }\n}\n\ntemplate <typename... Ts, typename F>\n\
    F for_each(tuple<Ts...>& t, F f) { \n  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\ntemplate <typename... Ts, typename F>\nF for_each(const tuple<Ts...>& t,\
    \ F f) { \n  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\n// IsC indicates whether a type defines a 'const_iterator'.\n// IsC::value\
    \ is true if 'const_iterator' exists and false otherwise.\ntemplate <typename\
    \ T> true_type const_iterator_check(typename T::const_iterator*);\ntemplate <typename\
    \ T> false_type const_iterator_check(...);\ntemplate <typename T> struct IsC :\
    \ decltype(const_iterator_check<T>(nullptr)) {};\n// No new input/output for string\
    \ as those already exist.\ntemplate <> struct IsC<string> : false_type {};\n\n\
    ///////////////////////////////////////////////////////////////\n// Begin Output\
    \ \n///////////////////////////////////////////////////////////////\n\n// Forward\
    \ declarations.\ntemplate <typename T>\nenable_if_t<IsC<T>::value, ostream&> operator<<(ostream&,\
    \ const T&);\ntemplate <typename T1, typename T2>\nostream& operator<<(ostream&,\
    \ const pair<T1, T2>&);\n\n// Print each tuple element.\ntemplate <typename...\
    \ Ts>\nostream& operator<<(ostream& o, const tuple<Ts...>& t) {\n    o << '(';\n\
    \    for_each(t, [&](auto& x, size_t i) { if(i) o << \", \"; o << x; });\n   \
    \ return o << ')';\n}\n\n// Special case for 1-tuple to avoid confusing parentheses\n\
    template <typename T>\nostream& operator<<(ostream& o, const tuple<T>& t) {\n\
    \  return o << get<0>(t);\n}\n\n// Output for pairs via above defined tuple output\
    \ routine.\ntemplate <typename T1, typename T2>\nostream& operator<<(ostream&\
    \ o, const pair<T1, T2>& p) {\n  return o << '(' << p.fi << \", \" << p.se <<\
    \ ')';\n}\n\n// Output every element in a container with 'begin' and 'end' iterators.\n\
    template <typename T>\nenable_if_t<IsC<T>::value, ostream&> operator<<(ostream&\
    \ o, const T& c) {\n  o << '[';\n  for (auto it = c.cbegin(); it != c.cend();\
    \ ++it)\n    o << *it << (next(it) != c.cend() ? \", \" : \"\");\n  return o <<\
    \ ']';\n}\n\n///////////////////////////////////////////////////////////////\n\
    // Pretty output\n///////////////////////////////////////////////////////////////\n\
    \n// PrettyPrint struct that contains a value to be printed and\n// a list of\
    \ seperators which indicate how different dimensions\n// of multidimensional values\
    \ should be seperated.\ntemplate <typename T, size_t N>\nstruct PP {\n  // Value\
    \ to print.\n  const T& v; \n  // Pointer to seperator list.\n  shared_ptr<array<string,\
    \ N>> se;\n  // Index of next seperator.\n  size_t idx;\n  PP(const T& value,\
    \ shared_ptr<array<string, N>> p, size_t i = 0) \n      : v{value}, se{p}, idx{i}\
    \ {}\n};\n\n// If a value is not a pair, tuple or std-library-continer just print\
    \ it.\n// Pairs and tuples are implemented via template specialization further\
    \ down.\ntemplate <typename T, size_t M>\nenable_if_t<not IsC<T>::value, ostream&>\n\
    operator<<(ostream& o, const PP<T, M>& p) {\n  return o << p.v;\n}\n\n// Prints\
    \ every tuple element.\ntemplate <size_t M, typename... Ts>\nostream& operator<<(ostream&\
    \ o, const PP<tuple<Ts...>, M>& p) {\n  const string& sep = p.idx < M ? (*p.se)[p.idx]\
    \ : \" \";\n  for_each(p.v, [&](auto& x, size_t i) { \n    if(i) o << sep; \n\
    \    o << PP<decay_t<decltype(x)>, M>(x, p.se, p.idx + 1);\n  });\n  return o;\n\
    }\n\n// Print pairs with the specified seperator for that level.\ntemplate <typename\
    \ T1, typename T2, size_t M>\nostream& operator<<(ostream& o, const PP<pair<T1,\
    \ T2>, M>& p) {\n  const string& sep = p.idx < M ? (*p.se)[p.idx] : \" \";\n \
    \ return o << PP<T1, M>(p.v.fi, p.se, p.idx + 1) << sep\n           << PP<T2,\
    \ M>(p.v.se, p.se, p.idx + 1);\n}\n\n// Print std-library-container with the specified\
    \ seperator.\ntemplate <typename T, size_t M>\nenable_if_t<IsC<T>::value, ostream&>\n\
    operator<<(ostream& o, const PP<T, M>& p) {\n  // Seperator for the current layer\
    \ (or default)\n  const string& sep = p.idx < M ? (*p.se)[p.idx] : \" \";\n  //\
    \ Print every container element\n  for (auto it = p.v.cbegin(); it != p.v.cend();\
    \ ++it)\n    o << PP<typename T::value_type, M>(*it, p.se, p.idx + 1)\n      <<\
    \ (next(it) != p.v.cend() ? sep : \"\");\n  return o;\n}\n\n// This function is\
    \ the main way for a user to interface with the PrettyPrinter.\ntemplate <typename\
    \ T, typename... Ts, size_t N = sizeof...(Ts)>\nPP<T, N> pp(const T& value, Ts...\
    \ seps) {\n  return PP<T, N>(value, make_shared<array<string, N>>(array<string,\
    \ N>{seps...}));\n}\n\n///////////////////////////////////////////////////////////////\n\
    // Begin Input \n///////////////////////////////////////////////////////////////\n\
    \n// Forward declarations.\ntemplate <typename T>\nenable_if_t<IsC<T>::value,\
    \ istream&> operator>>(istream&, T&);\ntemplate <typename T1, typename T2>\nistream&\
    \ operator>>(istream&, pair<T1, T2>&);\n\n// Read a tuple.\ntemplate <typename...\
    \ Ts>\nistream& operator>>(istream& i, tuple<Ts...>& t) {\n  for_each(t, [&](auto&\
    \ x, int) { i >> x; });\n  return i;\n}\n\n// Read the contents of a 'pair' object.\n\
    template <typename T1, typename T2>\nistream& operator>>(istream& i, pair<T1,\
    \ T2>& p) {\n  return i >> p.fi >> p.se;\n}\n\n// Read containers with 'begin'\
    \ and 'end' iterators.\ntemplate <typename T>\nenable_if_t<IsC<T>::value, istream&>\
    \ operator>>(istream& i, T& v) {\n  for (auto& x : v) i >> x;\n  return i;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: code/template_long.cc
  requiredBy:
  - code/utils/ops.cc
  timestamp: '2020-11-05 22:17:23+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/template_long.cc
layout: document
redirect_from:
- /library/code/template_long.cc
- /library/code/template_long.cc.html
title: code/template_long.cc
---
