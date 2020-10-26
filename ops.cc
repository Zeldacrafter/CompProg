#include "template_long.cc"

///////////////////////////////////////////////////////////////
// Utility functions.
///////////////////////////////////////////////////////////////

namespace impl {
  template <typename T, typename U, typename F, size_t... Is>
  T zipWith(const T& t, const U& u, F f, index_sequence<Is...>) { 
    return mt((static_cast<tuple_element_t<Is, T>>(f(get<Is>(t), get<Is>(u), Is)))...);
  }

  template <typename T, typename U, typename F, size_t... Is>
  F for_each_2t(T& t, const U& u, F f, index_sequence<Is...>) {
    auto l = { (f(get<Is>(t), get<Is>(u)), 0)... };
    (void) l;
    return f;
  }
}

template <typename... Ts, typename... Us, typename F>
tuple<Ts...> zipWith(const tuple<Ts...>& t, const tuple<Us...>& u, F f) { 
  static_assert(sizeof...(Ts) == sizeof...(Us), "Tuples must be the same size");
  return impl::zipWith(t, u, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename... Ts, typename... Us, typename F>
F for_each_2t(tuple<Ts...>& t, const tuple<Us...>& u, F f) { 
  static_assert(sizeof...(Ts) == sizeof...(Us), "Tuples must be the same size");
  return impl::for_each_2t(t, u, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename T> true_type tuple_size_check(typename tuple_size<T>::type*);
template <typename T> false_type tuple_size_check(...);
template <typename T> struct IsT : decltype(tuple_size_check<T>(nullptr)) {};
template <typename T> true_type stream_check(typename T::off_type*);
template <typename T> false_type stream_check(...);
template <typename T> struct IsSt : decltype(stream_check<T>(nullptr)) {};
template <typename T> struct IsS : integral_constant<bool, IsT<T>::value or IsC<T>::value or IsSt<T>::value> {};

#define vAssignmentOpF(name) \
  template <typename T, typename U> \
  vector<T>& name(vector<T>&, const U&); \
  template <typename T, typename U> \
  vector<T>& name(vector<T>&, const vector<U>&);

#define vAssignmentOp(name, op)     \
  template <typename T, typename U> \
  vector<T>& name(vector<T>& v, const U& x) { \
    for (auto& i : v) i op x; \
    return v; \
  } \
  template <typename T, typename U> \
  vector<T>& name(vector<T>& v, const vector<U>& w) { \
    F0R (i, min(SZ(v), SZ(w))) v[i] op w[i]; \
    return v; \
  }

#define vIncDecF(name) \
  template<typename T> \
  vector<T>& name(vector<T>&); \
  template<typename T> \
  vector<T> name(vector<T>&, int);

#define vIncDec(name, op)     \
  template<typename T> \
  vector<T>& name(vector<T>& v) { \
    for (auto& x : v) op x; \
    return v; \
  } \
  template<typename T> \
  vector<T> name(vector<T>& v, int) { \
    vector<T> t{v}; \
    op v; \
    return t; \
  }

#define vBinOpF(name) \
  template <typename T, typename U> \
  vector<T> name(vector<T>, const vector<U>&); \
  template <typename T, typename U> \
  vector<T> name(vector<T>, const U&); \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U&, vector<T>);

#define vBinOp(name, op) \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const vector<U>& u) { return v op u; } \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const U& u) { return v op u; } \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U& u, vector<T> v) { return v op u; }

#define vBinOpNo(name, op, ex) \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const vector<U>& u) { return v op u; } \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const U& u) { return v op u; } \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U& u, vector<T> v) { for (auto& i : v) i = u ex i; return v; }

#define pAssignmentOpF(name) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2>& name(pair<T1, T2>&, const pair<U1, U2>&); \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2>& name(pair<T1, T2>&, const U&); 

#define pAssignmentOp(name, op) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2>& name(pair<T1, T2>& p1, const pair<U1, U2>& p2) { \
    p1.fi op p2.fi; p1.se op p2.se; return p1; \
  } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2>& name(pair<T1, T2>& p, const U& u) { \
    p.fi op u; p.se op u; return p; \
  }

#define pIncDecF(name) \
  template<typename T1, typename T2> \
  pair<T1, T2>& name(pair<T1, T2>&); \
  template<typename T1, typename T2> \
  pair<T1, T2> name(pair<T1, T2>&, int);

#define pIncDec(name, op) \
  template<typename T1, typename T2> \
  pair<T1, T2>& name(pair<T1, T2>& p) { \
    op p.fi; op p.se; \
    return p; \
  } \
  template<typename T1, typename T2> \
  pair<T1, T2> name(pair<T1, T2>& p, int) { \
    pair<T1, T2> t{p}; \
    op p; \
    return t; \
  }

#define pBinOpF(name) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2>, const pair<U1, U2>&); \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2>, const U&); \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U&, pair<T1, T2>);

#define pBinOp(name, op) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2> p, const U& u) { return p op u; } \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U& u, pair<T1, T2> p) { return p op u; }

#define pBinOpNo(name, op, ex) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2> p, const U& u) { return p op u; } \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U& u, pair<T1, T2> p) { p.fi = u ex p.fi; p.se = u ex p.se; }

#define tAssignmentOpF(name) \
  template <typename... Ts, typename U> \
  tuple<Ts...>& name(tuple<Ts...>&, const U&); \
  template <typename... Ts, typename... Us> \
  tuple<Ts...>& name(tuple<Ts...>&, const tuple<Us...>&);

#define tAssignmentOp(name, op)     \
  template <typename... Ts, typename U> \
  tuple<Ts...>& name(tuple<Ts...>& t, const U& u) { \
    for_each(t, [&](auto& x, int) { x op u; }); \
    return t; \
  } \
  template <typename... Ts, typename... Us> \
  tuple<Ts...>& name(tuple<Ts...>& t1, const tuple<Us...>& t2) { \
    for_each_2t(t1, t2, [](auto& x, const auto& y) { x op y; }); \
    return t1; \
  }

#define tIncDecF(name) \
  template<typename... Ts> \
  tuple<Ts...>& name(tuple<Ts...>&); \
  template<typename... Ts> \
  tuple<Ts...> name(tuple<Ts...>&, int);

#define tIncDec(name, op)     \
  template<typename... Ts> \
  tuple<Ts...>& name(tuple<Ts...>& t) { \
    for_each(t,  [](auto& x, int) { op x; }); \
    return t; \
  } \
  template<typename... Ts> \
  tuple<Ts...> name(tuple<Ts...>& t, int) { \
    tuple<Ts...> tp{t}; \
    op t; \
    return tp; \
  }

#define tBinOpF(name) \
  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...>, const tuple<Us...>&); \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...>, const U&); \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U&, tuple<Ts...>);

