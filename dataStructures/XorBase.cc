#include "../template.cc" // https://codeforces.com/blog/entry/68953
template<size_t N>
struct BS : bitset<N> {
    friend bool operator<(const BS& a, const BS& b) {
        for(int i = N - 1; ~i; --i)
            if(a[i] != b[i])
                return b[i];
        return false;
    }
    friend bool operator>(const BS& a, const BS& b) {
        return !(a < b || a == b);
    }
    friend BS operator^(const BS& a, const BS& b) {
        return BS{static_cast<bitset<N>>(a) ^ static_cast<bitset<N>>(b)};
    }
    BS(ll k) : bitset<N>(k) {};
    BS(const bitset<N>& k) : bitset<N>(k) {};
    BS() {};
};
template<typename T = int>
struct XorBase : vector<T> {
    void apply(T& toApply) {
        for(const T& b : *this)
            ckmin(toApply, toApply ^ b);
    }
    pair<bool, vector<bool>> to(T elem) {
        vector<bool> res(SZ(*this));
        F0R(i, SZ(*this))
            res[i] = ckmin(elem, elem ^ (*this)[i]);
        return mp(elem == T(), res);
    }
    bool isIn(T toCheck) {
        apply(toCheck);
        return toCheck == T();
    }
    bool add(T toAdd) {
        apply(toAdd);
        if(toAdd != T()) this->pb(toAdd);
        return toAdd != T();
    }
    XorBase(const vector<T>& elems) {
        for(const auto& e : elems) add(e);
    }
    XorBase() {};
};
