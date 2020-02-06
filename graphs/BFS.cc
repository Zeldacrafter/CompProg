#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
int V;
vector<vi> adj_list(V);
vi visited(V, 0), p(V, -1);
void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj_list[v])
            if (!visited[u]) q.push(u), visited[u] = 1, p[u] = v;
    }
}
int main() {
    for (int v = 0; v < V; ++v)
        if (!visited[v]) bfs(v);
}
