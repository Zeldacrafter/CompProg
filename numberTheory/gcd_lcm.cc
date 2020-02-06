int gcd(int a, int b) {
  return !b ? a : gcd(a, a % b);
}
int lcm(int a, int b) {
  return a * (b / gcd(a, b));
}
