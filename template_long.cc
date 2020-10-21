///////////////////////////////////////////////////////////////
// Long template from: https://github.com/Zeldacrafter/CompProg
//
// Feature list:
// * C++11 compatibility.
// * Various 'define'-shorthands and typedefs.
// * Output stream that is only active with 'DEBUG'-flag set.
// * Input and output stream operators for...
//   * any container with 'begin' and 'end' iterator.
//   * tuples with any amount of elements 
//     (Except for 0 elements tuples :'( ) Related: https://xkcd.com/541/
//   * pairs.
// * Line seperated and aligned output of 2D vectors.
///////////////////////////////////////////////////////////////

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
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int)(x).size()
#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR (a, 0, (b))
template <typename T>
bool ckmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <typename T>
bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

// Output to 'cerr' if 'DEBUG' flag is set. Do nothing otherwise.
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout if (DEBUG) cerr
// Output all passed variables with their corresponding name and value.
#define dvar(...) " \x1b[35m[" << #__VA_ARGS__ ": " << mt(__VA_ARGS__) << "]\x1b[0m "

///////////////////////////////////////////////////////////////
// Begin template definitions for input/output.
///////////////////////////////////////////////////////////////

// IsC indicates whether a type defines a 'const_iterator'.
// IsC::value is true if 'const_iterator' exists and false otherwise.
template <typename T> true_type const_iterator_check(typename T::const_iterator*);
template <typename T> false_type const_iterator_check(...);
template <typename T> struct IsC : decltype(const_iterator_check<T>(nullptr)) {};
// No new input/output for string as those already exist.
template <> struct IsC<string> : false_type {};

template <typename... T> using TS = tuple_size<tuple<T...>>;

///////////////////////////////////////////////////////////////
// Begin Output 
///////////////////////////////////////////////////////////////

// Forward declarations.
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream&, const C&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);

// Output routine for tuples:
// 'idx' tracks the index of the current element that we want to print.
// The last element is at index 'TS<T...>::value - 1'.

// Print the last element of the tuple.
template <size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return o << ", " << get<idx>(t) << ')';
}
// Print all but the first and last element of a tuple.
template <size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << ", " << get<idx>(t), t);
}
// Print the first element of a tuple.
template <size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << '(' << get<idx>(t), t);
}

// Print tuples with only one contained element.
// Mainly here so that 'dvar(..)' functions correctly with only one element.
template <typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
  return o << get<0>(t);
}


// Output for pairs via above defined tuple output routine.
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
  return o << mt(p.fi, p.se);
}
// Output every element in a container with 'begin' and 'end' iterators.
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(
    ostream& o, const C& c) {
  o << '[';
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    o << *it << (next(it) != c.cend() ? ", " : "");
  return o << ']';
}

///////////////////////////////////////////////////////////////
// Pretty output
///////////////////////////////////////////////////////////////

// PrettyPrint struct that contains a value to be printed and
// a list of seperators which indicate how different dimensions
// of multidimensional values should be seperated.
template <typename T, size_t N>
struct PP {
  // Value to print.
  const T& v; 
  // Pointer to next seperator.
  shared_ptr<array<string, N>> se;
  // Index of next seperator.
  size_t idx;
  PP(const T& value, shared_ptr<array<string, N>> p, size_t i = 0) 
      : v{value}, se{p}, idx{i} {}
};

// If a value is not a pair, tuple or std-library-continer just print it.
// Pairs and tuples are implemented via template specialization further down.
template <typename U, size_t M>
typename enable_if<not IsC<U>::value, ostream&>::type
operator<<(ostream& o, const PP<U, M>& p) {
  return o << p.v;
}

// Forward declarations.
template <typename T, typename U, size_t N>
ostream& operator<<(ostream&, const PP<pair<T, U>, N>&);
template <typename T, size_t N>
typename enable_if<IsC<T>::value, ostream&>::type
operator<<(ostream& o, const PP<T, N>& p);

