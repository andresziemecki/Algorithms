#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compareInterval(string s1, string s2) { 
  long long i1, i2;
  i1 = atoll( (s1 + s2).c_str());
  i2 = atoll( (s2 + s1).c_str());
  if (i1 > i2)
    return true;
  else
    return false;
}

string largest_number(vector<string> a) {
  std::sort(a.begin(), a.end(), compareInterval);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
