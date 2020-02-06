int N;
vvi adj(N);
vi in(N);  // in degree for every node
int main() {
  queue<int> q;
  for (int i = 0; i < N; ++i)
    if (in[i] == 0) q.push(i);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << '\n';
    for (int v : adj[curr])
      if (--in[v] == 0) q.push(v);
  }
}
