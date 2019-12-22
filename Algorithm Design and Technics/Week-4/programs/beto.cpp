#include <iostream>

using namespace std;

int main(void) {

    int vago = 0, mina = 0;

    for (int i = 0; i< INT_MAX; i++) {
        if (rand()%2){
            mina++;
        }
    }

    return 0;
}