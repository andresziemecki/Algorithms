#include <iostream>
#include <list>

using namespace std;

int hindex (list<int> &mylist, int element) {
    bool inserted = false;
    // insert the element in decending order
    for (auto it = mylist.begin(); it != mylist.end(); ++it){
        if (*it < element) {
            mylist.insert(it, element);
            inserted = true;
            break;
        }
    }
    // check if it was inserted
    if (!inserted) {
        mylist.push_back(element);
    }
    // return the hindex
    int i = 0;
    for (auto it = mylist.begin(); it != mylist.end(); ++it) {
        i++;
        if (*it < i){
            return (i-1);
        }
    }
    return i;

}

int main() {
  
  int n,T, input;
  cin >> T;
  list<int> mylist, result;

  for (int t = 1; t<=T; t++) {
        cin >> n;
        mylist.clear();
        result.clear();
        for (size_t i = 0; i < n; ++i) {
            cin >> input;
            result.push_back(hindex(mylist, input));
        }
        cout << "Case #" << t << ": ";
        for (auto it = result.begin(); it != result.end(); ++it) {
            cout << *it << " ";
        } 
        cout << endl;
    }

  return 0;
}


