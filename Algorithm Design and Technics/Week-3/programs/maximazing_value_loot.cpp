#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0, max = 0;
  int i_max = 0; 
  int size = weights.size();
  while (capacity != 0){
      for (int i = 0; i < size ; i++ ) {
          if (1.0*values[i]/weights[i] > max){
              i_max = i;
              max = 1.0*values[i]/weights[i];
          }
      }
      if (weights[i_max] < capacity) {
          value += values[i_max];
          values[i_max] = 0;
          capacity -= weights[i_max];
      }
      else {
          value += 1.0*capacity*values[i_max]/weights[i_max];
          capacity = 0;
      }
      max = 0;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
