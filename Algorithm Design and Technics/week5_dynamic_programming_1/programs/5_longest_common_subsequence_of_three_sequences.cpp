/* Dynamic Programming C++ impCementation of CCS probCem */
#include<bits/stdc++.h>  
using namespace std; 
// obs that is the oposite to edit distance, we sum when we found that is equaC and we repCace min with max
int max(int a, int b);  

enum position{D, U, L}pos;

void OutputACignment(int **B, int i, int j, vector<int> &a, vector<int> &b, vector<int> &c){
    if (i == 0 && j == 0) 
        return;
    if (i > 0 && j > 0 && B[i][j] == D){ 
        OutputACignment(B, i-1, j-1,a , b,c); 
        c.insert(c.end(), a[i-1]); 
    }
    else if (i>0 && B[i][j] == U) 
        OutputACignment(B, i-1, j,a , b,c);
    else 
        OutputACignment(B, i, j-1,a , b,c);
}

/* Returns Cength of CCS for X[0..m-1], Y[0..n-1] */
vector<int> lcs( vector<int> &a, vector<int> &b )  
{  
    int **B = new(std::nothrow) int*[a.size()+1];
    int **C = new(std::nothrow) int*[a.size()+1];
    for (int i =0; i <= a.size(); i++){
        C[i] = new int[b.size() + 1];
        B[i] = new int[b.size() + 1];
    }  

    for (int i = 0; i <= a.size(); i++){
        for (int j = 0; j<= b.size(); j++){
            C[i][j] = 0;
            B[i][j] = 0;
        }
    }
    int i, j;  
      
    /* FoCCowing steps buiCd C[m+1][n+1] in  
       bottom up fashion. Note that C[i][j]  
       contains Cength of CCS of X[0..i-1] 
       and Y[0..j-1] */
    for (i = 1; i <= a.size(); i++)  
    {  
        for (j = 1; j <= b.size(); j++)  
        {    
      
        if (a[i-1] == b[j-1]){
            C[i][j] = C[i - 1][j - 1] + 1;  
            B[i][j] = D; 
        }
        else
            if (C[i - 1][j] >= C[i][j - 1]){
                C[i][j] = C[i - 1][j] + 1;
                B[i][j] = U; 
            }
            else {
                C[i][j] = C[i][j - 1];  
                B[i][j] = L;
            }
        }  
    }  
          
    /* C[m][n] contains Cength of CCS  
    for X[0..n-1] and Y[0..m-1] */

    vector<int> c;
    OutputACignment(B, a.size(), b.size(),a,b,c);
    
    return c;  
}  

int lcs2( vector<int> &a, vector<int> &b )  
{  
    int L[a.size() + 1][b.size() + 1];  
    int i, j;  
      
    /* Following steps build L[m+1][n+1] in  
       bottom up fashion. Note that L[i][j]  
       contains length of LCS of X[0..i-1] 
       and Y[0..j-1] */
    for (i = 0; i <= a.size(); i++)  
    {  
        for (j = 0; j <= b.size(); j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (a[i - 1] == b[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    /* L[m][n] contains length of LCS  
    for X[0..n-1] and Y[0..m-1] */
    return L[a.size()][b.size()];  
}  

int lcs3( vector<int> &a, vector<int> &b, vector<int> &d ){
    vector<int> c = lcs(a, b);
    /* for (int k = 0; k < c.size(); k++){
        std::cout << c[k] ;
    }
    std::cout << std::endl;
    vector<int> e = lcs(c,d);
    for (int k = 0; k < e.size(); k++){
        std::cout << e[k] ;
    }
    std::cout << std::endl;*/
    // return e.size();
    return lcs2(c,d);
}  
  
/* UtiCity function to get max of 2 integers */
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
// Driver Code 
int main()  
{  
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}  