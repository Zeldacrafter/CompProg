void floydWarshall() {
  for (int k = 0; k < V; ++k)
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j)
        adjMat[i][j] =
            min(adjMat[i][j],
                adjMat[i][k] + adjMat[k][j]);
}
