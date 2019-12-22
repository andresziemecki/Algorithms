#include <iostream>
#include <vector>

using namespace std;


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        /*
        if (i == from) {
            std::cout << "The current from naive is: ";
            std::cout << current%10 << endl;
        }
        */
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


unsigned long long int* fibonacci(int n){
    unsigned long long int *F = new unsigned long long int[n+1];
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i <= n ; i++) {
        F[i] = (F[i-1] + F[i-2])%10;
    } 
    return F;
}

unsigned long long int sum(unsigned long long int* F, unsigned long long int to){

    // cout << "The value of F[0] is : " << F[0] << endl;
    for (int i = 1; i < 140; i++){
        F[i] = (F[i] + F[i-1])%10;
    }
    
    unsigned long long int t = 1;
    for (int i = 1; i < 140; i++){
        if (F[i] != F[i-t]){
            ++t;
        }
    }
    /*
    std::cout << "El valor de t es: "<< t << endl;

    for (int i = 0; i < t; i++){
        std::cout << F[i];
    }
    std::cout << endl;
    for (int i = t; i < 2*t; i++){
        std::cout << F[i];
    }
    std::cout << endl;
    */
    unsigned long long int suma = F[to%t];
    return suma;
}

unsigned long long int last_digit(unsigned long long int from, unsigned long long int to ) {

    unsigned long long int* F = fibonacci(200);

    int t = 1;
    
    for (int i = 1; i < 200; i++){
        if (F[i] != F[i-t]){
            ++t;
        }
    }

    // std::cout << "The current from no-naive is: " << F[from%t] << endl;

    unsigned long long int partial = sum(&F[from%t], to-from);
    return partial;

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
    
    return o[n%t];
    */
}

int main() {
    unsigned long long int from, to, partial;
    std::cin >> from >> to;
    partial = last_digit(from, to);
    std::cout << partial << endl;
    // partial = get_fibonacci_partial_sum_naive(from,to);
    // std::cout << partial << endl;
    return 0;
    // std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
