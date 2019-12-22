#include <iostream>
#include <vector>
#include <algorithm>


typedef long long int lli;

using std::vector;

enum POS {L,R,P};

typedef struct INVERSION {
    lli num;
    POS pos;
    lli index;
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

vector<lli> fast_count_segments(vector<inv> v, lli pointSize) {
    // initialize the vector that we are going to return
  vector<lli> cnt(pointSize);
  // sort the vector
  std::sort(v.begin(), v.end(), cmp);
  // how many lefts and right are before each point
  unsigned long long int Lefts = 0,Rights = 0;

  // iterate aver all elements
  for (lli i = 0; i < v.size(); i++){
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

vector<int> naive_count_segments(vector<int> &starts, vector<int> &ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}



int main() {

  int c = 0;
  while (true){
    std::cout << "Case: " << c << std::endl;
    c++;
  lli n, m;
  // std::cin >> n >> m;
  n = std::rand()%50000;
  m = std::rand()%50000;

  vector<inv> v(2*n + m);

  vector<int> vecL(n);
  vector<int> vecR(n);

  vector<int> points(m);


  for (size_t i = 0, j = 0; i < 2*n; i++) {
    // std::cin >> v[i].num;
    v[i].num = rand()%200000000 - 100000000;

    vecL[j] = v[i].num;

    v[i].pos = L;
    ++i;
    // std::cin >> v[i].num;
    v[i].num = v[i-1].num + rand()%100000000;

    vecR[j] = v[i].num;
    j++;

    v[i].pos = R;

  }

  for (size_t i = 2*n, j = 0, k=0; i < v.size(); i++, j++, k++) {
    // std::cin >> v[i].num;
    v[i].num = rand()%200000000 - 100000000; 

    points[j] = v[i].num; 
    v[i].pos = P;
    v[i].index = k;
  }

  vector<lli> cnt = fast_count_segments(v, m);
  vector<int> cntN = naive_count_segments(vecL, vecR,  points);


  bool equal = true;

  for (size_t i = 0; i < cnt.size(); i++) {
    if (cnt[i] != cntNaive[i])
      equal = false;
  }

  if (!equal){
    std::cout << n << " " << m << std::endl;
    for (size_t i = 0; i < vecL.size(); i++) {
      std::cout << vecL[i] << ' ' << vecR[i] << std::endl;
    }
    for (size_t i = 0; i < points.size(); i++) {
      std::cout << points[i] << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < cnt.size(); i++) {
      std::cout << cnt[i] << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < cntN.size(); i++) {
      std::cout << cntN[i] << ' ';
    }
      break;
  }

}
return 0;
}
