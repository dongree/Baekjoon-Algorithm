#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9;

using namespace std;

vector<pair<int, int>> adjList[100001];
int distA[100001];
int distB[100001];
int distC[100001];

void dijkstra(int n, int dist[]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  dist[n] = 0;
  pq.push({0, n});

  while (!pq.empty()) {
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    // cout << adjList[node].size() << "\n";

    if (dist[node] < weight) continue;

    for (int i = 0; i < adjList[node].size(); i++) {
      int nextWeigth = weight + adjList[node][i].first;
      int nextNode = adjList[node][i].second;
      if (nextWeigth < dist[nextNode]) {
        dist[nextNode] = nextWeigth;
        pq.push({nextWeigth, nextNode});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int N, M, A, B, C;

  cin >> N;
  cin >> A >> B >> C;
  cin >> M;

  while (M--) {
    int D, E, L;

    cin >> D >> E >> L;
    adjList[D].push_back({L, E});
    adjList[E].push_back({L, D});
  }

  for (int i = 1; i <= N; i++) {
    distA[i] = INF;
    distB[i] = INF;
    distC[i] = INF;
  }

  dijkstra(A, distA);
  dijkstra(B, distB);
  dijkstra(C, distC);

  int ans;
  int dist = 0;
  for (int i = 1; i <= N; i++) {
    if (i == A || i == B || i == C) continue;

    int k = min(min(distA[i], distB[i]), distC[i]);
    if (dist < k) {
      dist = k;
      ans = i;
    }
  }

  cout << ans;

  return 0;
}