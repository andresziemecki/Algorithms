#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 //#include <stack>

using std::vector;
//using std::stack;

typedef struct Number_and_Operation{
  int Amount;
  // stack<int> st;
  std::string st;

} S;

S dynamic_optimal_sequence(int n) {
  S init;
  init.Amount = INT32_MAX;
  std::vector<S> sequence(n + 1, init);

  int Number;
  sequence[0].Amount = 0;
  // sequence[0].st.push(0);
  bool third, second;

  for (int i = 1; i < sequence.size(); i++){
    
    third = false;
    second = false;

    Number = sequence[i-1].Amount + 1;  
    sequence[i].Amount = Number;

    if (i%2==0){
      Number = sequence[i/2].Amount + 1;
      if (Number < sequence[i].Amount){
        second = true;
        sequence[i].Amount = Number;
      }
    }
    if (i%3==0){
      Number = sequence[i/3].Amount + 1;
      if (Number < sequence[i].Amount){
        third = true;
        sequence[i].Amount = Number;
      }
    }
    if (third){
      // sequence[i].st = sequence[i/3].st;
      //sequence[i].st.push(sequence[i].st.top()*3);
      sequence[i].st.append(sequence[i/3].st);
      sequence[i].st.append("3");
    }
    else if (second){
      // sequence[i].st = sequence[i/2].st;
      // sequence[i].st.push(sequence[i].st.top()*2);
      sequence[i].st.append(sequence[i/2].st);
      sequence[i].st.append("2");
    }
    else {
      // sequence[i].st = sequence[i - 1].st;
      // sequence[i].st.push(sequence[i].st.top() + 1);
      sequence[i].st.append(sequence[i - 1].st);
      sequence[i].st.append("1");
    }
  } 
  return sequence[sequence.size()-1];
}

// with the number 10 doesn't work
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {

  int n;
  std::cin >> n;

  S sequence = dynamic_optimal_sequence(n);
  std::cout << sequence.Amount - 1 << std::endl;
  int result[sequence.Amount];
  // for (size_t i = 0; i < sequence.Amount; ++i) {
  //  result[i] = sequence.st.top();
  //  sequence.st.pop();
  // }
  result[0]=1;
  for (int i = 1; i < sequence.Amount; i++){
    if (sequence.st[i] == '1'){
      result[i] = result[i-1] + 1;
    }
    else if (sequence.st[i] == '2'){
      result[i] = result[i-1]*2;
    } 
    else{
      result[i] = result[i-1]*3;
    }
  }
  for (int i = sequence.Amount - 1; i >=0 ; --i) {
    std::cout << result[i] << " ";
  }
  
}
