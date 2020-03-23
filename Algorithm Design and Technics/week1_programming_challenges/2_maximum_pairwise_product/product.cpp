#include <iostream>
#include <vector>

using namespace std;

unsigned long long int Max_multi(const std::vector<unsigned long long int> numbers){
  int n = numbers.size();
  unsigned long long int a = 0,b = 0,tmp;
  for (int i = 0; i < n; ++i){
    tmp = numbers[i];
      if (tmp > a){
        b = a;
        a = tmp;
      }
      else if (tmp > b){
        b = tmp;
      }
    }
  return a*b;
}


int main(void){
  int n;
  std::cin >> n;
  std::vector<unsigned long long int> numbers(n);
  for (int i = 0; i < n; ++i){
    cin >> numbers[i];
  }

  unsigned long long int result = Max_multi(numbers);

  cout << result << endl;
  return 0;
}
