#include <iostream>
#include <map>
using namespace std;

unsigned long long int mcd (unsigned long long int a, unsigned long long int b){
  unsigned long long int tmp1 = a, tmp2 = b;
  int i1 = 1, i2 = 1;
  while(tmp1!=tmp2){
    if (tmp1>tmp2){
        ++i2;
        tmp2 = b*i2;
    }
    else{
      ++i1;
      tmp1 = a*i1;
    }
  }
  return tmp1;
}

unsigned long long int lcm (unsigned long long int a, unsigned long long int b){
  map<int, int> m1, m2;
  map<int,int>::iterator it;

  if (a==1)
    return b;
  if (b==1)
    return a;

  unsigned long long int lcm = 1;
  unsigned long long int i = 2;

  while (a != 1){
    if (a%i == 0){
      a = a/i;
      it = m1.find(i);
      if (it != m1.end()) // Si esta lo metemos
        m1[i] = m1[i] + 1;
      else
        m1[i] = 1;
    }
    else
      ++i;
  }

  for (it = m1.begin(); it != m1.end(); ++it)
    printf("%d\t%d\n", it->first, it->second);

  i = 2;

  while (b != 1){
    if (b%i == 0){
      b = b/i;
      it = m2.find(i);
      if (it != m2.end())
        m2[i] = m2[i] + 1;
      else
        m2[i] = 1;
    }
    else
      ++i;
  }

  for (it = m2.begin(); it != m2.end(); ++it)
    printf("%d\t%d\n", it->first, it->second);

  // Im goind to add to m2 everything from m1
  for (it = m1.begin(); it != m1.end(); ++it){
    if (m2.find(it->first) == m2.end())
      m2[it->first] = it->second;
    else {
      if (it->second > m2[it->first])
        m2[it->first] = it->second;
    }
  }

  for (it = m2.begin(); it != m2.end(); ++it){
    for (int j = 0; j < it->second; ++j)
      lcm = lcm*it->first;
  }

  return lcm;
}

// Best implementation because we want the smallest number between max(a,b) and a*b, and this is a*b/gratest common divisor
unsigned long long int gdc(unsigned long long int a, unsigned long long int b){
  if (b == 0)
    return a;
  else{
    if (b>a){
      unsigned long long int tmp = a;
      a = b;
      b = tmp;
    }
    return gdc(b, a%b);
  }
}

int main(void){
  unsigned long long int a,b;
  cin >> a >> b;
  cout << a/gdc(a,b)*b<<endl;
  return 0;
}
