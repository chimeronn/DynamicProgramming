#include <iostream>
#include <vector>
using namespace std;

int knapsack(int numItems, int maxC, vector<int> weights, vector<int> vals) {
  vector<int> ans(maxC + 1);
  for(int i = 1; i < maxC + 1; ++i) {
    ans[i] = ans[i - 1];
    for(int j = 0; j < weights.size(); ++j) {
      int curr = 0;
      if(i - weights[j] >= 0) {
        curr = vals[j] + ans[i - weights[j]];
      }
      ans[i] = max(ans[i], curr);
    }
  }
  /*for(int i : ans) {
    cout << i << " ";
  }*/
  cout << "\n";
  return ans[maxC];
}

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> weights(n);
  vector<int> vals(n);

  for(int i = 0; i < n; ++i) {
    cin >> weights[i] >> vals[i];
  }
  cout << knapsack(n, w, weights, vals);
}
