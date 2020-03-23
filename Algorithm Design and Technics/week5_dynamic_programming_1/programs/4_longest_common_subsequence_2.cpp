/* Dynamic Programming C++ implementation of LCS problem */
#include<bits/stdc++.h>  
using namespace std; 
// obs that is the oposite to edit distance, we sum when we found that is equal and we replace min with max
int max(int a, int b);  
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( vector<int> &a, vector<int> &b )  
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
  
/* Utility function to get max of 2 integers */
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
// Driver Code 
int main()  
{  
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs(a, b) << std::endl; 
}  