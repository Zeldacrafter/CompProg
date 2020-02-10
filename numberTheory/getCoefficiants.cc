void getCoefficients(const vi& x, vi& y) {
  int n = x.size();
  F0R(i, n - 1)
    FOR(j, i + 1, n)
      y[j] = (y[j] - y[i]) / (x[j] - x[i]);
  R0F(i, n - 2)
    FOR(j, i, n - 1)
      y[j] = y[j] - (x[i] * y[j + 1]);
}
