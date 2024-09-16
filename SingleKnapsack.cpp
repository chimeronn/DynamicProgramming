#include <iostream>
#include <vector>
using namespace std;

int knapsack(int numItems, int maxC, vector<int> weights, vector<int> vals) {
  vector<int> ans(maxC + 1);
  for(int i = 1; i < weights.size(); ++i) {
    for(int j = maxC; j >= weights[i]; --j) {
      ans[j] = max(ans[j], ans[j - weights[i]] + vals[i]);
    }
  }
  //for(int i : ans) cout << i << " ";
  //cout << "\n";
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
