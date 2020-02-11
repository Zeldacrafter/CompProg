void getCoefficients(const vector<double>& x,
                     vector<double>& y) {
  F0R (i, SZ(x) - 1)
    FOR (j, i + 1, SZ(x))
      y[j] = (y[j] - y[i]) / (x[j] - x[i]);
  R0F (i, SZ(x) - 2)
    FOR (j, i, SZ(x) - 1)
      y[j] = y[j] - (x[i] * y[j + 1]);
}
