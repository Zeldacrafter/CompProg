#include "../template.hh"
template<typename V, typename F>
struct DSU {
  int sz;
  vi p;
  vector<V> v;
  F f;
  DSU(int size, const V& _v, F _f) :
    sz{size}, p(size, -1), v(size, _v), f{_f} {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a, b);
    p[a] += p[b], p[b] = a;
    v[a] = f(v[a], v[b]);
    return --sz, true;
  }
  int size() { return sz; }
  int size(int a) { return -p[find(a)]; }
};
