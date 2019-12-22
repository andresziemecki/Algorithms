#include <iostream>
#include <vector>

using std::vector;

vector<unsigned long int> optimal_summands(int n) {
  vector<unsigned long int> summands;
  unsigned long int it = 1;
  while (n != 0){
      if (n >= 2*it + 1){
          summands.push_back(it);
          n -= it;
          it++;
      }
      else {
          summands.push_back(n); 
          n = 0;
      }
  }
  return summands;
}

int main() {
  unsigned long int n;
  std::cin >> n;
  vector<unsigned long int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
