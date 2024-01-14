#include <iostream>
#include <vector>

using namespace std;

int dp[10001];  // dp[i] : 주어진 동전을 활용해 금액 i를 만드는 경우의 수

void reset(int price) {
  for (int i = 0; i <= price; i++) {
    dp[i] = 0;
  }
  dp[0] = 1;
}

int main() {
  freopen("example.txt", "r", stdin);
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, price;
    vector<int> coins;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      coins.push_back(a);
    }
    cin >> price;
    reset(price);

    for (int i = 0; i < n; i++) {
      for (int j = coins[i]; j <= price; j++) {
        dp[j] += dp[j - coins[i]];
      }
    }

    cout << dp[price] << '\n';
  }

  return 0;
}