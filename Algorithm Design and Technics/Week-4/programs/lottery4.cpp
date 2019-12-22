#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

enum POS {L,R,P};

typedef struct INVERSION {
    int num;
    POS pos;
    int index;
}inv;

bool cmp(const inv &a, const inv &b){
     if (a.num < b.num){
         return true;
     } else if (a.num == b.num){
         if (a.pos == L) {
             return true;
         } else if (a.pos == R) {
             return false;
         } else if (b.pos == L) {
             false;
         } else if (b.pos == R) {
             return true;
         }
     } else {
         return false;
     }
}

vector<int> fast_count_segments(vector<inv> &v, int pointSize) {
    // initialize the vector that we are going to return
  vector<int> cnt(pointSize);
  // sort the vector
  std::sort(v.begin(), v.end(), cmp);
  // how many lefts and right are before each point
  int Lefts = 0,Rights = 0;

  // iterate aver all elements
  for (int i = 0; i < v.size(); i++){
      if (v[i].pos == L)
        Lefts++;
    else if (v[i].pos == R)
        Rights++;
    else{ // count how many times this point is in all this segments
        cnt[v[i].index] = Lefts-Rights;
    } 
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}



int main() {

  int n, m;
  std::cin >> n >> m;
  vector<inv> v(2*n + m);
  for (size_t i = 0; i < 2*n; i++) {
    std::cin >> v[i].num;
    v[i].pos = L;
    ++i;
    std::cin >> v[i].num;
    v[i].pos = R;
  }

  for (size_t i = 2*n, k = 0; i < v.size(); i++, k++) {
    std::cin >> v[i].num;
    v[i].pos = P;
    v[i].index = k;
  }

  vector<int> cnt = fast_count_segments(v, m);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
