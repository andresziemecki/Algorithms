#include <iostream>

using namespace std;

unsigned int merge(unsigned long long int *v, int left, int mid, int right){
    int i=left,j=mid+1, k = 0;
    unsigned long long int temporary[right - left + 1]; 
    unsigned int inver = 0;
    while(i <= mid && j<=right) {
        if (v[i] > v[j]){
            temporary[k] = v[j];
            j++;
            inver++;
        }
        else {
            temporary[k] = v[i];
            i++;
            inver += j - (mid + 1);
        }
        k++;
    }
    inver += (mid-i)*(right-mid);
    while(i <= mid){
        temporary[k]=v[i];
        i++;
        k++; 
    }
    while (j <= right) {
        temporary[k] = v[j];
        j++;
        k++;
    }
    for (i = left, k=0; i <= right; i++, k++){
        v[i] = temporary[k];
    }
    return inver;
}

// mergesort
unsigned int mergeSort(unsigned long long int *v, int left, int right){
    if (left >= right)
        return 0;
    int mid = (left+right)/2;
    unsigned int sum = 0;
    sum += mergeSort(v, left, mid);
    sum += mergeSort(v, mid + 1, right);

    /* ESTE ES EL QUE FUNCIONA
    for (int i = left; i <= mid; i++){
        for (int j = mid+1; j<= right; j++){
            if (v[i] > v[j])
                sum++;
        }
    }
    return sum;
    */
    return sum + merge(v, left, mid, right);
}

unsigned int inversions(unsigned long long int *v, int size){
    return mergeSort(v, 0, size-1);
}

unsigned int inversionsTest(unsigned long long int *v, int size){
    int i = 0;
    unsigned int sum = 0;
    while(i < size){
        for (int j = i + 1; j < size; j++){
            if (v[i] > v[j]){
                sum++;
            }
        }
        i++;
    }
    return sum;
}

void test(int size){
    unsigned long long int v[size];
    unsigned long long int v2[size];
    while(true) {
        for (int i = 0; i < size; i++) {
            v[i] = rand()%10;
            v2[i] = v[i];
        }
        int inv = inversions(v, size), invT = inversionsTest(v2,size);
        if (inv != invT){
            for (int j=0; j < size ; j++){
                cout << v2[j] << " ";
            }
            cout << endl;
            cout << "inv: " << inv << "   invT: " << invT;
            cout << endl;
            break;
        }
    }
}

int main(void) {
    // input
    /*
    int n;
    cin >> n;
    unsigned long long int v[n];
    
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    cout << mergeSort(v, 0, n-1) << endl;
    */

    test(5);
    return 0;
}