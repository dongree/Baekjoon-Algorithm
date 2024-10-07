#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int s, t;
    cin >> s >> t;
    v.push_back({s, t});
  }

  sort(v.begin(), v.end());

  pq.push(v[0].second);
  int ans = 1;

  for (int i = 1; i < N; i++) {
    while (!pq.empty() && pq.top() <= v[i].first) {
      pq.pop();
    }
    pq.push(v[i].second);
    ans = max(ans, (int)pq.size());
  }

  cout << ans;

  return 0;
}