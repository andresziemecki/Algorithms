#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


int partition2(vector<unsigned long long int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort2(vector<unsigned long long int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort2(a, l, m - 1);
  randomized_quick_sort2(a, m + 1, r);
}

typedef struct partition {
  int below;
  int equal;
} par;

par partition(vector<unsigned long long int> &a, int l, int r) {
  // assign to x the below element of the array
  unsigned long long int x = a[l];

  // assign to j the left position
  int j = l;
  par index = {j,j};

  // start with the next element of the lest position and compare
  for (int i = l + 1; i <= r; i++) {
    // if it is less or equal, just swap
    if (a[i] < x) {
      swap(a[i], a[index.below]);
      index.equal++;
      swap(a[index.equal], a[i]);
      index.below++;
      
    }
    else if (a[i] == x) {
      index.equal++;
      swap(a[i], a[index.equal]);
    }
  }
  // swap(a[l], a[index.below]);
  return index;
}

void randomized_quick_sort(vector<unsigned long long int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  // pick a random element between left and right
  int k = l + rand() % (r - l + 1);
  // swap this element with the firt one
  swap(a[l], a[k]);
  
  // make the partition of quick sort which gives you the position of this partition
  par m = partition(a, l, r);

  randomized_quick_sort(a, l, m.below - 1);
  randomized_quick_sort(a, m.equal + 1, r);
}

bool difference(std::vector<unsigned long long int> &v,std::vector<unsigned long long int> &v1, int n) {
  randomized_quick_sort(v, 0, v.size() - 1);
  randomized_quick_sort2(v1, 0, v1.size() - 1);
  for(int i = 0; i < n; i++) {
    if (v[i] != v1[i])
      return true;
  }
  return false;
}

void test() {

  int n;
  std::vector<unsigned long long int> v, v1;
  while(true) {
    v.clear();
    n = rand()%100;
    for (int i = 0; i < n; i ++){
      v.push_back(rand()%10);
    }
    v1 = v;
   if (difference(v,v1, n))
    break;
  }
  std::cout << "There was a difference!" << std::endl;
  for (int i = 0; i < n; i ++)
    std::cout << v[i] << " ";
  std::cout << std::endl;
  for (int i = 0; i < n; i ++)
    std::cout << v1[i] << " ";
  std::cout << std::endl;

}

int main() {
  
  int n;
  std::cin >> n;
  vector<unsigned long long int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  
  // test();
  return 0;
}


