__int128 a;
unsigned __int128 b;
void print_it(
    unsigned __int128
        n) {  // 128 bit ints dont have a
              // default print routine
  if (n < 0) {
    cout << '-';
    n *= -1;
  }
  ll mod = 1000000000000000000;
  string str;
  do {
    unsigned ll digits = n % mod;
    string digitStr = to_string(digits);
    string leading0s =
        (digits != n)
            ? string(18 - digitStr.length(),
                     '0')
            : "";
    str = leading0s + digitStr + str;
    n = (n - digits) / mod;
  } while (n);
  cout << str;
}
