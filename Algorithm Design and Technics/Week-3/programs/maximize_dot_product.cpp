#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long int max_dot_product(long long int *a, long long int *b, size_t n) {
  std::sort(a,a+n, std::greater<long long int>());
  std::sort(b,b+n, std::greater<long long int>());
  long long int result = 0;
  for (size_t i = 0; i < n; i++) {
    result += a[i] * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  long long int a[n], b[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b, n) << std::endl;
}
