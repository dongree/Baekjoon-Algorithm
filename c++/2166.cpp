#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

vector<pair<int, int>> v;

ll getTrianlge(pair<int, int> a, pair<int, int> b) {
  ll ax = a.first;
  ll ay = a.second;
  ll bx = b.first;
  ll by = b.second;

  ll sx = v[0].first;
  ll sy = v[0].second;

  return (ax - sx) * (by - sy) - (bx - sx) * (ay - sy);
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }

  double ans = 0;

  for (int i = 2; i < N; i++) {
    ans += getTrianlge(v[i], v[i - 1]);
  }

  cout << fixed;
  cout.precision(1);
  cout << abs(ans) / 2;

  return 0;
}