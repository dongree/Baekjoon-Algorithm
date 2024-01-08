#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int main() {
  freopen("example.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> a;

  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    a.push_back(e);
  }

  for (int i = 0; i < n; i++) {
    int max = 0;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j] && dp[j] > max) max = dp[j];
    }
    dp[i] = max + 1;
  }

  int answer = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] > answer) answer = dp[i];
  }
  cout << answer;

  return 0;
}