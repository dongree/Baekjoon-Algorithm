#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<int> v;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  vector<int> diff;

  for (int i = 0; i < N - 1; i++) {
    diff.push_back(v[i + 1] - v[i]);
  }

  sort(diff.begin(), diff.end());

  int ans = 0;

  for (int i = 0; i < N - K; i++) {
    ans += diff[i];
  }

  cout << ans;

  return 0;
}