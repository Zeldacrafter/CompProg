vii adj;
bitset<..> visited;
void dfs(int curr) {
    visited[curr] = true;
    for(int v : adj[curr])
        if(!visited[v])
            dfs(v);
}
