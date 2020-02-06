#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
int N;
vector<vi> adj_list(N);
vi in(N);  // number of edges to i
int main() {
    queue<int> q;
    for (int i = 0; i < N; ++i)
        if (in[i] == 0) q.push(i);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        printf("%d\n", i);
        for (int j : adj_list[i])
            if (--in[j] == 0) q.push(j);
    }
}
