#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../code/template.cc"

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int q;
  cin >> q;

  map<ll, ll> arr;
  while(q--) {
    bool c;
    cin >> c;
    if(!c) {
      ll k, v;
      cin >> k >> v;
      arr[k] = v;
    } else {
      ll k;
      cin >> k;
      cout << arr[k] << endl;
    }
  }
}


