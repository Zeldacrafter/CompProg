#include "../template.cc"
class unionFind {
 public:
  unionFind(int size) : _size(size), data(size, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (data[a] > data[b]) swap(a, b);
    data[a] += data[b], data[b] = a;
    return true;
  }
  int size() { return _size; }
  int size(int a) { return -data[find(a)]; }

 private:
  vi data;
  int _size;
};
