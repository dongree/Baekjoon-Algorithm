#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, int>> goods;
// dp[i][j] : 용량이 j일 때 i번까지 물품들 중 최적으로 고른 물품둘의 가치의 합
int dp[101][100001];

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n >> k;
  goods.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    goods.push_back({w, v});
  }

  for (int i = 1; i <= n; i++) {
    int weight = goods[i].first;
    int value = goods[i].second;
    for (int j = 1; j <= k; j++) {
      if (j < weight)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
    }
  }

  cout << dp[n][k];

  return 0;
}