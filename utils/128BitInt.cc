#include "../template.cc"
__uint128_t a;
__int128_t b;
void print_it(__int128_t n) {
  if (n < 0) {
    cout << '-';
    n *= -1;
  }
  ll mod = 1e18;
  string s;
  do {
    unsigned long long digits = n % mod;
    string dStr = to_string(digits);
    if (digits != n)
      s = string(18 - dStr.length(), '0') + dStr + s;
    else
      s = dStr + s;
    n = (n - digits) / mod;
  } while (n);
  cout << s;
}
