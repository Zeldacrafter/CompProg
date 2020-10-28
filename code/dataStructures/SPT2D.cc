#include "../utils/bits.cc"

typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
struct SPT2D {
  vvvvi spT;
  int n, m, log2n, log2m;

  SPT2D(vvi& A) : n(SZ(A)), m(SZ(A[0])),
        log2n(33 - __builtin_clz(n)),
        log2m(33 - __builtin_clz(m)) {
    spT.assign(n, vvvi(log2n, vvi(m, vi(log2m))));

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

  int query(int r1, int r2, int c1, int c2) { //r2, c2 are exclusive
    int rk = 31 - __builtin_clz(r2 - r1);
    int ck = 31 - __builtin_clz(c2 - c1);

    int cc = c2 - (1 << ck);
    int rr = r2 - (1 << rk);
    return min({spT[r1][rk][c1][ck], spT[r1][rk][cc][ck],
                spT[rr][rk][c1][ck], spT[rr][rk][cc][ck]});
  }
};
