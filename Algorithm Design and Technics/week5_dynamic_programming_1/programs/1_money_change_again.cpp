#include <iostream>
#include <vector>

int get_change(unsigned int money) {
  std::vector<unsigned int> coins{1,3,4};
  std::vector<unsigned int> MinNumCoins(money+1, INT32_MAX);

  unsigned int NumCoins;
  MinNumCoins[0] = 0;
  for(unsigned int m = 1; m < MinNumCoins.size(); m++){
      for (unsigned int coin_i = 0; coin_i < coins.size(); coin_i++){
          if ( (m+1) > coins[coin_i]){
              NumCoins = MinNumCoins[m-coins[coin_i]] + 1;
              if (NumCoins < MinNumCoins[m]){
                  MinNumCoins[m] = NumCoins;
              }
          }
      }
  }

  return MinNumCoins[MinNumCoins.size() - 1];
}

int main() {
  unsigned int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
