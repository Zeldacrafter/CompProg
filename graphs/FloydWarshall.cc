#include "../template.cc"
const int V = 500;  // size of graph
int adjMat[V][V];
void floydWarshall() {
  F0R (k, V)
    F0R (i, V)
      F0R (j, V)
        adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
}
