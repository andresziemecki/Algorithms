#include <iostream>
#include <climits>

using namespace std;

typedef struct {
  unsigned long long int X;
  unsigned long long int C;
  bool b = false;
} l_p;

int main(void){
  int T, K, N;
  cin >> T;
  for (int t = 1; t<=T; ++t){
    cin >> K >> N;

    l_p valores[N];

    for (int n = 0; n < N; ++n)
      cin >> valores[n].X;

    for (int k = 0; k<N; ++k)
      cin >> valores[k].C;

    int place = 0;
    unsigned long long int tmp, suma = ULLONG_MAX, suma_tmp = 0, menor = ULLONG_MAX;

    for (int w = 0; w < N; ++w){ // Aca va el warehouse
      for (int j = 0; j < K ; ++j){
        for (int k = 0; k < N; ++k){ // aca van los stalls
          if (k!=w && valores[k].b != true){
            tmp = abs(int(valores[w].X - valores[k].X)) + valores[k].C;
            if (tmp < menor){
              menor = tmp;
              place = k;
            }
          }
        }
        menor = ULLONG_MAX;
        valores[place].b = true;
      }
      for (int s = 0; s < N; ++s){
        if (valores[s].b == true){
          suma_tmp = suma_tmp + abs(int(valores[w].X - valores[s].X)) + valores[s].C;
          cout << abs(int(valores[w].X - valores[s].X)) + valores[s].C << endl;
          valores[s].b = false;
        }
        if (s==w)
          suma_tmp = suma_tmp + valores[s].C;
      }
      if (suma_tmp < suma)
        suma = suma_tmp;
      suma_tmp = 0;
    }
  cout << suma << endl;
  }
  return 0;
}
