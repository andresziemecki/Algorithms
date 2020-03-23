#include <iostream>
#include <bitset>

using namespace std;

class Matrix {
  unsigned long int *M[2];
public:
  
  Matrix()
  {
    unsigned long int *m1 = new unsigned long int[2];
    unsigned long int *m2 = new unsigned long int[2];

    M[0]=m1;
    M[1]=m2;

    M[0][0]=0;
    M[0][1]=0;
    M[1][0]=0;
    M[1][1]=0;
  }
  Matrix(int num_of_col)
  {
    unsigned long int *m1 = new unsigned long int[2];
    unsigned long int *m2 = new unsigned long int[2];

    M[0]=m1;
    M[1]=m2;

    if (num_of_col == 1)
    {
      M[0][0]=1;
      M[0][1]=1;
      M[1][0]=1;
      M[1][1]=0;
    }
    else
    { // M[0][1] = F1 y M[1][1] = F0
      M[0][0]=0;
      M[0][1]=1;
      M[1][0]=0;
      M[1][1]=0;
    }
  }
  ~Matrix(){
    delete[] M[0];
    delete[] M[1];
  }
  Matrix (const Matrix &old){
    this->M[0] = old.M[0];
    this->M[1] = old.M[1];
    return;
  }


  friend Matrix operator* (const Matrix& x, const Matrix& y);
  void print_Matrix (){
    cout << M[0][0] << "\t" << M[0][1] << endl;
    cout << M[1][0] << "\t" << M[1][1] << endl;
  }

  void operator= (const Matrix &old){
    unsigned long int *m1 = new unsigned long int[2];
    unsigned long int *m2 = new unsigned long int[2];

    M[0]=m1;
    M[1]=m2;
    this->M[0][0] = old.M[0][0];
    this->M[0][1] = old.M[0][1];
    this->M[1][0] = old.M[1][0];
    this->M[1][1] = old.M[1][1];
  }

  unsigned long int getF1(){
    return this->M[0][1];
  }

  unsigned long int getF0(){
    return this->M[1][1];
  }

  friend Matrix operator% (const Matrix& A, int m);
};

Matrix operator% (const Matrix& A, int m)
    {
      Matrix R;
      R.M[0][0] = A.M[0][0]%m;
      R.M[0][1] = A.M[0][1]%m;
      R.M[1][0] = A.M[1][0]%m;
      R.M[1][1] = A.M[1][1]%m;
      return R;
    }
  
Matrix operator* (const Matrix& x, const Matrix& y)
{
  Matrix R;
  R.M[0][0] = x.M[0][0]*y.M[0][0] + x.M[0][1]*y.M[1][0];
  R.M[0][1] = x.M[0][0]*y.M[0][1] + x.M[0][1]*y.M[1][1];
  R.M[1][0] = x.M[1][0]*y.M[0][0] + x.M[1][1]*y.M[1][0];
  R.M[1][1] = x.M[1][0]*y.M[0][1] + x.M[1][1]*y.M[1][1];
  return R;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


int main(void){
  
  // set the input of the number
  unsigned long int number, m;
  cin >> number >> m;

  // check if this number is 0 or 1
  if (number == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  else if (number == 1)
  {
    cout << 1 << endl;
    return 0;
  }
  // passs the number to binary format
  bitset <64> b(number);
  string s = b.to_string();

  // shrink the length
  int length_s = s.length();
  int position;
  for (int j = 0; j<length_s; ++j){
    if (s[j] == '1'){
      position = j;
      break;
    }
  }

  // Get the module of the Fn element
  Matrix A(1);
  Matrix Result(0);
  for (int i = length_s - 1 ; i >= position; --i) {
    if (s[i] == '1')
      Result = (A*Result)%m;
    A = (A*A)%m;
  } 
  // std::cout << get_fibonacci_huge_naive(number, m) << '\n';
  cout << Result.getF0() << endl;
  return 0;
}
