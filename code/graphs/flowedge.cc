#include "../template.hh"
template <typename F>
struct edge {
  edge(int from, int to, F capacity, F flow = 0)
      : mfrom(from), mto(to), mcapacity(capacity), mflow(flow) {}
  int mfrom, mto;
  F mcapacity, mflow;
  int other(int v) { return v == mfrom ? mto : mfrom; }
  F capacity(int v) { return v == mfrom ? mcapacity : 0; }
  F flow(int v) { return v == mfrom ? mflow : -mflow; }
  void adjust(int v, F amount) {
    mflow += v == mfrom ? amount : -amount;
  }
};
template <typename F>
ostream& operator<<(ostream& o, const edge<F>& e) {
  return o << e.mfrom << "-- " << e.mflow << '/'
           << e.mcapacity << " -->" << e.mto;
}
