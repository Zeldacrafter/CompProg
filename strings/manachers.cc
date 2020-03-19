#include "../template.cc"
vi manacher(string s) {
  string T = "#";   // Assume that '#' is not
  for (char c : s)  // in the alphabet
    T += c, T += '#';
  cout << T << endl;

  vi P(SZ(T));

  int c = 0, r = 0;
  FOR (i, 1, SZ(T) - 1) {
    if (r > i)
      P[i] = min(r - i, P[2 * c - i]);
    while (T[i + 1 + P[i]] ==
           T[i - 1 - P[i]])
      P[i]++;
    if (i + P[i] > r) c = i, r = i + P[i];
  }

  return P;
}
