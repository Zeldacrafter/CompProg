#include "../template.hh"
vi prefixFunction(const string& s) {
  vi prefix(SZ(s));
  FOR (i, 1, SZ(s)) {
    int j = prefix[i - 1];
    while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
    if (s[i] == s[j]) ++j;
    prefix[i] = j;
  }
  return prefix;
}
