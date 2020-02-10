#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int main() {
  int N;
  vi A(N);  // the actual array
  vii L;    // save the current state of the
          // subsequence w/ the index of
          // every element in the actual
          // array
  // save the index of the previous element
  // in the actual array
  vi prev(N, -1);
  int list = 0;
  F0R(i, A.size()) {
    // the position in the sub sequence where
    // the next element would fit in so that
    // the previous element is strictly
    // smaller or the beginning
    list =
        lower_bound(
            L.begin(), L.end(), A[i],
            [](const ii& a, int b) -> bool {
              return a.first < b;
            }) -
        L.begin();
    if (list ==
        L.size())  // add the element to the
                   // end if it's
      L.push_back(
          {A[i], i});  // greater than all
                       // other elements
    else
      L[list] = {A[i],
                 i};  // otherwise add it in
                      // the middle
    // set the index of the previous element
    // or -1 if start item
    prev.push_back(list ? L[list - 1].second
                        : -1);
  }
  printf(
      "Longest Increasing Subsequence w/ "
      "length: %d",
      (int)L.size());
  stack<int> p;  // use a stack to print the
                 // LIS in order
  for (int x = L.back().second; x != -1;
       x = prev[x])
    p.push(A[x]);
  for (; !p.empty(); p.pop())
    printf("%d\n", p.top());
}
