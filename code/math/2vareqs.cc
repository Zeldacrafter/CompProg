#include "../utils/y_combinator.cc"

// Solving linear equation systems were every equation has at most 2 variables.
// Implemented the algorithm from the paper 'A Fast Algorithm for Solving
// Systems of Linear Equatlons with Two Variables per Equation' by Bengt Aspvall
// and Yossi Shiloach
// https://www.sciencedirect.com/science/article/pii/0024379580901627

template <typename T>
struct linear {  // a * x + c
  T a, c;
  linear() : a{1}, c{0} {}
  linear(const T& _a) : a{_a}, c{0} {}
  linear(const T& _a, const T& _c) : a{_a}, c{_c} {}
  T operator()(const T& x) const { return calc(x); }
  T calc(const T& x) const { return a * x + c; }
  linear combine(const linear& o) {  // o(this(x))
    return linear(o.a * a, o.a * c + o.c);
  }
  linear combine(const T& oa, const T& oc) {
    return combine(linear(oa, oc));
  }
};

template <typename T>
ostream& operator<<(ostream& o, const linear<T>& l) {
  return o << l.a << " * x + " << l.c;
}

template <>
ostream& operator<<(ostream& o, const linear<int>& l) {
  if (l.a == 0) return o << l.c;
  return o << l.a << " * x + " << l.c;
}

template <typename T>
struct eqsystem {
  int n;
  eqsystem(int _n) : n{_n} {}
  using eq = tuple<T, int, T, int, T>;  // a * x + b * y = c
  vector<eq> eqs;
  auto add(T a, int x, T b, int y, T c) -> void {
    eqs.eb(a, x, b, y, c);
  }
  auto add(T a, int x, T c) -> void { eqs.eb(0, x, a, x, c); }
  auto print() -> void {
    for (const auto& [a, x, b, y, c] : eqs) {
      cout << a << " * x_" << x << " + " << b << " * x_" << y << " = "
           << c << endl;
    }
  }
  // number of blocks,
  // vector with entries:
  //  - free variable or -1 if fixed value
  //  - linear<T> yielding the value depend on the free variable
  auto solve() -> optional<pair<vi, vector<pair<int, linear<T>>>>> {
    vvi adj(n);
    F0R (i, SZ(eqs)) {
      const auto& [a, x, b, y, c] = eqs[i];
      adj[x].pb(i);
      adj[y].pb(i);
    }
    vector<optional<linear<T>>> seen(n);
    vi found;
    optional<T> p;
    auto dfs = y_combinator([&](auto self, int v, linear<T> val) -> bool {
      found.pb(v);
      seen[v] = val;

      for (int i : adj[v]) {
        auto [a, x, b, y, c] = eqs[i];
        if (v != x) {
          swap(x, y);
          swap(a, b);
        }
        // a * x + b * y = c  <=>  y = c/b - a/b * x
        auto yval = val.combine(-a / b, c / b);
        if (seen[y]) {                 // consistency check
          if (yval.a != seen[y]->a) {  // TODO: add equality function
            T pp = -(yval.c - seen[y]->c) /
                   (yval.a - seen[y]->a);  // TODO: evil for int
            if (p and *p != pp) {
              dout << "two different values for free variable!" << endl;
              return false;
            }
            p = pp;
          } else if (yval.c != seen[y]->c) {
            dout << "contradiction for x_" << y << "!" << endl;
            return false;
          }
        } else {
          if (not self(y, yval)) return false;
        }
      }
      return true;
    });
    vector<pair<int, linear<T>>> sols(n, {-1, {}});
    vi fr;
    F0R (i, n) {
      if (not seen[i]) {
        if (not dfs(i, linear<T>{})) return {};
        if (not p) fr.pb(i);
        for (auto j : found) {
          if (p) {
            sols[j] = {-1, linear<T>{0, (*seen[j])(*p)}};
          } else {
            sols[j] = {i, *seen[j]};
          }
        }
        p.reset();
        found.clear();
      }
    }
    return pair{fr, sols};
  }
};

