vector<vi> A(1000, vi(31000, NINF));
vii I(1000);  // first is weight, second is profit
int N;        // Number of Items

int value(int id, int avaiW) {  // use w/ 0, W
    if (avaiW < 0) return NINF;
    if (avaiW == 0 || id == N) return 0;
    if (A[id][avaiW] > 0) return A[id][avaiW];
    return A[id][avaiW] =
               max(value(id + 1, avaiW),
                   value(id + 1, avaiW - I[id].second) + I[id].first);
}
