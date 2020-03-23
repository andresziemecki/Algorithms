
/* Dynamic Programming C++ implementation of LCS problem */
#include<bits/stdc++.h>  
using namespace std; 
// obs that is the oposite to edit distance, we sum when we found that is equal and we replace min with max
int max(int i, int j, int k);  
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs3( vector<int> &a, vector<int> &b, vector<int> &c )  
{  
    int L[a.size() + 1][b.size() + 1][c.size() + 1];  
    int i, j, k;  

    for (i = 0; i <= a.size(); i++)  {
        for (j = 0; j <= b.size(); j++) {  
            for (k = 0; k<= c.size(); k++){
                L[i][j][k] = 0; 
            }
        }
          
    } 
      
    /* Following steps build L[m+1][n+1] in  
       bottom up fashion. Note that L[i][j]  
       contains length of LCS of X[0..i-1] 
       and Y[0..j-1] */
    for (i = 0; i <= a.size(); i++)  {
        for (j = 0; j <= b.size(); j++) {  
            for (k = 0; k<= c.size(); k++){
                if (i == 0 || j == 0 || k==0)  
                    L[i][j][k] = 0;  
                else if (a[i - 1] == b[j - 1] == c[k-1])  
                    L[i][j][k] = L[i - 1][j - 1][k-1] + 1;  
                else
                    L[i][j][k] = max(L[i - 1][j][k], L[i][j - 1][k], L[i][j][k-1]);  
        }
            }
          
    }  
          
    /* L[m][n] contains length of LCS  
    for X[0..n-1] and Y[0..m-1] */
    return L[a.size()][b.size()][c.size()];  
}  
  
  int max2(int a, int b)  
{  
    return (a > b)? a : b;  
} 
/* Utility function to get max of 2 integers */
int max(int i,int j,int k){
  int x = max2(i,j);
  return max2(x,k);
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
/*
def lcs3(a, b, c):
    n = len(a)
    m = len(b)
    l = len(c)

    if 0 in (n, m, l):
        return 0

    E = [[[0] * (l + 1) for _ in range(m + 1)] for _ in range(n + 1)]

    for i in reversed(range(n + 1)):
        for j in reversed(range(m + 1)):
            for k in reversed(range(l + 1)):
                if i == n or j == m or k ==l:
                    E[i][j][k] = 0
                elif a[i] == b[j] == c[k]:
                    E[i][j][k] = 1 + E[i + 1][j + 1][k + 1]
                else:
                    E[i][j][k] = max(E[i + 1][j][k], E[i][j + 1][k], E[i][j][k + 1])

    return E[0][0][0]
    */