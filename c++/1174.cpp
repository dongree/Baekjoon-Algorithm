#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> v;

void dfs(ll num, int level) {
  if (level > 10) return;
  v.push_back(num);
  for (int i = 0; i < num % 10; i++) {
    dfs(num * 10 + i, level + 1);
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < 10; i++) {
    dfs(i, 1);
  }

  sort(v.begin(), v.end());

  if (N <= v.size())
    cout << v[N - 1];
  else
    cout << -1;

  return 0;
}