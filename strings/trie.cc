#include "../template.cc"
vvi adj(1, vi(26, -1));
vi value(1, -1);  // -1: no value present
void insert(const string& s, int val) {
  int node = 0;
  for (char c : s) {
    if (adj[node][c - 'A'] == -1) {
      adj.eb(26, -1);
      value.eb(-1);
      adj[node][c - 'A'] = SZ(adj) - 1;
    }
    node = adj[node][c - 'A'];
  }
  value[node] = val;
}
int get(const string& s) {
  int node = 0;
  for (char c : s) {
    if (adj[node][c - 'A'] == -1) return -1;
    node = adj[node][c - 'A'];
  }
  return value[node];
}
