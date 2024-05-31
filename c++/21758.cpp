#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int ps[100001];

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;
  vector<int> v;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
    ps[i + 1] = ps[i] + a;
  }

  int ans = 0;

  // 꿀 벌 벌
  for (int i = 1; i < N - 1; i++) {
    ans = max(ans, ps[i] + ps[N - 1] - v[i]);
  }

  // 벌 꿀 벌
  for (int i = 1; i < N - 1; i++) {
    ans = max(ans, ps[i + 1] - ps[1] + ps[N - 1] - ps[i]);
  }

  // 벌 벌 꿀
  for (int i = 1; i < N - 1; i++) {
    ans = max(ans, ps[N] - ps[1] - v[i] + ps[N] - ps[i + 1]);
  }

  cout << ans;

  return 0;
}