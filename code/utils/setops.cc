#include "../template.hh"
template<typename T>
set<T>& operator+=(set<T>& s, const T& e) {
  return s.insert(e), s;
}
template<typename T>
set<T>& operator-=(set<T>& s, const T& e) {
  return s.erase(e), s;
}
template<typename T>
set<T>& operator&=(set<T>& a, const set<T>& b) {
  set<T> o;
  set_intersection(ALL(a), ALL(b), inserter(o, o.begin()));
  return a.swap(o), a;
}
template<typename T>
set<T>& operator|=(set<T>& a, const set<T>& b) {
  return a.insert(ALL(b)), a;
}
template<typename T>
set<T> operator&(set<T> a, const set<T>& b) {
  return a &= b;
}
template<typename T>
set<T> operator|(set<T> a, const set<T>& b) {
  return a |= b;
}
template<typename T>
bool operator<(const set<T>& s, const T& e) {
  return static_cast<bool>(s.count(e));
}
