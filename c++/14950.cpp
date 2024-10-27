#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adjList[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
bool isVisited[10001];
int ans = 0;
int k = 0;
;

int main() {
  freopen("example.txt", "r", stdin);

  int N, M, t;
  cin >> N >> M >> t;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adjList[a].push_back({c, b});
    adjList[b].push_back({c, a});
  }

  pq.push({0, 1});

  while (!pq.empty()) {
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (isVisited[node]) continue;
    isVisited[node] = true;
    if (node != 1) {
      ans += k + weight;
      k += t;
    }

    for (int i = 0; i < adjList[node].size(); i++) {
      int nextWeight = adjList[node][i].first;
      int nextNode = adjList[node][i].second;
      if (!isVisited[nextNode]) {
        pq.push({nextWeight, nextNode});
      }
    }
  }

  cout << ans;

  return 0;
}