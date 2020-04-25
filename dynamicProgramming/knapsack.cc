#include "../template.cc"
const int ninf = -1e9;
vector<vi> A(1000, vi(31000, ninf));
vii I(1000);  // {weight, profit}
int N;
// Call with (0, Budget)
int value(int id, int avaiW) {
  if (avaiW < 0) return ninf;
  if (!avaiW || id == N) return 0;
  if (A[id][avaiW] > 0) return A[id][avaiW];
  return A[id][avaiW] =
             max(value(id + 1, avaiW),
                 value(id + 1, avaiW - I[id].se) + I[id].fi);
}
