#include <iostream>
#include <vector>

#define INF 2000000000

using namespace std;

// 행렬 i에서 j까지 곱했을 때 최소 곱연산 횟수
int dp[501][501];
vector<pair<int, int>> matrix;
int n;

int main() {
  freopen("example.txt", "r", stdin);
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    matrix.push_back({a, b});
  }

  for (int gap = 1; gap < n; gap++) {
    for (int start = 0; start < n - gap; start++) {
      int end = start + gap;
      dp[start][end] = INF;
      for (int j = start; j <= end; j++) {
        dp[start][end] =
            min(dp[start][end], dp[start][j] + dp[j + 1][end] +
                                    matrix[start].first * matrix[j].second *
                                        matrix[end].second);
      }
    }
  }

  cout << dp[0][n - 1];

  return 0;
}