#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
//#include <string>
#include <cmath>

using std::vector;
//using std::string;
//using std::pair;
//using std::min;

typedef struct point {
  long long int x;
  long long int y;
} P;


typedef struct partition {
  int below;
  int equal;
} par;

bool comp_x(P p1, P p2){
  return p1.x<p2.x;
}

bool comp_y(P p1, P p2){
  return p1.y<p2.y;
}

bool equals_x(P p1, P p2){
  return p1.x==p2.x;
}

bool equals_y(P p1, P p2){
  return p1.y==p2.y;
}


par partition(vector<P> &p, int l, int r, bool(*comp)(P, P), bool(*equals)(P, P)) {
  // assign to x the below element of the array
  P tmp = p[l];

  // assign to j the left position
  int j = l;
  par index = {j,j};

  // start with the next element of the lest position and compare
  for (int i = l + 1; i <= r; i++) {
    // if it is less or equal, just swap
    if (comp(p[i], tmp)) {
      std::swap(p[i], p[index.below]);
      index.equal++;
      std::swap(p[index.equal], p[i]);
      index.below++;
      
    }
    else if ( equals(p[i],tmp) ) {
      index.equal++;
      std::swap(p[i], p[index.equal]);
    }
  }
  // swap(a[l], a[index.below]);
  return index;
}

void randomized_quick_sort(vector<P> &p, int l, int r, bool(*comp)(P, P), bool(*equals)(P, P)) {

  if (l >= r) {
    return;
  }
  // pick a random element between left and right
  int k = l + rand() % (r - l + 1);
  // swap this element with the firt one
  std::swap(p[l], p[k]);
  
  // make the partition of quick sort which gives you the position of this partition
  par m = partition(p, l, r, comp, equals);

  randomized_quick_sort(p, l, m.below - 1, comp, equals);
  randomized_quick_sort(p, m.equal + 1, r, comp, equals);
}

long long int distance_square(P p1, P p2){
  return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

long long int find_min_distance(vector<P> &p, int left, int right){
  // iterate over all elements and find min distance
  long long int min_distance = distance_square(p[left], p[left+1]);  
    for (int i = left; i < right; i++){
      for (int j = i + 1; j <= right; j++)
          min_distance = std::min(min_distance, distance_square(p[i], p[j]));
    }
  return min_distance;
}

long long int find_closest_two_points(vector<P> &p, int left, int right){
  
  // find shortest distance in the last 7 elements
  if ( (right - left) < 4){ 
    return find_min_distance(p, left, right);
  }
  // partition
  int middle = (right + left)/2;
  long long int min_distance = std::min(find_closest_two_points(p, left, middle-1),find_closest_two_points(p, middle, right));
    
  // find the most left and right element in the middle strip
   
  int most_left = middle - 1; 
  while ( most_left > left && (p[middle].x - p[most_left].x)*(p[middle].x - p[most_left].x) < min_distance)
    --most_left;
  int most_right = middle + 1;
  while (most_right < right && (p[most_right].x - p[middle].x)*(p[most_right].x - p[middle].x) < min_distance)
    ++most_right;

  //Find min distance between this two parts
  if ((most_right - most_left) < 8)
    min_distance = std::min(min_distance, find_min_distance(p, most_left, most_right));
  else {
      vector<P> tmp(most_right-most_left+1);
      for (int i = 0; i<= most_right - most_left; i++){
        tmp[i] = p[i+most_left];
      }
    //sort y elements
    randomized_quick_sort(tmp, 0, tmp.size()-1, comp_y, equals_y);
    for (int i = 0, j = 7; j <= tmp.size()-1; i++, j++){
        min_distance = std::min(min_distance, find_min_distance(tmp, i,j));
      }
  }
  return min_distance;
}

long long int minimal_distance(vector<P> &p) {
  //sort through x
  randomized_quick_sort(p, 0, p.size()-1, comp_x, equals_x);
  // find closest two points and return
  long long int closest =  find_closest_two_points(p, 0, p.size());
  return closest;
}

void test(int size){
    vector<P> v1(size);
    vector<P> v2(size);
    int k = 0;
    while(true) {
        for (int i = 0; i < size; i++) {
            v1[i].x = rand()%100-50;
            v1[i].y = rand()%100-50;
            v2[i].x = v1[i].x;
            v2[i].y = v1[i].y;
        }
        long long int inv =  minimal_distance(v1);
        long long int invT = find_min_distance(v2, 0 , v2.size() -1 );
        if (inv != invT){
            for (int j=0; j < size ; j++){
                std::cout << "(" << v1[j].x << "," << v1[j].y<<  ") ";
            }
            std::cout << std::endl;
            std::cout << "Your: " << inv << "   Expected: " << invT;
            std::cout << std::endl;
            break;
        }
        std::cout << "Case " << k << " passed" << std:: endl; 
        ++k;
    }
}

int main() {
  size_t n;
  std::cin >> n;
  vector<P> p(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> p[i].x >> p[i].y;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << std::sqrt(minimal_distance(p)) << "\n";
  // test(1000);
}