#define tBinOp(name, op) \
  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...> t, const tuple<Us...>& u) {return t op u; } \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U& u, tuple<Ts...> t) { return t op u; }

#define tBinOpNo(name, op, ex) \
  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...> t, const tuple<Us...>& u) {return t op u; } \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U& u, tuple<Ts...> t) { for_each(t, [&](auto& x, int) { x = u ex x; }); return t; }

// vector forward declarations
vAssignmentOpF(operator+=) vAssignmentOpF(operator-=)
vAssignmentOpF(operator*=) vAssignmentOpF(operator/=) vAssignmentOpF(operator%=)
vAssignmentOpF(operator^=) vAssignmentOpF(operator|=) vAssignmentOpF(operator&=)
vAssignmentOpF(operator<<=) vAssignmentOpF(operator>>=)
vBinOpF(operator+) vBinOpF(operator-)
vBinOpF(operator*) vBinOpF(operator/) vBinOpF(operator%)
vBinOpF(operator^) vBinOpF(operator|) vBinOpF(operator&)
vBinOpF(operator<<) vBinOpF(operator>>)
vIncDecF(operator++) vIncDecF(operator--)
template <typename T> vector<T> operator-(vector<T> v);
template <typename T> vector<T> operator+(vector<T> v);

// pair forward declarations
pAssignmentOpF(operator+=) pAssignmentOpF(operator-=)
pAssignmentOpF(operator*=) pAssignmentOpF(operator/=) pAssignmentOpF(operator%=)
pAssignmentOpF(operator^=) pAssignmentOpF(operator|=) pAssignmentOpF(operator&=)
pAssignmentOpF(operator<<=) pAssignmentOpF(operator>>=)
pBinOpF(operator+) pBinOpF(operator-)
pBinOpF(operator*) pBinOpF(operator/) pBinOpF(operator%)
pBinOpF(operator^) pBinOpF(operator|) pBinOpF(operator&)
pBinOpF(operator<<) pBinOpF(operator>>)
pIncDecF(operator++) pIncDecF(operator--)
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p);
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p);

