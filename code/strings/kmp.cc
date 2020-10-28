#include "../template.hh"
vi preprocess(string& s) {
  vi fail(SZ(s) + 1);
  fail[0] = -1;
  for (int i = 0, j = -1; i < SZ(s);) {
    while (j >= 0 && s[i] != s[j]) j = fail[j];
    ++i, ++j;
    fail[i] = j;
  }
  return fail;
}
vi match(string& text, string& pattern) {
  vi matches, fail(preprocess(pattern));
  for (int i = 0, j = 0; i < SZ(text);) {
    while (j >= 0 && text[i] != pattern[j]) j = fail[j];
    ++i; ++j;
    if (j == SZ(pattern)) {
      matches.pb(i - j);
      j = fail[j];
    }
  }
  return matches;
}
