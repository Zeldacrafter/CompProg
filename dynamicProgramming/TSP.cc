vector<vi> A(12, vi(2048, -1));
vector<vi> dist(11, vi(11));  // adj matrix
int N;  // Number of stops

int tsp(int pos, int mask) {
  if ((1 << N) - 1 == mask)
    return dist[pos][0];
  if (A[pos][mask] != -1)
    return A[pos][mask];
  int minV = 100000000;
  F0R(i, N) {
    if (i != pos && !(mask & (1 << i)))
      minV = min(
          minV, dist[pos][i] +
                    tsp(i, mask | (1 << i)));
  }
  return A[pos][mask] = minV;
}
