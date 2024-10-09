#include <iostream>

using namespace std;

int dp[5001][5001];  // i번부터 j번까지 부분수열을 펠린드롬으로 만들기 위해
                     // 필요한 최소 삽입 횟수
int arr[5001];

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  // 초기 조건
  for (int i = 0; i < N - 1; i++) {
    if (arr[i] != arr[i + 1]) dp[i][i + 1] = 1;
  }

  for (int len = 3; len <= N; len++) {
    for (int i = 0; i <= N - len; i++) {
      int j = i + len - 1;
      if (arr[i] == arr[j])
        dp[i][j] = dp[i + 1][j - 1];
      else
        dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
    }
  }

  cout << dp[0][N - 1];

  return 0;
}