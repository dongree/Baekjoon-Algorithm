#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

// dp[i][l][r]  i번 수까지 입력 받았을 때 두 발이 l, r 위치에 있을 때 최소 힘 값
int dp[100000][5][5];

vector<int> v;
int n;

int calc(int a, int target) {
  if (a == 0)
    return 2;
  else if (a == target)
    return 1;
  else if (abs(a - target) == 2)
    return 4;
  else
    return 3;
}

int dfs(int l, int r, int idx) {
  if (idx == n) return 0;
  if (dp[idx][l][r] != -1) return dp[idx][l][r];

  int left = dfs(v[idx], r, idx + 1) + calc(l, v[idx]);
  int right = dfs(l, v[idx], idx + 1) + calc(r, v[idx]);

  return dp[idx][l][r] = min(left, right);
}

int main() {
  freopen("example.txt", "r", stdin);

  while (true) {
    int num;
    cin >> num;

    if (num == 0) break;
    v.push_back(num);
  }

  memset(dp, -1, sizeof(dp));

  n = v.size();
  cout << dfs(0, 0, 0);

  return 0;
}