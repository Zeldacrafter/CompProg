#include "../template.hh"
template <typename T, int E = 26, typename V = char, V base = 'a'>
struct Trie {
  using str = basic_string<V>;
  vector<array<int, E>> nxt;
  vector<T> v;
  Trie() : nxt{array<int, E>{}}, v(1, -1) {}
  void set(const str& s, T val) {
    int it = 0;
    for (V c : s) {
      if (!nxt[it][c - base]) {
        nxt[it][c - base] = SZ(nxt);
        nxt.eb();
        v.eb();
      }
      it = nxt[it][c - base];
    }
    v[it] = val;
  }
  T get(const str& s) {
    int it = 0;
    for (V c : s) {
      if (!nxt[it][c - base]) return T();
      it = nxt[it][c - base];
    }
    return v[it];
  }
};
