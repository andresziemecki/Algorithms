#include <iostream>
#include <climits>
using namespace std;

unsigned long long int fibonacci_huge (unsigned long long int n, unsigned long long int m){
  if (n==0)
    return 0;
  else if (n==1)
    return 1;
  unsigned long long int *F = new unsigned long long int[n + 1];
  F[0] = 0;
  F[1] = 1;
  for (unsigned long long int i = 2; i <= n; ++i){
    F[i] = (F[i-1] + F[i-2]) % m;
  }
  unsigned long long int result = F[n];
  delete []F;
  return result;
}

int main(void){
  unsigned long long int n, m;
  cin >> n >> m;
  cout << fibonacci_huge(n,m) << endl;
  return 0;
}
