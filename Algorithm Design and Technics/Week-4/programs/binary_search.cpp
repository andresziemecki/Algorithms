#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<unsigned long long int> &a, unsigned long long int x) {
  int left = 0, right = (int)a.size();
  int middle;
  while(left<right){
      middle = (left + right)/2;
      // std::cout << middle << std::endl;
      if (a[middle] == x)
          return middle;
      if (a[middle] < x)
          left = middle + 1;
      else 
          right = middle;
  } 
  return - 1;
}

int linear_search(const vector<unsigned long long int> &a, unsigned long long int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<unsigned long long int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<unsigned long long int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