// Prints every but the last tuple element.
template <size_t M, size_t idx = 0, typename... Ts>
typename enable_if<idx + 1 < sizeof...(Ts), ostream&>::type
operator<<(ostream& o, const PP<tuple<Ts...>, M>& p) {
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  return operator<<<M, idx + 1, Ts...>(o << PP<typename tuple_element<idx, tuple<Ts...>>::type, M>(get<idx>(p.v), p.se, p.idx + 1) << sep, p); 
}

// Prints the last element of a tuple without a seperator.
template <size_t M, size_t idx = 0, typename... Ts>
typename enable_if<idx + 1 == sizeof...(Ts), ostream&>::type
operator<<(ostream& o, const PP<tuple<Ts...>, M>& p) {
  return o << PP<typename tuple_element<idx, tuple<Ts...>>::type, M>(get<idx>(p.v), p.se, p.idx + 1);
}

// Print pairs with the specified seperator for that level.
template <typename U1, typename U2, size_t M>
ostream& operator<<(ostream& o, const PP<pair<U1, U2>, M>& p) {
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  return o << PP<U1, M>(p.v.fi, p.se, p.idx + 1) << sep
           << PP<U2, M>(p.v.se, p.se, p.idx + 1);
}

// Print std-library-container with the specified seperator.
template <typename U, size_t M>
typename enable_if<IsC<U>::value, ostream&>::type
operator<<(ostream& o, const PP<U, M>& p) {
  // Seperator for the current layer (or default)
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  // Print every container element
  for (auto it = p.v.cbegin(); it != p.v.cend(); ++it)
    o << PP<typename U::value_type, M>(*it, p.se, p.idx + 1)
      << (next(it) != p.v.cend() ? sep : "");
  return o;
}

// Function for PrettyPrinting a object with specified seperators.
// Each additional seperator specifies the seperator for one level
// further into a nested structure. Pairs, tuples and std-library-container
// cause the level to increase.
// If no seperator is specified a default of " "(space) is used.
// For example a call 
//    vector<ii> a(4, mp(1, 2));
//    cout << pp(a, " | ", "-");
// results in the output (without trailing newline)
//    1-2 | 1-2 | 1-2 | 1-2
//
// This function is the main way for a user to interface with the PrettyPrinter.
template <typename T, typename... Ts, size_t N = sizeof...(Ts)>
PP<T, N> pp(const T& value, Ts... seps) {
  return PP<T, N>(value, make_shared<array<string, N>>(array<string, N>{seps...}));
}


///////////////////////////////////////////////////////////////
// Begin Input 
///////////////////////////////////////////////////////////////

// Forward declarations.
template <typename C>
typename enable_if<IsC<C>::value, istream&>::type operator>>(istream&, C&);
template <typename T1, typename T2>
istream& operator>>(istream&, pair<T1, T2>&);

// Input routine for tuples:
// 'idx' tracks the index of the current element that we want to read.
// The last element is at index 'TS<T...>::value - 1'.

// Read the last element of the tuple.
template <size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, istream&>::type
operator>>(istream& i, tuple<T...>& t) {
  return i >> get<idx>(t);
}
// Read all but the first and last element of a tuple.
template <size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, istream&>::type
operator>>(istream& i, tuple<T...>& t) {
  return operator>><idx + 1>(i >> get<idx>(t), t);
}
// Read the first element of a tuple.
template <size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, istream&>::type
operator>>(istream& i, tuple<T...>& t) {
  return operator>><idx + 1>(i >> get<idx>(t), t);
}

// Read tuples with only one contained element. 
//   (You could also just use this thing called a 'variable')
template <typename T>
istream& operator>>(istream& i, tuple<T>& t) {
  return i >> get<0>(t);
}

// Read the contents of a 'pair' object.
template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& p) {
  return i >> p.fi >> p.se;
}

// Read containers with 'begin' and 'end' iterators.
template <typename C>
typename enable_if<IsC<C>::value, istream&>::type operator>>(istream& i, C& v) {
  for (auto& x : v) i >> x;
  return i;
}
