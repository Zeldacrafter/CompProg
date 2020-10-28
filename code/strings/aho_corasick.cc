#include "../template.cc"

template <typename T, int E = 26, typename V = char, V base = 'a'>
struct AHC {
  using str = basic_string<V>;

  T e;
  vector<array<int, E>> nxt;
  vi fail;
  vector<T> val;

  AHC(T _e) 
      : e{_e}, nxt(1, array<int, E>()), fail(1, 0), val(1, e) {}
  AHC(T _e, const vector<pair<str, T>>& strs) 
      : e{_e}, nxt(1, array<int, E>()), fail(1, 0), val(1, e) {
    for (const auto& [s, v] : strs) insert(s, v);
    build();
  }

  void reserve(size_t sz) {
    nxt.reserve(sz);
    fail.reserve(sz);
    val.reserve(sz);
  }

  void insert(const str& s, T v) {
    int curr = 0;
    for (V c : s) {
      if (!nxt[curr][c - base]) {
        nxt[curr][c - base] = SZ(nxt);
        nxt.eb();
        val.pb(e);
      }
      curr = nxt[curr][c - base];
    }
    val[curr] += v;
  }

  void build() {
    fail.assign(SZ(nxt), 0);
    queue<int> q;
    F0R (i, E)
      if (nxt[0][i]) q.push(nxt[0][i]);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      F0R (i, E) {
        if (nxt[curr][i]) {
          fail[nxt[curr][i]] = nxt[fail[curr]][i];
          val[nxt[curr][i]] += val[nxt[fail[curr]][i]];
          q.push(nxt[curr][i]);
        } else
          nxt[curr][i] = nxt[fail[curr]][i];
      }
    }
  }

  T query(const str& s) {
    int curr = 0;
    T res = e;
    for (V c : s) {
      if (nxt[curr][c - base])
        curr = nxt[curr][c - base];
      else
        while (curr && !nxt[curr][c - base]) curr = fail[curr];
      res += val[curr];
    }
    return res;
  }
};
