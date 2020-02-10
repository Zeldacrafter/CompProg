ll onEdge(vii pts) {
    //Assume pts[0] = pts[pts.size() - 1]
    ll res = pts.size();
    F0R(i, pts.size() - 1)
        res += abs(gcd(
                pts[i].fi - pts[i + 1].fi,
                pts[i].se - pts[i + 1].se);
    return res;
}
