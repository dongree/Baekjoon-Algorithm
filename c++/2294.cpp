#include <algorithm>
#include <iostream>
#include <vector>

#define INF 1e9

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

  sort(v.begin(), v.end());

  for (int i = 1; i <= k; i++) {
    int minV = INF;
    for (int j = 0; j < v.size(); j++) {
      if (v[j] > i) break;
      minV = min(dp[i - v[j]] + 1, minV);
    }
    dp[i] = minV;
  }

  cout << (dp[k] == INF ? -1 : dp[k]);

  return 0;
}