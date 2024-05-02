#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;

using namespace std;

int N, M, a, b, c;
vector<pair<int, int>> adjList[100001];
bool isVisited[100001];
ll totalW = 0;
ll ww = 0;
int cnt = 0;

void prim() {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;

  pq.push({0, 1});

  while (!pq.empty()) {
    int w = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (isVisited[node]) continue;

    cnt++;
    ww += w;
    isVisited[node] = true;

    for (int i = 0; i < adjList[node].size(); i++) {
      int nextNode = adjList[node][i].second;
      int nextWeight = adjList[node][i].first;
      if (!isVisited[nextNode]) {
        pq.push({nextWeight, nextNode});
      }
    }
  }
}

void dfs() {}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> M;

  while (M--) {
    cin >> a >> b >> c;
    adjList[a].push_back({c, b});
    adjList[b].push_back({c, a});
    totalW += c;
  }

  prim();

  cout << (cnt == N ? totalW - ww : -1);

  return 0;
}