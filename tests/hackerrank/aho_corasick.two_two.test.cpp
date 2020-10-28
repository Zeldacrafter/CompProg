#define PROBLEM "https://www.hackerrank.com/challenges/two-two/problem"

#include "../../code/strings/aho_corasick.cc"
#include "../../code/utils/bigint.cc"

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<pair<basic_string<char>, int>> strs;

    bigint x = 1;
    F0R(i, 801) {
        strs.eb(to_string(x), 1);
        x *= 2;
    }
    //for(auto [a, b] : strs) cout << a << endl;

    AHC<int, 10, char, '0'> ahc(0, strs);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << ahc.query(s) << endl;
    }
}
