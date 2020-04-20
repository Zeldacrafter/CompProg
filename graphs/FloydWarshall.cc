#include "../template.cc"
void floydWarshall() {
  F0R (k, V)
    F0R (i, V)
      F0R (j, V)
        adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}
