#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
int N;
vector<vi> adj_list(N);
const int UNVISITED = 0, VISITED = 1;
vi visited(N, UNVISITED);
vi ts;  // topo sort in reverse order
void dfs(int v) {
    visited[v] = VISITED;
    for (int u : adj_list[v])
        if (visited[u] == UNVISITED) dfs(u);
    ts.push_back(v);
}
int main() {
    for (int v = 0; v < N; ++v)
        if (visited[v] == UNVISITED) dfs(v);
    for (auto it = ts.rbegin(); it != ts.rend(); ++it) printf("%d\n", *it);
}
