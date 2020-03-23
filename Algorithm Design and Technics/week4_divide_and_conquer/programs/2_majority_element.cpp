#include <iostream>
#include <unordered_map>


using namespace std;

int majority_element(unsigned long long int *a, unsigned int size){
    unordered_map<unsigned long long int, unsigned long long int> m;
    for (unsigned long long int i = 0; i < size; i ++) {
        m[a[i]]++; 
    }
    for (auto x : m) {
        if (x.second > size/2)
            return 1; 
    }
    return 0;
}

int main(void) {
    unsigned int n;
    cin >> n;
    unsigned long long int a[n];
    for (unsigned int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    cout << majority_element(a, n);
    return 0;
}