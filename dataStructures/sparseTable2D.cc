#include "../utils/bits.cc"
const int MAX_N = 100;
const int LOG2_N = 7;
const int MAX_M = 100;
const int LOG2_M = 7;

int spT[MAX_N + 1][LOG2_N + 1][MAX_M + 1][LOG2_M + 1];
void build(int A[MAX_N][MAX_M], int n, int m) {
  F0R (ir, n) {
    F0R (ic, m)
      spT[ir][0][ic][0] = A[ir][ic];

    for (int jc = 1; (1 << jc) <= m; ++jc)
      for (int ic = 0; ic + (1 << jc) <= m; ++ic)
        spT[ir][0][ic][jc] =
            min(spT[ir][0][ic][jc - 1],
                spT[ir][0][ic + (1 << (jc - 1))][jc - 1]);
  }

  for (int jr = 1; (1 << jr) <= n; ++jr)
    for (int ir = 0; ir + (1 << jr) <= n; ++ir)
      for (int jc = 0; (1 << jc) <= m; ++jc)
        for (int ic = 0; ic + (1 << jc) <= m; ++ic)
          spT[ir][jr][ic][jc] =
              min(spT[ir][jr - 1][ic][jc],
                  spT[ir + (1 << (jr - 1))][jr - 1][ic][jc]);
}

int rmq(int r1, int r2, int c1, int c2) {
  int rk = 31 - __builtin_clz(r2 - r1 + 1);
  int ck = 31 - __builtin_clz(c2 - c1 + 1);

  int cc = c2 - (1 << ck) + 1;
  int rr = r2 - (1 << rk) + 1;
  return min(min(spT[r1][rk][c1][ck], spT[r1][rk][cc][ck]),
             min(spT[rr][rk][c1][ck], spT[rr][rk][cc][ck]));
}
