#include "../template.hh"
// for c++14 and above;  explicitly specify the return type of the lambda
// links:
//  1. https://stackoverflow.com/a/40873657
//  2. http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<typename F>
struct y_combinator_result {
  F f;
  template<typename T>
  explicit y_combinator_result(T&& fun) : f(forward<T>(fun)) {}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return f(ref(*this), forward<Args>(args)...);
  }
};
template<typename F>
decltype(auto) y_combinator(F&& f) {
  return y_combinator_result<decay_t<F>>(forward<F>(f));
}
