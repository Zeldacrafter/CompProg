const int N = 1e7;
int lp[N+1];
void sieve() {
    vector<ll> pr;

    FOR(i, 2LL, N + 1) {
        if (!lp[i]) {
            lp[i] = i;
            pr.pb(i);
        }
        for (ll j = 0; i < SZ(pr) && pr[j] <= lp[i] && i*pr[j] <= N; ++j)
            lp[i + pr[j]] = pr[j];
    }
}
