#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adjList[100001];
bool isVisited[100001];
int V;
int maxDist = 0;
int endPoint = 0;

void initIsVisited() {
  for (int i = 1; i <= V; i++) {
    isVisited[i] = false;
  }
}

void dfs(int node, int dist) {
  if (dist > maxDist) {
    maxDist = dist;
    endPoint = node;
  }

  for (int i = 0; i < adjList[node].size(); i++) {
    int nextNode = adjList[node][i].second;
    int nextDist = adjList[node][i].first;

    if (!isVisited[nextNode]) {
      isVisited[nextNode] = true;
      dfs(nextNode, dist + nextDist);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> V;

  for (int i = 0; i < V; i++) {
    int a;
    cin >> a;
    while (true) {
      int b, dist;
      cin >> b;
      if (b == -1) break;
      cin >> dist;
      adjList[a].push_back({dist, b});
    }
  }

  isVisited[1] = true;
  dfs(1, 0);

  initIsVisited();
  isVisited[endPoint] = true;
  dfs(endPoint, 0);

  cout << maxDist;
  return 0;
}