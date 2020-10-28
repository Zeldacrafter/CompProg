/*
 *
 */
#include "../template.hh"

template<typename T>
struct Combinatorics {
    static vector<T> facs, der;
    static vector<vector<T>> ch, eul, stir1, stir2;

    static void precompFac(int maxN) { fac(maxN); }

    static T fac(int n) {
        facs.reserve(n + 1);
        if(!SZ(facs)) facs.pb(1);
        while(SZ(facs) <= n) facs.pb(facs.back() * SZ(facs));
        return facs[n];
    }

    static void precompChoose(int maxN) {
        int oldN = SZ(ch);
        ch.resize(max(oldN, maxN)); 
        if(!oldN) ch[0].pb(1);
        FOR(n, oldN + 1, maxN + 1) {
            ch[n].reserve(n + 1);
            ch[n].pb(1);
            FOR(k, 1, n)
                ch[n].pb(ch[n - 1][k - 1] + ch[n - 1][k]);
            ch[n].pb(1);
        }
    }

    static T choose(int n, int k) {
        assert(n >= k);
        if(SZ(ch) >= n) return ch[n][k];
        if(SZ(facs) >= n) return facs[n]/(facs[n - k]*facs[k]);
        T res = 1;
        FOR(i, n - k + 1, n + 1) res *= i;
        FOR(i, 2, k + 1) res /= i;
        return res;
    }

    static T catalan(int n) {
        return choose(2*n, n)/(n + 1);
    }

    static T precompEuler(int maxN) {
        int oldN = SZ(eul);
        eul.resize(max(oldN, maxN + 1));
        if(!oldN) eul[0].pb(1);
        FOR(n, oldN + 1, maxN + 1) {
            eul[n].reserve(n + 1);
            eul[n].pb(1);
            FOR(k, 1, n)
                eul[n].pb(k*eul[n - 1][k] + (n - k + 1)*eul[n - 1][k - 1]);
            eul[n].pb(1);
        }
    }

    static T euler(int n, int k) {
        assert(n >= k);
        if(SZ(eul) <= n) precompEuler(n);
        return eul[n][k];
    }

    static void precompStirling1(int maxN) {
        int oldN = SZ(stir1);
        stir1.resize(max(oldN, maxN + 1));
        if(!oldN) stir1[0].pb(1);
        FOR(n, 1, maxN + 1) {
            stir1[n].reserve(n + 1);
            stir1[n].pb(0);
            FOR(k, 1, n)
                stir1[n].pb(stir1[n - 1][k - 1] + (n - 1)*stir1[n - 1][k]);
            stir1[n].pb(1);
        }
    }

    static T stirling1(int n, int k) {
        assert(n >= k);
        if(SZ(stir1) <= n) precompStirling1(n);
        return stir1[n][k];
    }

    static void precompStirling2(int maxN) {
        int oldN = SZ(stir2);
        stir2.resize(max(oldN, maxN + 1));
        if(!oldN) stir2[0].pb(1);
        FOR(n, 1, maxN + 1) {
            stir2[n].reserve(n + 1);
            stir2[n].pb(0);
            FOR(k, 1, n)
                stir2[n].pb(stir2[n - 1][k - 1] + k*stir2[n - 1][k]);
            stir2[n].pb(1);
        }
    }

    static T stirling2(int n, int k) {
        if(SZ(stir2) <= n) precompStirling2(n);
        return stir2[n][k];
    }

    static void precompDerangements(int maxN) {
        if(!SZ(der)) {
            der.pb(1);
            der.pb(0);
        }
        der.reserve(maxN + 1);
        while(SZ(der) <= maxN) {
            int n = SZ(der);
            der.pb(n*(der[n - 1] + der[n - 2]));
        }
    }

    static T derangements(int n) {
        if(SZ(der) <= n) precompDerangements(n);
        return der[n];
    }
}; 

using comb = Combinatorics<ll>;
