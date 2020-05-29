#include "../template.cc"
struct SPT {
  vvi spT, idx; // min value, pos of min value
  SPT(vi& A) {
    const int logn = ceil(log2l(SZ(A))) + 1;
    spT.assign(SZ(A), vi(logn));
    idx.assign(SZ(A), vi(logn));
    F0R (i, SZ(A)) spT[i][0] = A[i], idx[i][0] = i;
    for (int j = 1; (1 << j) <= SZ(A); ++j)
      for (int i = 0; i + (1 << j) <= SZ(A); ++i) {
        int k = i + (1 << (j - 1));
        spT[i][j] = spT[k][j - 1], idx[i][j] = idx[k][j - 1];
        if (ckmin(spT[i][j], spT[i][j - 1])) idx[i][j] = idx[i][j - 1];
    }
  }
  ii rmq(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(mp(spT[l][k], idx[l][k]),
               mp(spT[r - (1 << k) + 1][k], idx[r - (1 << k) + 1][k]));
  }
};
