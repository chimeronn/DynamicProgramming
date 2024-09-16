#include <iostream>
#include <fstream>
using namespace std;

int coinChange(int total, int coins[]);

int main() {
  int total;
  int numCoins;
  int coins[numCoins];

  fstream file("coins.txt");
  file >> total;
  file >> numCoins;

  for(int i = 0; i < numCoins; i++){
    file >> coins[i];
  }

  cout << coinChange(total, coins) << endl;
}

int coinChange(int total, int coins[]){
  int dp[total + 1];
  int curr;
  int min;

  dp[0] = 0;

  for(int i = 1; i <= total; i++){
    min = INT32_MAX;
    for(int j = 0; j < sizeof(coins) / sizeof(int) + 1; j++){
      if(coins[j] <= i){
        curr = 1 + dp[i - coins[j]];
      }
      if(curr < min){
        min = curr;
      }
    }

    dp[i] = min;
  }
  
  return dp[total];
}
