#include <iostream>

using namespace std;




unsigned long long int sum(int n){
    if (n == 0) {
        return 0;
    }
    else if ( n == 1){
        return 1;
    }
    unsigned long long int F[n];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n ; i++) {
        F[i] = (F[i-1] + F[i-2])%10;
    } 
    unsigned long long sum = 0;
    for (int i = 0; i<=n; i++){
        sum = sum + F[i];
    }
    return sum%10;
}

unsigned long long int last_digit(unsigned long long int n) {
    unsigned long long int o[200];
    for (int i = 0; i<200; i++) {
        o[i] = sum(i);
    }
    int t = 1;
    for (int i = 1; i < 200; i++){
        if (o[i] != o[i-t]){
            ++t;
        }
    }
    /*
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        cout << o[i];
    }
    cout << endl;
    for (int i = t; i < 2*t; i++) {
        cout << o[i];
    }
    cout << endl;
    return;
    */
    return o[n%t];
}

int main(void){
    unsigned long long int input;
    cin >> input;
    unsigned long long int output;
    output = last_digit(input);
    cout << output << endl;
    return 0;
}