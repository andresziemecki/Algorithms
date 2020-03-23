#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  vector<vector<int>> value(w.size() + 1, vector<int> (W +1, 0));
  size_t i,j;
  
  int current_weight = 0;
  int val;
  
  for (i = 1; i <= w.size(); ++i) {
    for (j = 1; j<=W; j++){
      value[i][j] =  value[i-1][j];
      if (w[i-1] <= j){
      val = value[ i-1][j - w[i-1]] + w[i-1];
      if (value[i][j]< val)
        value[i][j] = val;
      }
    }
  }/*
  for (i = 0; i <= w.size(); ++i) {
    for (j = 0; j<=W; j++){
      std::cout<< value[i][j] << " ";
    }
    std::cout << std::endl;
  }*/
  return value[i-1][j-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
