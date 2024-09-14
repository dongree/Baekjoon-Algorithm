#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, s, e;
vector<pair<int, int>> adjList[100001];
priority_queue<pair<int, int>> pq;
int paperNum[100001];

void dijkstra(int s, int e) {
  pq.push({1e9, s});
  paperNum[s] = 1e9;

  while (!pq.empty()) {
    int pn = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (int i = 0; i < adjList[node].size(); i++) {
      int npn = adjList[node][i].first;
      int nextNode = adjList[node][i].second;

      int n = min(pn, npn);
      if (paperNum[nextNode] < n) {
        paperNum[nextNode] = n;
        pq.push({n, nextNode});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N >> M >> s >> e;

  while (M--) {
    int h1, h2, k;
    cin >> h1 >> h2 >> k;

    adjList[h1].push_back({k, h2});
    adjList[h2].push_back({k, h1});
  }

  dijkstra(s, e);

  for (int i = 1; i <= N; i++) {
    cout << paperNum[i] << ' ';
  }
  cout << '\n';

  cout << paperNum[e];

  return 0;
}