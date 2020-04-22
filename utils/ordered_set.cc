#include "../template.cc"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
struct oset : public tree<T, null_type, less<T>, rb_tree_tag,
                          tree_order_statistics_node_update> {};
// same operations as set w/ extra options:
// - oset.find_by_order(int k) returns iterator to the k-th smallest
//   entry (0 indexed)
// - oset.oreder_of_key(int k) returns the number of keys strictly
//   smaller than k