// tuple forward declarations
tAssignmentOpF(operator+=) tAssignmentOpF(operator-=)
tAssignmentOpF(operator*=) tAssignmentOpF(operator/=) tAssignmentOpF(operator%=)
tAssignmentOpF(operator^=) tAssignmentOpF(operator|=) tAssignmentOpF(operator&=)
tAssignmentOpF(operator<<=) tAssignmentOpF(operator>>=)
tBinOpF(operator+) tBinOpF(operator-)
tBinOpF(operator*) tBinOpF(operator/) tBinOpF(operator%)
tBinOpF(operator^) tBinOpF(operator|) tBinOpF(operator&)
tBinOpF(operator<<) tBinOpF(operator>>)
tIncDecF(operator++) tIncDecF(operator--)
template <typename... Ts> tuple<Ts...> operator-(tuple<Ts...> v);
template <typename... Ts> tuple<Ts...> operator+(tuple<Ts...> v);

// vector implementation
vAssignmentOp(operator+=, +=) vAssignmentOp(operator-=, -=)
vAssignmentOp(operator*=, *=) vAssignmentOp(operator/=, /=) vAssignmentOp(operator%=, %=)
vAssignmentOp(operator^=, ^=) vAssignmentOp(operator|=, |=) vAssignmentOp(operator&=, &=)
vAssignmentOp(operator<<=, <<=) vAssignmentOp(operator>>=, >>=)
vBinOp(operator+, +=) vBinOpNo(operator-, -=, -)
vBinOp(operator*, *=) vBinOpNo(operator/, /=, /) vBinOpNo(operator%, %=, %)
vBinOp(operator^, ^=) vBinOp(operator|, |=) vBinOp(operator&, &=)
vBinOpNo(operator<<, <<=, <<) vBinOpNo(operator>>, >>=, <<)
vIncDec(operator++, ++) vIncDec(operator--, --)
template <typename T> vector<T> operator-(vector<T> v) {
  for (auto& i : v) i = -i;
  return v;
}
template <typename T> vector<T> operator+(vector<T> v) {
  for (auto& i : v) i = +i;
  return v;
}

// pair implementation
pAssignmentOp(operator+=, +=) pAssignmentOp(operator-=, -=)
pAssignmentOp(operator*=, *=) pAssignmentOp(operator/=, /=) pAssignmentOp(operator%=, %=)
pAssignmentOp(operator^=, ^=) pAssignmentOp(operator|=, |=) pAssignmentOp(operator&=, &=)
pAssignmentOp(operator<<=, <<=) pAssignmentOp(operator>>=, >>=)
pBinOp(operator+, +=) pBinOpNo(operator-, -=, -)
pBinOp(operator*, *=) pBinOpNo(operator/, /=, /) pBinOpNo(operator%, %=, %)
pBinOp(operator^, ^=) pBinOp(operator|, |=) pBinOp(operator&, &=)
pBinOpNo(operator<<, <<=, <<) pBinOpNo(operator>>, >>=, <<)
pIncDec(operator++, ++) pIncDec(operator--, --)
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p) { return mp(-p.fi, -p.se); }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p) { return mp(+p.fi, +p.se); }

// tuple implementation
tAssignmentOp(operator+=, +=) tAssignmentOp(operator-=, -=)
tAssignmentOp(operator*=, *=) tAssignmentOp(operator/=, /=) tAssignmentOp(operator%=, %=)
tAssignmentOp(operator^=, ^=) tAssignmentOp(operator|=, |=) tAssignmentOp(operator&=, &=)
tAssignmentOp(operator<<=, <<=) tAssignmentOp(operator>>=, >>=)
tBinOp(operator+, +=) tBinOpNo(operator-, -=, -)
tBinOp(operator*, *=) tBinOpNo(operator/, /=, /) tBinOpNo(operator%, %=, %)
tBinOp(operator^, ^=) tBinOp(operator|, |=) tBinOp(operator&, &=)
tBinOpNo(operator<<, <<=, <<) tBinOpNo(operator>>, >>=, <<)
tIncDec(operator++, ++) tIncDec(operator--, --)
template <typename... Ts> tuple<Ts...> operator-(tuple<Ts...> t) {
  for_each(t, [](auto& x, int) { x = -x; });
  return t;
}
template <typename... Ts> tuple<Ts...> operator+(tuple<Ts...> t) {
  for_each(t, [](auto& x, int) { x = +x; });
  return t;
}
