#include <iostream>

int get_change(unsigned long int m) {
  int8_t coin1 = 1, coin5 = 5, coin10 = 10;
  unsigned int n;
  n = m/coin10;
  m= m%coin10;
  n += m/coin5;
  m = m%coin5;
  n += m;
  return n;
}

int main() {
  unsigned long int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
