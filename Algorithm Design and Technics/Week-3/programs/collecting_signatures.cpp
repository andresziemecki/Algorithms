#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  unsigned long long int start, end;
};
bool compareInterval(Segment i1, Segment i2) { 
    return (i1.start < i2.start); 
}

/*
bool nextElementIsBiggerThanTheRest (vector<Segment> &list, Segment nextElement) {
    for (size_t i = 0; i < list.size(); ++i){
        if (list[i].end < nextElement.start)
            return true;
    }
    return false;
}
*/

vector<unsigned long long int> optimal_points(vector<Segment> &segments) {
    vector<unsigned long long int> points;
    std::sort(segments.begin(), segments.end(), compareInterval); 
    Segment sc = segments[0];
    size_t i;
    // iterate over every elements
    for (i = 1; i < segments.size(); ++i) {
        if (sc.end < segments[i].start) {
            points.push_back(sc.end);
            sc = segments[i];
        }
        else {
            if (sc.end > segments[i].end)
                sc = segments[i];
        }
    }
    points.push_back(sc.end);
    return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<unsigned long long int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}