#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;

using namespace std;

queue<pair<ll, ll>> q;
vector<pair<ll, ll>> v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    ll a;
    cin >> a;
    q.push({a, i});
  }

  while (q.size() > 1) {
    v.clear();
    while (!q.empty()) {
      ll a = q.front().first;
      ll b = q.front().second;
      q.pop();

      ll aa = a;
      if (q.size() > 0 && q.front().first <= aa) {
        a += q.front().first;
        q.pop();
      }

      if (v.size() > 0 && v.back().first <= aa) {
        a += v.back().first;
        v.pop_back();
      }

      v.push_back({a, b});
    }

    for (int i = 0; i < v.size(); i++) {
      q.push(v[i]);
    }
  }

  cout << q.front().first << '\n' << q.front().second;

  return 0;
}