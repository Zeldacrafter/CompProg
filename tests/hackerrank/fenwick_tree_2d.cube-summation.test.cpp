#define PROBLEM "https://www.hackerrank.com/challenges/cube-summation/problem"

#include "../../dataStructures/FT2D.cc"

template<typename T>
struct FT3D {
  int n;
  vector<FT2D<T>> fts;
  FT3D(int sz1, int sz2, int sz3) : n{sz1}, fts(n + 1, FT2D<T>(sz2, sz3)) {};
  T query(int i, int j1, int j2, int k1, int k2) {
    T sum = 0;
    for (--i; i >= 0; i = (i & (i + 1)) - 1) sum += fts[i].query(j1, j2, k1, k2);
    return sum;
  }
  T query(int i1, int i2, int j1, int j2, int k1, int k2) {
    return query(i2, j1, j2, k1, k2) - query(i1, j1, j2, k1, k2);
  }
  void update(int i, int j, int k, T add) {
    for (; i < n; i |= i + 1) fts[i].update(j, k, add);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  FT3D<ll> ft(n + 1, n + 1, n + 1);

  F0R(i, m) {
    string s;
    cin >> s;
    if(s == "QUERY") {
      int x1, x2, y1, y2, z1, z2;
      cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
      x1--; y1--; z1--; x2--; y2--; z2--;

      cout << ft.query(x1, x2 + 1, y1, y2 + 1, z1, z2 + 1) << endl;
    } else {
      assert(s == "UPDATE");
      int x, y, z;
      ll w;
      cin >> x >> y >> z >> w;
      x--; y--; z--;

      ll val = ft.query(x, x + 1, y, y + 1, z, z + 1);
      ft.update(x, y, z, w - val);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int tc;
  cin >> tc;
  while(tc--) solve();
}



