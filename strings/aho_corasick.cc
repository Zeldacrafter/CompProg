#include "../template.cc"
// First call insert() on all relevant t_i
// then call buildAC()
const int MAXN = 1e5;
int nxt[MAXN][26], fail[MAXN], val[MAXN], nodeCnt = 0;
void insert(string& s, int v) {
  int curr = 0;
  for (char c : s) {
    if (!nxt[curr][c - 'a']) nxt[curr][c - 'a'] = ++nodeCnt;
    curr = nxt[curr][c - 'a'];
  }
  val[curr] += v;
}
void buildAC() {
  queue<int> q;
  F0R (i, 26)
    if (nxt[0][i]) q.push(nxt[0][i]);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    F0R (i, 26) {
      if (nxt[curr][i]) {
        fail[nxt[curr][i]] = nxt[fail[curr]][i];
        val[nxt[curr][i]] += val[nxt[fail[curr]][i]];
        q.push(nxt[curr][i]);
      } else
        nxt[curr][i] = nxt[fail[curr]][i];
    }
  }
}
int query(string& s) {
  int curr = 0, res = 0;
  for (char c : s) {
    if (nxt[curr][c - 'a']) curr = nxt[curr][c - 'a'];
    else while (curr && !nxt[curr][c - 'a']) curr = fail[curr];
    res += val[curr];
  }
  return res;
}
