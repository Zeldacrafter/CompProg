---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: code/template_long.cc
    title: code/template_long.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"code/template_long.cc\"\n///////////////////////////////////////////////////////////////\n\
    // Long template from: https://github.com/Zeldacrafter/CompProg\n//\n// Feature\
    \ list:\n// * C++14 compatibility.\n// * Various 'define'-shorthands and typedefs.\n\
    // * Output stream that is only active with 'DEBUG'-flag set.\n// * Input and\
    \ output stream operators for...\n//   * any container with 'begin' and 'end'\
    \ iterator.\n//   * tuples with any amount of elements\n//     (Except for 0 elements\
    \ tuples :'( ) Related: https://xkcd.com/541/\n//   * pairs.\n// * PrettyPrinting\
    \ a object with specified seperators.\n//   Each additional seperator specifies\
    \ the seperator for one level\n//   further into a nested structure. Pairs, tuples\
    \ and std-library-container\n//   cause the level to increase.\n//   If no seperator\
    \ is specified a default of \" \"(space) is used.\n//   For example a call\n//\
    \      vii a(4, mp(1, 2));\n//      cout << pp(a, \" | \", \"-\");\n//   results\
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
    \ b ? a = b, true : false; }\n// Output to 'cerr' if 'DEBUG' flag is set. Do nothing\
    \ otherwise.\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG)\
    \ cerr\n// Output all passed variables with their corresponding name and value.\n\
    #define dvarimpl(...) mkDB(#__VA_ARGS__, __VA_ARGS__) << \"\\e[0m \"\n#define\
    \ dvar(...) \" \\e[35m\" << dvarimpl(__VA_ARGS__)\n#define dvarr(...) \" \\e[31m\"\
    \ << dvarimpl(__VA_ARGS__)\n#define dvarb(...) \" \\e[34m\" << dvarimpl(__VA_ARGS__)\n\
    #define dvarg(...) \" \\e[32m\" << dvarimpl(__VA_ARGS__)\n#define dvary(...) \"\
    \ \\e[33m\" << dvarimpl(__VA_ARGS__)\n#define dvarc(...) \" \\e[36m\" << dvarimpl(__VA_ARGS__)\n\
    #define dvari(...) \" \\e[7m\" << dvarimpl(__VA_ARGS__)\n\n///////////////////////////////////////////////////////////////\n\
    // Utility functions.\n///////////////////////////////////////////////////////////////\n\
    \nnamespace impl {\n  template <typename T, typename F, size_t... Is>\n  F for_each(T&\
    \ t, F f, index_sequence<Is...>) {\n    auto l = { (f(get<Is>(t), Is), 0)... };\n\
    \    (void) l;\n    return f;\n  }\n}\n\ntemplate <typename... Ts, typename F>\n\
    F for_each(tuple<Ts...>& t, F f) {\n  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\ntemplate <typename... Ts, typename F>\nF for_each(const tuple<Ts...>& t,\
    \ F f) {\n  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\n\n// IsC indicates whether a type defines a 'const_iterator'.\n// IsC::value\
    \ is true if 'const_iterator' exists and false otherwise.\ntemplate <typename\
    \ T> true_type const_iterator_check(typename T::const_iterator*);\ntemplate <typename\
    \ T> false_type const_iterator_check(...);\ntemplate <typename T> struct IsC :\
    \ decltype(const_iterator_check<T>(nullptr)) {};\n// No new input/output for string\
    \ as those already exist.\ntemplate <> struct IsC<string> : false_type {};\n\n\
    ///////////////////////////////////////////////////////////////\n// Begin Output\n\
    ///////////////////////////////////////////////////////////////\n\n// Forward\
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
    // Debug output\n///////////////////////////////////////////////////////////////\n\
    \ntemplate <typename... Ts>\nstruct DB {\n  string n;\n  tuple<Ts...> d;\n  DB(const\
    \ string& ns, Ts... ds) : n{ns}, d{ds...} {}\n  friend ostream& operator<<(ostream&\
    \ o, const DB& db) {\n    int i = 0;\n    for_each(db.d, [&](const auto& e, int\
    \ idx) {\n      (idx ? o << \" \" : o) << \"[\";\n      while (i < SZ(db.n) and\
    \ isspace(db.n[i])) ++i;\n      int br = 0, str = 0, chr = 0, esc = 0;\n     \
    \ while (i < SZ(db.n)) {\n        if (db.n[i] == '\\\\') esc = not esc;\n    \
    \    if (not chr and not esc and db.n[i] == '\\\"') str = not str;\n        if\
    \ (not str and not esc and db.n[i] == '\\'') chr = not chr;\n        if (not str\
    \ and not chr) {\n          br += brt(db.n[i]);\n          if (db.n[i] == ','\
    \ and br == 0) {\n            ++i;\n            break;\n          }\n        }\n\
    \        if (db.n[i] != '\\\\') esc = false;\n        o << db.n[i++];\n      }\n\
    \      o << \": \" << e << \"]\";\n    });\n    return o;\n  }\n  static inline\
    \ int brt(char c) {\n    switch (c) {\n    case '(': case '[': case '{': return\
    \ 1;\n    case ')': case ']': case '}': return -1;\n    default: return 0;\n \
    \   }\n  }\n};\ntemplate <typename... Ts>\nDB<Ts...> mkDB(const string& n, Ts...\
    \ d) { return DB<Ts...>(n, d...); }\n\n///////////////////////////////////////////////////////////////\n\
    // Pretty output\n///////////////////////////////////////////////////////////////\n\
    \n// PrettyPrint struct that contains a value to be printed and\n// a list of\
    \ seperators which indicate how different dimensions\n// of multidimensional values\
    \ should be seperated.\ntemplate <typename T, size_t N>\nstruct PP {\n  // Value\
    \ to print.\n  const T& v;\n  // Pointer to seperator list.\n  shared_ptr<array<string,\
    \ N>> se;\n  // Index of next seperator.\n  size_t idx;\n  PP(const T& value,\
    \ shared_ptr<array<string, N>> p, size_t i = 0)\n      : v{value}, se{p}, idx{i}\
    \ {}\n};\n\n// If a value is not a pair, tuple or std-library-continer just print\
    \ it.\n// Pairs and tuples are implemented via template specialization further\
    \ down.\ntemplate <typename T, size_t M>\nenable_if_t<not IsC<T>::value, ostream&>\n\
    operator<<(ostream& o, const PP<T, M>& p) {\n  return o << p.v;\n}\n\n// Prints\
    \ every tuple element.\ntemplate <size_t M, typename... Ts>\nostream& operator<<(ostream&\
    \ o, const PP<tuple<Ts...>, M>& p) {\n  const string& sep = p.idx < M ? (*p.se)[p.idx]\
    \ : \" \";\n  for_each(p.v, [&](auto& x, size_t i) {\n    if(i) o << sep;\n  \
    \  o << PP<decay_t<decltype(x)>, M>(x, p.se, p.idx + 1);\n  });\n  return o;\n\
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
    // Begin Input\n///////////////////////////////////////////////////////////////\n\
    \n// Forward declarations.\ntemplate <typename T>\nenable_if_t<IsC<T>::value,\
    \ istream&> operator>>(istream&, T&);\ntemplate <typename T1, typename T2>\nistream&\
    \ operator>>(istream&, pair<T1, T2>&);\n\n// Read a tuple.\ntemplate <typename...\
    \ Ts>\nistream& operator>>(istream& i, tuple<Ts...>& t) {\n  for_each(t, [&](auto&\
    \ x, int) { i >> x; });\n  return i;\n}\n\n// Read the contents of a 'pair' object.\n\
    template <typename T1, typename T2>\nistream& operator>>(istream& i, pair<T1,\
    \ T2>& p) {\n  return i >> p.fi >> p.se;\n}\n\n// Read containers with 'begin'\
    \ and 'end' iterators.\ntemplate <typename T>\nenable_if_t<IsC<T>::value, istream&>\
    \ operator>>(istream& i, T& v) {\n  for (auto& x : v) i >> x;\n  return i;\n}\n\
    template<typename T>\nset<T>& operator+=(set<T>& s, const T& e) {\n  return s.insert(e),\
    \ s;\n}\ntemplate<typename T>\nset<T>& operator-=(set<T>& s, const T& e) {\n \
    \ return s.erase(e), s;\n}\ntemplate<typename T>\nset<T>& operator&=(set<T>& a,\
    \ const set<T>& b) {\n  set<T> o;\n  set_intersection(ALL(a), ALL(b), inserter(o,\
    \ o.begin()));\n  return a.swap(o), a;\n}\ntemplate<typename T>\nset<T>& operator^=(set<T>&\
    \ a, const set<T>& b) {\n  set<T> o;\n  set_symmetric_difference(ALL(a), ALL(b),\
    \ inserter(o, o.begin()));\n  return a.swap(o), a;\n}\ntemplate<typename T>\n\
    set<T>& operator/=(set<T>& a, const set<T>& b) {\n  set<T> o;\n  set_difference(ALL(a),\
    \ ALL(b), inserter(o, o.begin()));\n  return a.swap(o), a;\n}\ntemplate<typename\
    \ T>\nset<T>& operator|=(set<T>& a, const set<T>& b) {\n  return a.insert(ALL(b)),\
    \ a;\n}\ntemplate<typename T>\nset<T> operator&(set<T> a, const set<T>& b) {\n\
    \  return a &= b;\n}\ntemplate<typename T>\nset<T> operator^(set<T> a, const set<T>&\
    \ b) {\n  return a ^= b;\n}\ntemplate<typename T>\nset<T> operator/(set<T> a,\
    \ const set<T>& b) {\n  return a /= b;\n}\ntemplate<typename T>\nset<T> operator|(set<T>\
    \ a, const set<T>& b) {\n  return a |= b;\n}\ntemplate<typename T>\nbool operator<(const\
    \ set<T>& s, const T& e) {\n  return static_cast<bool>(s.count(e));\n}\ntemplate<typename\
    \ T>\nbool operator<(const T& e, const set<T>& s) {\n  return static_cast<bool>(s.count(e));\n\
    }\n#line 2 \"code/utils/ops.cc\"\n\n///////////////////////////////////////////////////////////////\n\
    // Utility functions.\n///////////////////////////////////////////////////////////////\n\
    \nnamespace impl {\n  template <typename T, typename U, typename F, size_t...\
    \ Is>\n  T zipWith(const T& t, const U& u, F f, index_sequence<Is...>) { \n  \
    \  return mt((static_cast<tuple_element_t<Is, T>>(f(get<Is>(t), get<Is>(u), Is)))...);\n\
    \  }\n\n  template <typename T, typename U, typename F, size_t... Is>\n  F for_each_2t(T&\
    \ t, const U& u, F f, index_sequence<Is...>) {\n    auto l = { (f(get<Is>(t),\
    \ get<Is>(u)), 0)... };\n    (void) l;\n    return f;\n  }\n}\n\ntemplate <typename...\
    \ Ts, typename... Us, typename F>\ntuple<Ts...> zipWith(const tuple<Ts...>& t,\
    \ const tuple<Us...>& u, F f) { \n  static_assert(sizeof...(Ts) == sizeof...(Us),\
    \ \"Tuples must be the same size\");\n  return impl::zipWith(t, u, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\ntemplate <typename... Ts, typename... Us, typename F>\nF for_each_2t(tuple<Ts...>&\
    \ t, const tuple<Us...>& u, F f) { \n  static_assert(sizeof...(Ts) == sizeof...(Us),\
    \ \"Tuples must be the same size\");\n  return impl::for_each_2t(t, u, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\ntemplate <typename T> true_type tuple_size_check(typename tuple_size<T>::type*);\n\
    template <typename T> false_type tuple_size_check(...);\ntemplate <typename T>\
    \ struct IsT : decltype(tuple_size_check<T>(nullptr)) {};\ntemplate <typename\
    \ T> true_type stream_check(typename T::off_type*);\ntemplate <typename T> false_type\
    \ stream_check(...);\ntemplate <typename T> struct IsSt : decltype(stream_check<T>(nullptr))\
    \ {};\ntemplate <typename T> struct IsS : integral_constant<bool, IsT<T>::value\
    \ or IsC<T>::value or IsSt<T>::value> {};\n\n#define vAssignmentOpF(name) \\\n\
    \  template <typename T, typename U> \\\n  vector<T>& name(vector<T>&, const U&);\
    \ \\\n  template <typename T, typename U> \\\n  vector<T>& name(vector<T>&, const\
    \ vector<U>&);\n\n#define vAssignmentOp(name, op)     \\\n  template <typename\
    \ T, typename U> \\\n  vector<T>& name(vector<T>& v, const U& x) { \\\n    for\
    \ (auto& i : v) i op x; \\\n    return v; \\\n  } \\\n  template <typename T,\
    \ typename U> \\\n  vector<T>& name(vector<T>& v, const vector<U>& w) { \\\n \
    \   F0R (i, min(SZ(v), SZ(w))) v[i] op w[i]; \\\n    return v; \\\n  }\n\n#define\
    \ vIncDecF(name) \\\n  template<typename T> \\\n  vector<T>& name(vector<T>&);\
    \ \\\n  template<typename T> \\\n  vector<T> name(vector<T>&, int);\n\n#define\
    \ vIncDec(name, op)     \\\n  template<typename T> \\\n  vector<T>& name(vector<T>&\
    \ v) { \\\n    for (auto& x : v) op x; \\\n    return v; \\\n  } \\\n  template<typename\
    \ T> \\\n  vector<T> name(vector<T>& v, int) { \\\n    vector<T> t{v}; \\\n  \
    \  op v; \\\n    return t; \\\n  }\n\n#define vBinOpF(name) \\\n  template <typename\
    \ T, typename U> \\\n  vector<T> name(vector<T>, const vector<U>&); \\\n  template\
    \ <typename T, typename U> \\\n  vector<T> name(vector<T>, const U&); \\\n  template\
    \ <typename T, typename U> \\\n  enable_if_t<!IsS<U>::value, vector<T>> \\\n \
    \ name(const U&, vector<T>);\n\n#define vBinOp(name, op) \\\n  template <typename\
    \ T, typename U> \\\n  vector<T> name(vector<T> v, const vector<U>& u) { return\
    \ v op u; } \\\n  template <typename T, typename U> \\\n  vector<T> name(vector<T>\
    \ v, const U& u) { return v op u; } \\\n  template <typename T, typename U> \\\
    \n  enable_if_t<!IsS<U>::value, vector<T>> \\\n  name(const U& u, vector<T> v)\
    \ { return v op u; }\n\n#define vBinOpNo(name, op, ex) \\\n  template <typename\
    \ T, typename U> \\\n  vector<T> name(vector<T> v, const vector<U>& u) { return\
    \ v op u; } \\\n  template <typename T, typename U> \\\n  vector<T> name(vector<T>\
    \ v, const U& u) { return v op u; } \\\n  template <typename T, typename U> \\\
    \n  enable_if_t<!IsS<U>::value, vector<T>> \\\n  name(const U& u, vector<T> v)\
    \ { for (auto& i : v) i = u ex i; return v; }\n\n#define pAssignmentOpF(name)\
    \ \\\n  template <typename T1, typename T2, typename U1, typename U2> \\\n  pair<T1,\
    \ T2>& name(pair<T1, T2>&, const pair<U1, U2>&); \\\n  template <typename T1,\
    \ typename T2, typename U> \\\n  pair<T1, T2>& name(pair<T1, T2>&, const U&);\
    \ \n\n#define pAssignmentOp(name, op) \\\n  template <typename T1, typename T2,\
    \ typename U1, typename U2> \\\n  pair<T1, T2>& name(pair<T1, T2>& p1, const pair<U1,\
    \ U2>& p2) { \\\n    p1.fi op p2.fi; p1.se op p2.se; return p1; \\\n  } \\\n \
    \ template <typename T1, typename T2, typename U> \\\n  pair<T1, T2>& name(pair<T1,\
    \ T2>& p, const U& u) { \\\n    p.fi op u; p.se op u; return p; \\\n  }\n\n#define\
    \ pIncDecF(name) \\\n  template<typename T1, typename T2> \\\n  pair<T1, T2>&\
    \ name(pair<T1, T2>&); \\\n  template<typename T1, typename T2> \\\n  pair<T1,\
    \ T2> name(pair<T1, T2>&, int);\n\n#define pIncDec(name, op) \\\n  template<typename\
    \ T1, typename T2> \\\n  pair<T1, T2>& name(pair<T1, T2>& p) { \\\n    op p.fi;\
    \ op p.se; \\\n    return p; \\\n  } \\\n  template<typename T1, typename T2>\
    \ \\\n  pair<T1, T2> name(pair<T1, T2>& p, int) { \\\n    pair<T1, T2> t{p}; \\\
    \n    op p; \\\n    return t; \\\n  }\n\n#define pBinOpF(name) \\\n  template\
    \ <typename T1, typename T2, typename U1, typename U2> \\\n  pair<T1, T2> name(pair<T1,\
    \ T2>, const pair<U1, U2>&); \\\n  template <typename T1, typename T2, typename\
    \ U> \\\n  pair<T1, T2> name(pair<T1, T2>, const U&); \\\n  template <typename\
    \ T1, typename T2, typename U> \\\n  enable_if_t<!IsS<U>::value, pair<T1, T2>>\
    \ \\\n  name(const U&, pair<T1, T2>);\n\n#define pBinOp(name, op) \\\n  template\
    \ <typename T1, typename T2, typename U1, typename U2> \\\n  pair<T1, T2> name(pair<T1,\
    \ T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \\\n  template <typename\
    \ T1, typename T2, typename U> \\\n  pair<T1, T2> name(pair<T1, T2> p, const U&\
    \ u) { return p op u; } \\\n  template <typename T1, typename T2, typename U>\
    \ \\\n  enable_if_t<!IsS<U>::value, pair<T1, T2>> \\\n  name(const U& u, pair<T1,\
    \ T2> p) { return p op u; }\n\n#define pBinOpNo(name, op, ex) \\\n  template <typename\
    \ T1, typename T2, typename U1, typename U2> \\\n  pair<T1, T2> name(pair<T1,\
    \ T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \\\n  template <typename\
    \ T1, typename T2, typename U> \\\n  pair<T1, T2> name(pair<T1, T2> p, const U&\
    \ u) { return p op u; } \\\n  template <typename T1, typename T2, typename U>\
    \ \\\n  enable_if_t<!IsS<U>::value, pair<T1, T2>> \\\n  name(const U& u, pair<T1,\
    \ T2> p) { p.fi = u ex p.fi; p.se = u ex p.se; }\n\n#define tAssignmentOpF(name)\
    \ \\\n  template <typename... Ts, typename U> \\\n  tuple<Ts...>& name(tuple<Ts...>&,\
    \ const U&); \\\n  template <typename... Ts, typename... Us> \\\n  tuple<Ts...>&\
    \ name(tuple<Ts...>&, const tuple<Us...>&);\n\n#define tAssignmentOp(name, op)\
    \     \\\n  template <typename... Ts, typename U> \\\n  tuple<Ts...>& name(tuple<Ts...>&\
    \ t, const U& u) { \\\n    for_each(t, [&](auto& x, int) { x op u; }); \\\n  \
    \  return t; \\\n  } \\\n  template <typename... Ts, typename... Us> \\\n  tuple<Ts...>&\
    \ name(tuple<Ts...>& t1, const tuple<Us...>& t2) { \\\n    for_each_2t(t1, t2,\
    \ [](auto& x, const auto& y) { x op y; }); \\\n    return t1; \\\n  }\n\n#define\
    \ tIncDecF(name) \\\n  template<typename... Ts> \\\n  tuple<Ts...>& name(tuple<Ts...>&);\
    \ \\\n  template<typename... Ts> \\\n  tuple<Ts...> name(tuple<Ts...>&, int);\n\
    \n#define tIncDec(name, op)     \\\n  template<typename... Ts> \\\n  tuple<Ts...>&\
    \ name(tuple<Ts...>& t) { \\\n    for_each(t,  [](auto& x, int) { op x; }); \\\
    \n    return t; \\\n  } \\\n  template<typename... Ts> \\\n  tuple<Ts...> name(tuple<Ts...>&\
    \ t, int) { \\\n    tuple<Ts...> tp{t}; \\\n    op t; \\\n    return tp; \\\n\
    \  }\n\n#define tBinOpF(name) \\\n  template <typename... Ts, typename... Us>\
    \ \\\n  tuple<Ts...> name(tuple<Ts...>, const tuple<Us...>&); \\\n  template <typename...\
    \ Ts, typename U> \\\n  tuple<Ts...> name(tuple<Ts...>, const U&); \\\n  template\
    \ <typename... Ts, typename U> \\\n  enable_if_t<!IsS<U>::value, tuple<Ts...>>\
    \ \\\n  name(const U&, tuple<Ts...>);\n\n#define tBinOp(name, op) \\\n  template\
    \ <typename... Ts, typename... Us> \\\n  tuple<Ts...> name(tuple<Ts...> t, const\
    \ tuple<Us...>& u) {return t op u; } \\\n  template <typename... Ts, typename\
    \ U> \\\n  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \\\
    \n  template <typename... Ts, typename U> \\\n  enable_if_t<!IsS<U>::value, tuple<Ts...>>\
    \ \\\n  name(const U& u, tuple<Ts...> t) { return t op u; }\n\n#define tBinOpNo(name,\
    \ op, ex) \\\n  template <typename... Ts, typename... Us> \\\n  tuple<Ts...> name(tuple<Ts...>\
    \ t, const tuple<Us...>& u) {return t op u; } \\\n  template <typename... Ts,\
    \ typename U> \\\n  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op\
    \ u; } \\\n  template <typename... Ts, typename U> \\\n  enable_if_t<!IsS<U>::value,\
    \ tuple<Ts...>> \\\n  name(const U& u, tuple<Ts...> t) { for_each(t, [&](auto&\
    \ x, int) { x = u ex x; }); return t; }\n\n// vector forward declarations\nvAssignmentOpF(operator+=)\
    \ vAssignmentOpF(operator-=)\nvAssignmentOpF(operator*=) vAssignmentOpF(operator/=)\
    \ vAssignmentOpF(operator%=)\nvAssignmentOpF(operator^=) vAssignmentOpF(operator|=)\
    \ vAssignmentOpF(operator&=)\nvAssignmentOpF(operator<<=) vAssignmentOpF(operator>>=)\n\
    vBinOpF(operator+) vBinOpF(operator-)\nvBinOpF(operator*) vBinOpF(operator/) vBinOpF(operator%)\n\
    vBinOpF(operator^) vBinOpF(operator|) vBinOpF(operator&)\nvBinOpF(operator<<)\
    \ vBinOpF(operator>>)\nvIncDecF(operator++) vIncDecF(operator--)\ntemplate <typename\
    \ T> vector<T> operator-(vector<T> v);\ntemplate <typename T> vector<T> operator+(vector<T>\
    \ v);\n\n// pair forward declarations\npAssignmentOpF(operator+=) pAssignmentOpF(operator-=)\n\
    pAssignmentOpF(operator*=) pAssignmentOpF(operator/=) pAssignmentOpF(operator%=)\n\
    pAssignmentOpF(operator^=) pAssignmentOpF(operator|=) pAssignmentOpF(operator&=)\n\
    pAssignmentOpF(operator<<=) pAssignmentOpF(operator>>=)\npBinOpF(operator+) pBinOpF(operator-)\n\
    pBinOpF(operator*) pBinOpF(operator/) pBinOpF(operator%)\npBinOpF(operator^) pBinOpF(operator|)\
    \ pBinOpF(operator&)\npBinOpF(operator<<) pBinOpF(operator>>)\npIncDecF(operator++)\
    \ pIncDecF(operator--)\ntemplate <typename T1, typename T2>\npair<T1, T2> operator-(const\
    \ pair<T1, T2>& p);\ntemplate <typename T1, typename T2>\npair<T1, T2> operator+(const\
    \ pair<T1, T2>& p);\n\n// tuple forward declarations\ntAssignmentOpF(operator+=)\
    \ tAssignmentOpF(operator-=)\ntAssignmentOpF(operator*=) tAssignmentOpF(operator/=)\
    \ tAssignmentOpF(operator%=)\ntAssignmentOpF(operator^=) tAssignmentOpF(operator|=)\
    \ tAssignmentOpF(operator&=)\ntAssignmentOpF(operator<<=) tAssignmentOpF(operator>>=)\n\
    tBinOpF(operator+) tBinOpF(operator-)\ntBinOpF(operator*) tBinOpF(operator/) tBinOpF(operator%)\n\
    tBinOpF(operator^) tBinOpF(operator|) tBinOpF(operator&)\ntBinOpF(operator<<)\
    \ tBinOpF(operator>>)\ntIncDecF(operator++) tIncDecF(operator--)\ntemplate <typename...\
    \ Ts> tuple<Ts...> operator-(tuple<Ts...> v);\ntemplate <typename... Ts> tuple<Ts...>\
    \ operator+(tuple<Ts...> v);\n\n// vector implementation\nvAssignmentOp(operator+=,\
    \ +=) vAssignmentOp(operator-=, -=)\nvAssignmentOp(operator*=, *=) vAssignmentOp(operator/=,\
    \ /=) vAssignmentOp(operator%=, %=)\nvAssignmentOp(operator^=, ^=) vAssignmentOp(operator|=,\
    \ |=) vAssignmentOp(operator&=, &=)\nvAssignmentOp(operator<<=, <<=) vAssignmentOp(operator>>=,\
    \ >>=)\nvBinOp(operator+, +=) vBinOpNo(operator-, -=, -)\nvBinOp(operator*, *=)\
    \ vBinOpNo(operator/, /=, /) vBinOpNo(operator%, %=, %)\nvBinOp(operator^, ^=)\
    \ vBinOp(operator|, |=) vBinOp(operator&, &=)\nvBinOpNo(operator<<, <<=, <<) vBinOpNo(operator>>,\
    \ >>=, <<)\nvIncDec(operator++, ++) vIncDec(operator--, --)\ntemplate <typename\
    \ T> vector<T> operator-(vector<T> v) {\n  for (auto& i : v) i = -i;\n  return\
    \ v;\n}\ntemplate <typename T> vector<T> operator+(vector<T> v) {\n  for (auto&\
    \ i : v) i = +i;\n  return v;\n}\n\n// pair implementation\npAssignmentOp(operator+=,\
    \ +=) pAssignmentOp(operator-=, -=)\npAssignmentOp(operator*=, *=) pAssignmentOp(operator/=,\
    \ /=) pAssignmentOp(operator%=, %=)\npAssignmentOp(operator^=, ^=) pAssignmentOp(operator|=,\
    \ |=) pAssignmentOp(operator&=, &=)\npAssignmentOp(operator<<=, <<=) pAssignmentOp(operator>>=,\
    \ >>=)\npBinOp(operator+, +=) pBinOpNo(operator-, -=, -)\npBinOp(operator*, *=)\
    \ pBinOpNo(operator/, /=, /) pBinOpNo(operator%, %=, %)\npBinOp(operator^, ^=)\
    \ pBinOp(operator|, |=) pBinOp(operator&, &=)\npBinOpNo(operator<<, <<=, <<) pBinOpNo(operator>>,\
    \ >>=, <<)\npIncDec(operator++, ++) pIncDec(operator--, --)\ntemplate <typename\
    \ T1, typename T2>\npair<T1, T2> operator-(const pair<T1, T2>& p) { return mp(-p.fi,\
    \ -p.se); }\ntemplate <typename T1, typename T2>\npair<T1, T2> operator+(const\
    \ pair<T1, T2>& p) { return mp(+p.fi, +p.se); }\n\n// tuple implementation\ntAssignmentOp(operator+=,\
    \ +=) tAssignmentOp(operator-=, -=)\ntAssignmentOp(operator*=, *=) tAssignmentOp(operator/=,\
    \ /=) tAssignmentOp(operator%=, %=)\ntAssignmentOp(operator^=, ^=) tAssignmentOp(operator|=,\
    \ |=) tAssignmentOp(operator&=, &=)\ntAssignmentOp(operator<<=, <<=) tAssignmentOp(operator>>=,\
    \ >>=)\ntBinOp(operator+, +=) tBinOpNo(operator-, -=, -)\ntBinOp(operator*, *=)\
    \ tBinOpNo(operator/, /=, /) tBinOpNo(operator%, %=, %)\ntBinOp(operator^, ^=)\
    \ tBinOp(operator|, |=) tBinOp(operator&, &=)\ntBinOpNo(operator<<, <<=, <<) tBinOpNo(operator>>,\
    \ >>=, <<)\ntIncDec(operator++, ++) tIncDec(operator--, --)\ntemplate <typename...\
    \ Ts> tuple<Ts...> operator-(tuple<Ts...> t) {\n  for_each(t, [](auto& x, int)\
    \ { x = -x; });\n  return t;\n}\ntemplate <typename... Ts> tuple<Ts...> operator+(tuple<Ts...>\
    \ t) {\n  for_each(t, [](auto& x, int) { x = +x; });\n  return t;\n}\n"
  code: "#include \"../template_long.cc\"\n\n///////////////////////////////////////////////////////////////\n\
    // Utility functions.\n///////////////////////////////////////////////////////////////\n\
    \nnamespace impl {\n  template <typename T, typename U, typename F, size_t...\
    \ Is>\n  T zipWith(const T& t, const U& u, F f, index_sequence<Is...>) { \n  \
    \  return mt((static_cast<tuple_element_t<Is, T>>(f(get<Is>(t), get<Is>(u), Is)))...);\n\
    \  }\n\n  template <typename T, typename U, typename F, size_t... Is>\n  F for_each_2t(T&\
    \ t, const U& u, F f, index_sequence<Is...>) {\n    auto l = { (f(get<Is>(t),\
    \ get<Is>(u)), 0)... };\n    (void) l;\n    return f;\n  }\n}\n\ntemplate <typename...\
    \ Ts, typename... Us, typename F>\ntuple<Ts...> zipWith(const tuple<Ts...>& t,\
    \ const tuple<Us...>& u, F f) { \n  static_assert(sizeof...(Ts) == sizeof...(Us),\
    \ \"Tuples must be the same size\");\n  return impl::zipWith(t, u, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\ntemplate <typename... Ts, typename... Us, typename F>\nF for_each_2t(tuple<Ts...>&\
    \ t, const tuple<Us...>& u, F f) { \n  static_assert(sizeof...(Ts) == sizeof...(Us),\
    \ \"Tuples must be the same size\");\n  return impl::for_each_2t(t, u, f, make_index_sequence<sizeof...(Ts)>{});\n\
    }\n\ntemplate <typename T> true_type tuple_size_check(typename tuple_size<T>::type*);\n\
    template <typename T> false_type tuple_size_check(...);\ntemplate <typename T>\
    \ struct IsT : decltype(tuple_size_check<T>(nullptr)) {};\ntemplate <typename\
    \ T> true_type stream_check(typename T::off_type*);\ntemplate <typename T> false_type\
    \ stream_check(...);\ntemplate <typename T> struct IsSt : decltype(stream_check<T>(nullptr))\
    \ {};\ntemplate <typename T> struct IsS : integral_constant<bool, IsT<T>::value\
    \ or IsC<T>::value or IsSt<T>::value> {};\n\n#define vAssignmentOpF(name) \\\n\
    \  template <typename T, typename U> \\\n  vector<T>& name(vector<T>&, const U&);\
    \ \\\n  template <typename T, typename U> \\\n  vector<T>& name(vector<T>&, const\
    \ vector<U>&);\n\n#define vAssignmentOp(name, op)     \\\n  template <typename\
    \ T, typename U> \\\n  vector<T>& name(vector<T>& v, const U& x) { \\\n    for\
    \ (auto& i : v) i op x; \\\n    return v; \\\n  } \\\n  template <typename T,\
    \ typename U> \\\n  vector<T>& name(vector<T>& v, const vector<U>& w) { \\\n \
    \   F0R (i, min(SZ(v), SZ(w))) v[i] op w[i]; \\\n    return v; \\\n  }\n\n#define\
    \ vIncDecF(name) \\\n  template<typename T> \\\n  vector<T>& name(vector<T>&);\
    \ \\\n  template<typename T> \\\n  vector<T> name(vector<T>&, int);\n\n#define\
    \ vIncDec(name, op)     \\\n  template<typename T> \\\n  vector<T>& name(vector<T>&\
    \ v) { \\\n    for (auto& x : v) op x; \\\n    return v; \\\n  } \\\n  template<typename\
    \ T> \\\n  vector<T> name(vector<T>& v, int) { \\\n    vector<T> t{v}; \\\n  \
    \  op v; \\\n    return t; \\\n  }\n\n#define vBinOpF(name) \\\n  template <typename\
    \ T, typename U> \\\n  vector<T> name(vector<T>, const vector<U>&); \\\n  template\
    \ <typename T, typename U> \\\n  vector<T> name(vector<T>, const U&); \\\n  template\
    \ <typename T, typename U> \\\n  enable_if_t<!IsS<U>::value, vector<T>> \\\n \
    \ name(const U&, vector<T>);\n\n#define vBinOp(name, op) \\\n  template <typename\
    \ T, typename U> \\\n  vector<T> name(vector<T> v, const vector<U>& u) { return\
    \ v op u; } \\\n  template <typename T, typename U> \\\n  vector<T> name(vector<T>\
    \ v, const U& u) { return v op u; } \\\n  template <typename T, typename U> \\\
    \n  enable_if_t<!IsS<U>::value, vector<T>> \\\n  name(const U& u, vector<T> v)\
    \ { return v op u; }\n\n#define vBinOpNo(name, op, ex) \\\n  template <typename\
    \ T, typename U> \\\n  vector<T> name(vector<T> v, const vector<U>& u) { return\
    \ v op u; } \\\n  template <typename T, typename U> \\\n  vector<T> name(vector<T>\
    \ v, const U& u) { return v op u; } \\\n  template <typename T, typename U> \\\
    \n  enable_if_t<!IsS<U>::value, vector<T>> \\\n  name(const U& u, vector<T> v)\
    \ { for (auto& i : v) i = u ex i; return v; }\n\n#define pAssignmentOpF(name)\
    \ \\\n  template <typename T1, typename T2, typename U1, typename U2> \\\n  pair<T1,\
    \ T2>& name(pair<T1, T2>&, const pair<U1, U2>&); \\\n  template <typename T1,\
    \ typename T2, typename U> \\\n  pair<T1, T2>& name(pair<T1, T2>&, const U&);\
    \ \n\n#define pAssignmentOp(name, op) \\\n  template <typename T1, typename T2,\
    \ typename U1, typename U2> \\\n  pair<T1, T2>& name(pair<T1, T2>& p1, const pair<U1,\
    \ U2>& p2) { \\\n    p1.fi op p2.fi; p1.se op p2.se; return p1; \\\n  } \\\n \
    \ template <typename T1, typename T2, typename U> \\\n  pair<T1, T2>& name(pair<T1,\
    \ T2>& p, const U& u) { \\\n    p.fi op u; p.se op u; return p; \\\n  }\n\n#define\
    \ pIncDecF(name) \\\n  template<typename T1, typename T2> \\\n  pair<T1, T2>&\
    \ name(pair<T1, T2>&); \\\n  template<typename T1, typename T2> \\\n  pair<T1,\
    \ T2> name(pair<T1, T2>&, int);\n\n#define pIncDec(name, op) \\\n  template<typename\
    \ T1, typename T2> \\\n  pair<T1, T2>& name(pair<T1, T2>& p) { \\\n    op p.fi;\
    \ op p.se; \\\n    return p; \\\n  } \\\n  template<typename T1, typename T2>\
    \ \\\n  pair<T1, T2> name(pair<T1, T2>& p, int) { \\\n    pair<T1, T2> t{p}; \\\
    \n    op p; \\\n    return t; \\\n  }\n\n#define pBinOpF(name) \\\n  template\
    \ <typename T1, typename T2, typename U1, typename U2> \\\n  pair<T1, T2> name(pair<T1,\
    \ T2>, const pair<U1, U2>&); \\\n  template <typename T1, typename T2, typename\
    \ U> \\\n  pair<T1, T2> name(pair<T1, T2>, const U&); \\\n  template <typename\
    \ T1, typename T2, typename U> \\\n  enable_if_t<!IsS<U>::value, pair<T1, T2>>\
    \ \\\n  name(const U&, pair<T1, T2>);\n\n#define pBinOp(name, op) \\\n  template\
    \ <typename T1, typename T2, typename U1, typename U2> \\\n  pair<T1, T2> name(pair<T1,\
    \ T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \\\n  template <typename\
    \ T1, typename T2, typename U> \\\n  pair<T1, T2> name(pair<T1, T2> p, const U&\
    \ u) { return p op u; } \\\n  template <typename T1, typename T2, typename U>\
    \ \\\n  enable_if_t<!IsS<U>::value, pair<T1, T2>> \\\n  name(const U& u, pair<T1,\
    \ T2> p) { return p op u; }\n\n#define pBinOpNo(name, op, ex) \\\n  template <typename\
    \ T1, typename T2, typename U1, typename U2> \\\n  pair<T1, T2> name(pair<T1,\
    \ T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \\\n  template <typename\
    \ T1, typename T2, typename U> \\\n  pair<T1, T2> name(pair<T1, T2> p, const U&\
    \ u) { return p op u; } \\\n  template <typename T1, typename T2, typename U>\
    \ \\\n  enable_if_t<!IsS<U>::value, pair<T1, T2>> \\\n  name(const U& u, pair<T1,\
    \ T2> p) { p.fi = u ex p.fi; p.se = u ex p.se; }\n\n#define tAssignmentOpF(name)\
    \ \\\n  template <typename... Ts, typename U> \\\n  tuple<Ts...>& name(tuple<Ts...>&,\
    \ const U&); \\\n  template <typename... Ts, typename... Us> \\\n  tuple<Ts...>&\
    \ name(tuple<Ts...>&, const tuple<Us...>&);\n\n#define tAssignmentOp(name, op)\
    \     \\\n  template <typename... Ts, typename U> \\\n  tuple<Ts...>& name(tuple<Ts...>&\
    \ t, const U& u) { \\\n    for_each(t, [&](auto& x, int) { x op u; }); \\\n  \
    \  return t; \\\n  } \\\n  template <typename... Ts, typename... Us> \\\n  tuple<Ts...>&\
    \ name(tuple<Ts...>& t1, const tuple<Us...>& t2) { \\\n    for_each_2t(t1, t2,\
    \ [](auto& x, const auto& y) { x op y; }); \\\n    return t1; \\\n  }\n\n#define\
    \ tIncDecF(name) \\\n  template<typename... Ts> \\\n  tuple<Ts...>& name(tuple<Ts...>&);\
    \ \\\n  template<typename... Ts> \\\n  tuple<Ts...> name(tuple<Ts...>&, int);\n\
    \n#define tIncDec(name, op)     \\\n  template<typename... Ts> \\\n  tuple<Ts...>&\
    \ name(tuple<Ts...>& t) { \\\n    for_each(t,  [](auto& x, int) { op x; }); \\\
    \n    return t; \\\n  } \\\n  template<typename... Ts> \\\n  tuple<Ts...> name(tuple<Ts...>&\
    \ t, int) { \\\n    tuple<Ts...> tp{t}; \\\n    op t; \\\n    return tp; \\\n\
    \  }\n\n#define tBinOpF(name) \\\n  template <typename... Ts, typename... Us>\
    \ \\\n  tuple<Ts...> name(tuple<Ts...>, const tuple<Us...>&); \\\n  template <typename...\
    \ Ts, typename U> \\\n  tuple<Ts...> name(tuple<Ts...>, const U&); \\\n  template\
    \ <typename... Ts, typename U> \\\n  enable_if_t<!IsS<U>::value, tuple<Ts...>>\
    \ \\\n  name(const U&, tuple<Ts...>);\n\n#define tBinOp(name, op) \\\n  template\
    \ <typename... Ts, typename... Us> \\\n  tuple<Ts...> name(tuple<Ts...> t, const\
    \ tuple<Us...>& u) {return t op u; } \\\n  template <typename... Ts, typename\
    \ U> \\\n  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \\\
    \n  template <typename... Ts, typename U> \\\n  enable_if_t<!IsS<U>::value, tuple<Ts...>>\
    \ \\\n  name(const U& u, tuple<Ts...> t) { return t op u; }\n\n#define tBinOpNo(name,\
    \ op, ex) \\\n  template <typename... Ts, typename... Us> \\\n  tuple<Ts...> name(tuple<Ts...>\
    \ t, const tuple<Us...>& u) {return t op u; } \\\n  template <typename... Ts,\
    \ typename U> \\\n  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op\
    \ u; } \\\n  template <typename... Ts, typename U> \\\n  enable_if_t<!IsS<U>::value,\
    \ tuple<Ts...>> \\\n  name(const U& u, tuple<Ts...> t) { for_each(t, [&](auto&\
    \ x, int) { x = u ex x; }); return t; }\n\n// vector forward declarations\nvAssignmentOpF(operator+=)\
    \ vAssignmentOpF(operator-=)\nvAssignmentOpF(operator*=) vAssignmentOpF(operator/=)\
    \ vAssignmentOpF(operator%=)\nvAssignmentOpF(operator^=) vAssignmentOpF(operator|=)\
    \ vAssignmentOpF(operator&=)\nvAssignmentOpF(operator<<=) vAssignmentOpF(operator>>=)\n\
    vBinOpF(operator+) vBinOpF(operator-)\nvBinOpF(operator*) vBinOpF(operator/) vBinOpF(operator%)\n\
    vBinOpF(operator^) vBinOpF(operator|) vBinOpF(operator&)\nvBinOpF(operator<<)\
    \ vBinOpF(operator>>)\nvIncDecF(operator++) vIncDecF(operator--)\ntemplate <typename\
    \ T> vector<T> operator-(vector<T> v);\ntemplate <typename T> vector<T> operator+(vector<T>\
    \ v);\n\n// pair forward declarations\npAssignmentOpF(operator+=) pAssignmentOpF(operator-=)\n\
    pAssignmentOpF(operator*=) pAssignmentOpF(operator/=) pAssignmentOpF(operator%=)\n\
    pAssignmentOpF(operator^=) pAssignmentOpF(operator|=) pAssignmentOpF(operator&=)\n\
    pAssignmentOpF(operator<<=) pAssignmentOpF(operator>>=)\npBinOpF(operator+) pBinOpF(operator-)\n\
    pBinOpF(operator*) pBinOpF(operator/) pBinOpF(operator%)\npBinOpF(operator^) pBinOpF(operator|)\
    \ pBinOpF(operator&)\npBinOpF(operator<<) pBinOpF(operator>>)\npIncDecF(operator++)\
    \ pIncDecF(operator--)\ntemplate <typename T1, typename T2>\npair<T1, T2> operator-(const\
    \ pair<T1, T2>& p);\ntemplate <typename T1, typename T2>\npair<T1, T2> operator+(const\
    \ pair<T1, T2>& p);\n\n// tuple forward declarations\ntAssignmentOpF(operator+=)\
    \ tAssignmentOpF(operator-=)\ntAssignmentOpF(operator*=) tAssignmentOpF(operator/=)\
    \ tAssignmentOpF(operator%=)\ntAssignmentOpF(operator^=) tAssignmentOpF(operator|=)\
    \ tAssignmentOpF(operator&=)\ntAssignmentOpF(operator<<=) tAssignmentOpF(operator>>=)\n\
    tBinOpF(operator+) tBinOpF(operator-)\ntBinOpF(operator*) tBinOpF(operator/) tBinOpF(operator%)\n\
    tBinOpF(operator^) tBinOpF(operator|) tBinOpF(operator&)\ntBinOpF(operator<<)\
    \ tBinOpF(operator>>)\ntIncDecF(operator++) tIncDecF(operator--)\ntemplate <typename...\
    \ Ts> tuple<Ts...> operator-(tuple<Ts...> v);\ntemplate <typename... Ts> tuple<Ts...>\
    \ operator+(tuple<Ts...> v);\n\n// vector implementation\nvAssignmentOp(operator+=,\
    \ +=) vAssignmentOp(operator-=, -=)\nvAssignmentOp(operator*=, *=) vAssignmentOp(operator/=,\
    \ /=) vAssignmentOp(operator%=, %=)\nvAssignmentOp(operator^=, ^=) vAssignmentOp(operator|=,\
    \ |=) vAssignmentOp(operator&=, &=)\nvAssignmentOp(operator<<=, <<=) vAssignmentOp(operator>>=,\
    \ >>=)\nvBinOp(operator+, +=) vBinOpNo(operator-, -=, -)\nvBinOp(operator*, *=)\
    \ vBinOpNo(operator/, /=, /) vBinOpNo(operator%, %=, %)\nvBinOp(operator^, ^=)\
    \ vBinOp(operator|, |=) vBinOp(operator&, &=)\nvBinOpNo(operator<<, <<=, <<) vBinOpNo(operator>>,\
    \ >>=, <<)\nvIncDec(operator++, ++) vIncDec(operator--, --)\ntemplate <typename\
    \ T> vector<T> operator-(vector<T> v) {\n  for (auto& i : v) i = -i;\n  return\
    \ v;\n}\ntemplate <typename T> vector<T> operator+(vector<T> v) {\n  for (auto&\
    \ i : v) i = +i;\n  return v;\n}\n\n// pair implementation\npAssignmentOp(operator+=,\
    \ +=) pAssignmentOp(operator-=, -=)\npAssignmentOp(operator*=, *=) pAssignmentOp(operator/=,\
    \ /=) pAssignmentOp(operator%=, %=)\npAssignmentOp(operator^=, ^=) pAssignmentOp(operator|=,\
    \ |=) pAssignmentOp(operator&=, &=)\npAssignmentOp(operator<<=, <<=) pAssignmentOp(operator>>=,\
    \ >>=)\npBinOp(operator+, +=) pBinOpNo(operator-, -=, -)\npBinOp(operator*, *=)\
    \ pBinOpNo(operator/, /=, /) pBinOpNo(operator%, %=, %)\npBinOp(operator^, ^=)\
    \ pBinOp(operator|, |=) pBinOp(operator&, &=)\npBinOpNo(operator<<, <<=, <<) pBinOpNo(operator>>,\
    \ >>=, <<)\npIncDec(operator++, ++) pIncDec(operator--, --)\ntemplate <typename\
    \ T1, typename T2>\npair<T1, T2> operator-(const pair<T1, T2>& p) { return mp(-p.fi,\
    \ -p.se); }\ntemplate <typename T1, typename T2>\npair<T1, T2> operator+(const\
    \ pair<T1, T2>& p) { return mp(+p.fi, +p.se); }\n\n// tuple implementation\ntAssignmentOp(operator+=,\
    \ +=) tAssignmentOp(operator-=, -=)\ntAssignmentOp(operator*=, *=) tAssignmentOp(operator/=,\
    \ /=) tAssignmentOp(operator%=, %=)\ntAssignmentOp(operator^=, ^=) tAssignmentOp(operator|=,\
    \ |=) tAssignmentOp(operator&=, &=)\ntAssignmentOp(operator<<=, <<=) tAssignmentOp(operator>>=,\
    \ >>=)\ntBinOp(operator+, +=) tBinOpNo(operator-, -=, -)\ntBinOp(operator*, *=)\
    \ tBinOpNo(operator/, /=, /) tBinOpNo(operator%, %=, %)\ntBinOp(operator^, ^=)\
    \ tBinOp(operator|, |=) tBinOp(operator&, &=)\ntBinOpNo(operator<<, <<=, <<) tBinOpNo(operator>>,\
    \ >>=, <<)\ntIncDec(operator++, ++) tIncDec(operator--, --)\ntemplate <typename...\
    \ Ts> tuple<Ts...> operator-(tuple<Ts...> t) {\n  for_each(t, [](auto& x, int)\
    \ { x = -x; });\n  return t;\n}\ntemplate <typename... Ts> tuple<Ts...> operator+(tuple<Ts...>\
    \ t) {\n  for_each(t, [](auto& x, int) { x = +x; });\n  return t;\n}\n"
  dependsOn:
  - code/template_long.cc
  isVerificationFile: false
  path: code/utils/ops.cc
  requiredBy: []
  timestamp: '2024-04-19 13:55:53+02:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/utils/ops.cc
layout: document
redirect_from:
- /library/code/utils/ops.cc
- /library/code/utils/ops.cc.html
title: code/utils/ops.cc
---
