#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>

using std::vector;
using std::string;

long long eval(long long int a, long long int b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}


typedef struct Mym {
  long long int max;
  long long int min;
} Mym;


Mym MinAndMax(Mym **M, char *op, int i, int j){
  long long int min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::lowest();
  long long int abcd[4];
  
  for (int k = i; k <= j-1 ; k++){
    abcd[0] = eval(M[i][k].max, M[k+1][j].max, op[k]);
    abcd[1] = eval(M[i][k].max, M[k+1][j].min, op[k]);
    abcd[2] = eval(M[i][k].min, M[k+1][j].max, op[k]);
    abcd[3] = eval(M[i][k].min, M[k+1][j].min, op[k]); 
    int lmax = 0, lmin = 0;
    for (int l = 1; l < 4; l++){
      if (abcd[l] > abcd[lmax])
        lmax = l;
      if (abcd[l] < abcd[lmin])
        lmin = l;
    }
    if (abcd[lmax] > max)
      max = abcd[lmax];
    if (abcd[lmin] < min)
      min = abcd[lmin];
  }
  Mym result{max, min};
  return result;
}

void PrintM(Mym **M, int n){

  std::cout << "MAX: " << std::endl;
  for (int i = 0; i< n; i++){
    for (int j = 0 ; j< n; j ++){
      std::cout << M[i][j].max << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "MIN: " << std::endl;
  for (int i = 0; i< n; i++){
    for (int j = 0 ; j< n; j ++){
      std::cout << M[i][j].min << " ";
    }
    std::cout << std::endl;
  }
  return;
}

long long int get_maximum_value(const string &exp) {
  // find the number of numbers in the string
  int n = (exp.length() - 1)/2 + 1;

  // Initialize the M and m matrix
  Mym **M;
  M = new Mym *[n];
  for(int i = 0; i <n; i++)
    M[i] = new Mym[n];
  char op[n-1];

  // Fill both matrix and the operations
  for (int i = 0, j = 0; i < exp.length(); i++){
    if (i%2==0) {
      M[j][j].max = int(exp[i]) - '0';
      M[j][j].min = int(exp[i]) - '0';
    } else {
      op[j] = exp[i];
      j++;
    }
  }

  

  // Find the Maximum
  int j;
  Mym result;
  for (int s = 0; s <= n-1; s++){
    for (int i = 0; i < (n-s); i++){
      j = i+s;
      if (i != j)
        M[i][j] = MinAndMax(M,op,i,j);
    }
  }
  // PrintM(M,n);
  return M[0][n-1].max;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
