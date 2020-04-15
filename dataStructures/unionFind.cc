#include "../template.cc"
class unionFind {
 public:
  unionFind(int size)
      : _size(size), data(size, -1) {}
  int find(int toFind) {
    int root = toFind;
    while (data[root] >= 0)
      root = data[root];
    while (toFind != root) {
      int tmp = data[toFind];
      data[toFind] = root;
      toFind = tmp;
    }
    return root;
  }
  void join(int a, int b) {
    if (data[a] < data[b]) {
      data[a] += data[b];
      data[b] = a;
    } else {
      data[b] += data[a];
      data[a] = b;
    }
    _size--;
  }
  int size() { return _size; }
  int size(int a) { return -data[a]; }

 private:
  vi data;
  int _size;
};
