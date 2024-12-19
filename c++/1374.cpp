#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int n, a, b;
    cin >> n >> a >> b;

    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  pq.push(v[0].second);

  int result = 1;

  for (int i = 1; i < N; i++) {
    while (!pq.empty() && v[i].first >= pq.top()) {
      pq.pop();
    }
    pq.push(v[i].second);

    if (result < pq.size()) result = pq.size();
  }

  cout << result;

  return 0;
}