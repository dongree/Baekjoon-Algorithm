#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int dp[10001];

int main() {
  freopen("example.txt", "r", stdin);
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = v[i]; j <= k; j++) {
      dp[j] += dp[j - v[i]];
    }
  }

  cout << dp[k];

  return 0;
}