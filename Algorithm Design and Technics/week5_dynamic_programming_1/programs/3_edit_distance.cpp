#include <iostream>
#include <string>

using std::string;

int min(int i,int j,int k){
  if (i<j && i<k)
    return i;
  else if (j < i && j<k)
    return j;
  else
    return k;
}

int edit_distance(const string &str1, const string &str2) {
  // Initialize 
  int **D = new(std::nothrow) int*[str1.length()+1];
  for (int i =0; i <= str1.length(); i++){
    D[i] = new int[str2.length() + 1];
  }
  for (int i = 0; i <= str1.length(); i++){
    for (int j = 0; j<= str2.length(); j++){
      if (i == 0)
        D[i][j] = j;
      else if (j==0)
        D[i][j] = i;
      else
        D[i][j] = 0;
    }
  }

int insertion, deletion, match, mismatch;
  // Edit distance algorithm
  for (int i = 1; i <= str1.length(); i++){
    //std::cout << std::endl;
    for (int j = 1; j<= str2.length(); j++){
      insertion = D[i][j-1] + 1;
      deletion = D[i-1][j] + 1;
      match = D[i-1][j-1];
      mismatch = D[i-1][j-1] + 1;
      if (str1[i-1] == str2[j-1])
        D[i][j]=min(insertion,deletion,match);
      else
        D[i][j]=min(insertion,deletion,mismatch);
      //std::cout << D[i][j] <<  " ";
    }
  }
  // Return result
  int result = D[str1.length()][str2.length()];
  return result;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
