#include <iostream>
#include <vector>

using std::vector;

int Knaspack(int W, vector<int> &w) {
  vector<vector<int>> K(w.size() + 1, vector<int> (W +1, 0));
  size_t i,j;
  
  int current_weight = 0;
  int val;
  
  for (i = 1; i <= w.size(); ++i) {
    for (j = 1; j<=W; j++){
      K[i][j] =  K[i-1][j];
      if (w[i-1] <= j){
      val = K[ i-1][j - w[i-1]] + w[i-1];
      if (K[i][j]< val)
        K[i][j] = val;
      }
    }
  }
  int res = K[i-1][j-1]; 
  if (res != W){
    return 0;
  }
 
  unsigned int n = i - 1;

  // now we have to take out the items used to fill this knaspack

  for (i = n; i > 0 && W > 0; i--) { 
          
        // either the result comes from the top 
        // (K[i-1][w]) or from (val[i-1] + K[i-1] 
        // [w-wt[i-1]]) as in Knapsack table. If 
        // it comes from the latter one/ it means  
        // the item is included. 
        if (W == K[i - 1][W])  
            continue;         
        else { 
  
            // This item is included. 
            // printf("%d ", w[i - 1]); 
              
            // Since this weight is included its  
            // value is deducted  
            W = W - w[i - 1]; 
            w[i-1] = -1;
        } 
    }
    std::vector<int> result;
    for (i = 0; i<w.size(); i++){
      if (w[i]!= -1)
        result.push_back(w[i]);
    }
    w = result;
    return res;
}

int partition3(vector<int> &A) {
  // First check if the total could be divided by 3
  unsigned int sum = 0;
  for (int i = 0; i < A.size(); i++){
    sum += A[i];
  }
  if (sum%3 != 0)
    return 0;
  unsigned int totalForEachPlayer = sum/3;
  unsigned int player_1 = Knaspack(totalForEachPlayer, A);
  unsigned int player_2 = Knaspack(totalForEachPlayer, A);
  unsigned int player_3 = Knaspack(totalForEachPlayer, A);

  return (player_1 == player_2 && player_2 == player_3 && (player_1+player_2+player_3) == sum );
   
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n), B(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  for (size_t i = 1; i <= A.size(); ++i) {
    B[i-1] = A[A.size() - i];
  }
  std::cout << partition3(B) << '\n';
}
