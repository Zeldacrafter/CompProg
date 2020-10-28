#include "bigint.cc"
void testProperties(bigint& c) {
  assert((!c.signum) == c.mag.empty());
  assert(c.mag.empty() || c.mag.back());
}
int main() {
  while (1) {
    char op;
    cin >> op;
    if (op == 'q') break;
    string a, b;
    cin >> a >> b;
    bigint aa(a), bb(b);
    assert(to_string(aa) == a && to_string(bb) == b);
    if (op == '+')
      aa += bb;
    else if (op == '-')
      aa -= bb;
    else
      aa *= bb;
    testProperties(aa);
    cout << aa << endl;
    cout.flush();
  }
}
