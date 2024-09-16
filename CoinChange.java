class Main {
  public static void main(String[] args) {
    int[] coins = {1, 2, 5};
    int amount = 11;
    System.out.println(coinChange(coins, amount));
  }

  public static int coinChange(int[] coins, int amount) {
        int numCoins = coins.length;
        int min = Integer.MAX_VALUE - 1;
        int curr = min;
        int[] dp = new int[amount + 1];
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
          min = Integer.MAX_VALUE;
            for(int j = 0; j < numCoins; j++){
                int coinVal = coins[j];
                if(coinVal <= i){
                  curr = 1 + dp[i - coinVal];
                }
                if(curr < min){
                    min = curr;
                }
            }
          dp[i] = min;
        }

        return dp[amount];
    }
}
