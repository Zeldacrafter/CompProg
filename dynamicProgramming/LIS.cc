#include "../template.cc"
void LIS(const vi& A) {
  int len = 0, lis_end = 0, n = SZ(A);
  vi p(n, -1);
  vii L(n);

  F0R (i, n) {
    int pos =
        lower_bound(L.begin(),
                    L.begin() + len, A[i],
                    [](const ii& a, int b) {
                      return a.fi < b;
                    }) -
        L.begin();
    L[pos] = mp(A[i], i);
    p[i] = pos ? L[pos - 1].se : -1;
    if (pos == len) {
      ++len;
      lis_end = i;
    }
  }

  cout << "Length of LIS is " << len << ": ";
  stack<int> s;
  for (int x = lis_end; x != -1; x = p[x])
    s.push(A[x]);
  for (; !s.empty(); s.pop(), cout << ' ')
    cout << s.top();
}
