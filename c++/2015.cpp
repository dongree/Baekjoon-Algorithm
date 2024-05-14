#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

int dp[200001];
map<ll, ll> dic;

int main() {
  freopen("example.txt", "r", stdin);
  int N, K;
  cin >> N >> K;
  ll ans = 0;

  for (int i = 1; i <= N; i++) {
    cin >> dp[i];
    dp[i] += dp[i - 1];
    if (dp[i] == K) ans++;
  }

  for (int i = 1; i <= N; i++) {
    ans += dic[dp[i] - K];
    dic[dp[i]]++;
  }

  cout << ans;
  return 0;
}