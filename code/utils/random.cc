#include "../template.hh"
mt19937 gen((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
// values from [a, b] use like Idst(gen);
uniform_int_distribution<int> Idst(0, 10); 
// values from [a, b) use like Idst(gen);
uniform_real_distribution<double> Rdist(.0, 10.0);
