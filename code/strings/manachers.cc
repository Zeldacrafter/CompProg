#include "../template.hh"
vi manacher(string s) {
  string T = "#";   // Assume that '#' is not in the alphabet
  for (char c : s) T += c, T += '#';
  vi P(SZ(T));
  int c = 0, R = 0;
  FOR (i, 1, SZ(T) - 1) {
    if (R > i) P[i] = min(R - i, P[2 * c - i]);
    for (int r = i + 1 + P[i], l = i - 1 - P[i];
         r < SZ(T) && l >= 0 && T[l] == T[r]; l--, r++)
      P[i]++;
    if (i + P[i] > R) c = i, R = i + P[i];
  }
  return P;
}
