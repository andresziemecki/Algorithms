#include <iostream>

using namespace std;

int get_fibonacci_last_digit(int n) {
    if (n == 0)
      return 0;
    else if (n == 1)
      return 1;
    else{
      int N_1 = 1, N_2 = 0, current;
      for (int i = 2; i<= n; ++i){
        current = (N_1 + N_2)%10;
        N_2 = N_1;
        N_1 = current;
      }
      return current;
    }
}

int main(void){
  int n;
  cin >> n;
  unsigned int c = get_fibonacci_last_digit(n);
  cout << c << '\n';
}
