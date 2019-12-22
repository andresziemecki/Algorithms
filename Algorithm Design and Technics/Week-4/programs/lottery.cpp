#include <iostream>
#include <vector>
// https://towardsdatascience.com/course-1-algorithmic-toolbox-part-3-divide-and-conquer-dd9022bfa2c0

using std::vector;
using std::swap;

typedef struct INVERSION {
    int num;
    int pos;
    int index;
}inv;

void randomized_quick_sort(vector<inv> &a, int l, int r);

bool cmp(const inv &a, const inv &b){
     if (a.num < b.num || (a.num == b.num && a.pos < b.pos) ){
         return true;
     }
    return false;
}

vector<int> fast_count_segments(vector<inv> &v, int pointSize) {
    // initialize the vector that we are going to return
  vector<int> cnt(pointSize);
  // sort the vector
  // std::sort(v.begin(), v.end(), cmp);
  randomized_quick_sort(v, 0, v.size()-1);

  // how many lefts and right are before each point
  int Lefts = 0;

  // iterate aver all elements
  for (int i = 0; i < v.size(); i++){
      if (v[i].pos == 1)
       ++Lefts;
    else if (v[i].pos == 3)
        --Lefts;
    else{ // count how many times this point is in all this segments
        cnt[v[i].index] = Lefts;
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



int partition(vector<inv> &a, int l, int r) {
  // assign to x the below element of the array
  inv x = a[l];

  // assign to j the left position
  int j = l;

  // start with the next element of the left position and compare
  for (int i = l + 1; i <= r; i++) {
    // if it is less or equal, just swap
    if (cmp(a[i], x)) {
      j++;
      swap(a[i], a[j]); 
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<inv> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  // pick a random element between left and right
  // int k = l + rand() % (r - l + 1);
  // swap this element with the firt one
  // swap(a[l], a[k]);
  
  // make the partition of quick sort which gives you the position of this partition
  int m = partition(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}



int main() {

  int n, m;
  std::cin >> n >> m;
  vector<inv> v(2*n + m);
  for (size_t i = 0; i < 2*n; i++) {
    std::cin >> v[i].num;
    v[i].pos = 1;
    ++i;
    std::cin >> v[i].num;
    v[i].pos = 3;
  }

  for (size_t i = 2*n, k = 0; i < v.size(); i++, k++) {
    std::cin >> v[i].num;
    v[i].pos = 2;
    v[i].index = k;
  }

  vector<int> cnt = fast_count_segments(v, m);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
