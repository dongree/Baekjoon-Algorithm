#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() {
  freopen("example.txt", "r", stdin);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  pq.push(v[0].second);

  int answer = 1;
  for (int i = 1; i < n; i++) {
    while (!pq.empty() && pq.top() <= v[i].first) {
      pq.pop();
    }
    pq.push(v[i].second);
    answer = max(answer, (int)pq.size());
  }

  cout << answer;

  return 0;
}
