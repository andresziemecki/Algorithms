#include <iostream>
#include <vector>

using std::vector;

int max(int i,int j,int k){
  if (i>j && i>k)
    return i;
  else if (j > i && j>k)
    return j;
  else
    return k;
}

/*
int OutputAlignment(int **D, int i, int j, vector<int> &a, vector<int> &b){
    if (i==0 && j==0){
        return 0;
    }
    if (i > 0 && D[i][j] == (D[i-1][j] + 1)){
        std::cout << a[i-1] << "/" << "-" << "\t";
        return OutputAlignment(D, i -1, j,a,b);
    }
    else if ( j > 0 && D[i][j] == (D[i][j-1] + 1)){
        std::cout << "-" << "/" << b[j-1] << "\t";
        return OutputAlignment(D, i, j-1, a, b);
    }
    else {
        std::cout << a[i-1] << "/" << b[j-1] << "\t";
        if (a[i-1]==b[j-1]){
            return 1 + OutputAlignment(D, i-1, j-1,a ,b );
        }
        else {
            return OutputAlignment(D, i-1, j-1,a ,b );
        }
        
    }
}
*/
int lcs(vector<int> &a, vector<int> &b) {
  // Initialize 
  int **D = new(std::nothrow) int*[a.size()+1];
  for (int i =0; i <= a.size(); i++){
    D[i] = new int[b.size() + 1];
  }
  for (int i = 0; i <= a.size(); i++){
    for (int j = 0; j<= b.size(); j++){
        D[i][j] = 0;
    }
  }

int insertion, deletion, match, mismatch;
  // Edit distance algorithm
  for (int i = 1; i <= a.size(); i++){
    //std::cout << std::endl;
    for (int j = 1; j<= b.size(); j++){
      insertion = D[i][j-1];
      deletion = D[i-1][j];
      match = D[i-1][j-1] + 1;
      mismatch = D[i-1][j-1];
      if (a[i-1] == b[j-1])
        D[i][j]=match;
      else
        D[i][j]=max(insertion,deletion,mismatch);
      //std::cout << D[i][j] <<  " ";
    }
    //std::cout << std::endl;
  }
  // Return result
  //int result = OutputAlignment(D, a.size(),b.size(),a ,b);
  return D[a.size()][b.size()];
}



int main() {
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


/*
Failed case #1/37: (Wrong answer)                                                                                  
                                                                                                                       
    Input:                                                                                                             
    3                                                                                                                  
    1 2 3                                                                                                              
    3                                                                                                                  
    3 2 1                                                                                                              
                                                                                                                       
    Your output:                                                                                                       
    2                                                                                                                  
                                                                                                                       
    Correct output:                                                                                                    
    1
*/