void SolveForCoefficients(const vi& x,
                          vi& y) {
  // p(x[i]) = y[i]. All pairs need to be
  // distinct. coefficients gets saved in y
  // Applicable for any field. Not just
  // int/reals.
  int n = x.size();
  for (int i = 0; i < n - 1; i = i + 1)
    for (int j = i + 1; j < n; j = j + 1)
      y[j] = (y[j] - y[i]) / (x[j] - x[i]);
  for (int i = n - 2; i >= 0; i = i - 1)
    for (int j = i; j < n - 1; j = j + 1)
      y[j] = y[j] - (x[i] * y[j + 1]);
}
