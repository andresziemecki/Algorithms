#include <iostream>

using namespace std;

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
  cout << gdc(a,b) << endl;
  return 0;
}

apacheNLP
standford NLP
name enetity recognition
?NER
comprehend or sagemaker
AWS
aws NER comprehend
docNET
