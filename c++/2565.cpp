#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int dp[100];

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    int k = 0;
    for (int j = 0; j < i; j++) {
      if (v[j].second < v[i].second) k = max(k, dp[j]);
    }
    dp[i] = k + 1;
  }

  int a = 0;
  for (int i = 0; i < N; i++) {
    a = max(a, dp[i]);
  }

  cout << N - a;

  return 0;
}