#include "../utils/bits.cc"
const int MAX_N = 100;
const int LOG2_N = 7;

int spT[MAX_N][LOG2_N + 1];  // Min value
int idx[MAX_N][LOG2_N + 1];  // Index of min

void build(int A[], int n) {
  F0R (i, n)
    spT[i][0] = A[i], idx[i][0] = i;

  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i) {
      int k = i + (1 << (j - 1));
      if (spT[i][j - 1] < spT[k][j - 1]) {
        spT[i][j] = spT[i][j - 1];
        idx[i][j] = idx[i][j - 1];
      } else {
        spT[i][j] = spT[k][j - 1];
        idx[i][j] = idx[k][j - 1];
      }
    }
}

int rmq(int l, int r) {
  int k = msbIndex(r - l + 1);
  return min(spT[l][k],
             spT[r - (1 << k) + 1][k]);
}
