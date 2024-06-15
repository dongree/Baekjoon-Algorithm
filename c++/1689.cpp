#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main() {
  freopen("example.txt", "r", stdin);
  int n;
  cin >> n;

  while (n--) {
    int x1, x2;
    cin >> x1 >> x2;
    v.push_back({x1, 1});
    v.push_back({x2, -1});
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << ' ' << v[i].second << '\n';
  }

  int ans = 0;

  int k = 0;
  for (int i = 0; i < v.size(); i++) {
    k += v[i].second;
    if (k > ans) ans = k;
  }

  cout << ans;

  return 0;
}