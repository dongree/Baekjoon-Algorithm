#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int dp[101][10001];  // dp[i][j]  공부시간이 j일 때 i번째 단원까지 공부할 수
                     // 있을 때 얻을 수 있는 최대 점수

int main() {
  freopen("example.txt", "r", stdin);
  int N, T;
  cin >> N >> T;

  v.push_back({0, 0});
  for (int i = 0; i < N; i++) {
    int K, S;
    cin >> K >> S;

    v.push_back({K, S});
  }

  for (int i = 1; i <= N; i++) {
    int time = v[i].first;
    int point = v[i].second;
    for (int j = 1; j <= T; j++) {
      if (j < time)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time] + point);
    }
  }

  cout << dp[N][T];

  return 0;
}