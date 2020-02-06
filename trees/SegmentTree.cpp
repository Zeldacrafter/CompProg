#include <limits>
#include <vector>
using namespace std;
typedef vector<int> vi;
vi A;                // the array on which the range queries are performed;
class SegmentTree {  // segment tree for range maximum queries
   private:
    vi value;
    int inline left(int p) { return p << 1; }
    int inline right(int p) { return (p << 1) + 1; }

    int build(int p, int L, int R) {
        if (L == R) {
            return value[p] = A[L];
        } else {
            return value[p] = max(build(left(p), L, (R + L) / 2),
                                  build(right(p), (R + L) / 2 + 1, R));
        }
    }
    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return numeric_limits<int>::min();
        if (i <= L && R <= j) return value[p];
        return max(rmq(left(p), L, (L + R) / 2, i, j),
                   rmq(right(p), (L + R) / 2 + 1, R, i, j));
    }

   public:
    SegmentTree() : value(A.size() * 4) { build(1, 0, A.size() - 1); }
    int rmq(int i, int j) { return rmq(1, 0, A.size() - 1, i, j); }
};
