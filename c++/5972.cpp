#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

vector<pair<int, int>> adjList[50001];
int dist[50001];

void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 1});
  dist[1] = 0;

  while (!pq.empty()) {
    int cowCnt = pq.top().first;
    int node = pq.top().second;

    pq.pop();

    if (cowCnt > dist[node]) continue;

    for (int i = 0; i < adjList[node].size(); i++) {
      int nextCowCnt = cowCnt + adjList[node][i].first;
      int nextNode = adjList[node][i].second;

      if (dist[nextNode] > nextCowCnt) {
        dist[nextNode] = nextCowCnt;
        pq.push({nextCowCnt, nextNode});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    adjList[a].push_back({c, b});
    adjList[b].push_back({c, a});
  }

  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }

  dijkstra();

  cout << dist[N];

  return 0;
}