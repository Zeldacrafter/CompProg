#include "../template.cc"
int N;
vvi adj(N);
vi in(N);  // in degree for every node
int main() {
  vi q; // Result saved in q
  F0R (i, N)
    if (!in[i]) q.pb(i);
  F0R (i, SZ(q))
    for (int v : adj[q[i]])
      if (!--in[v]) 
          q.pb(v);
}
