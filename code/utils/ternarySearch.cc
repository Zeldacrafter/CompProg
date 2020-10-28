#include "../template.cc"
// f unimodal function on [l, r]
double terSearch(double l, double r, function<double(double)> f,
                 bool mx = true) {
  const double eps = 1e-9;
  while (abs(r - l) > eps) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    if (mx == (f(m1) < f(m2))) l = m1;
    else r = m2;
  }
  return l;
}
