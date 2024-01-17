#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define RED 1
#define BLUE 2

using namespace std;

vector<int> graph[20001];
int nodeColors[20001];

void reset(int n) {
  for (int i = 1; i <= n; i++) {
    while (!graph[i].empty()) graph[i].pop_back();
    nodeColors[i] = 0;
  }
}

void makeGraph(int E) {
  for (int i = 0; i < E; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

bool bfs(int start) {
  queue<pair<int, int>> q;
  q.push({start, RED});
  nodeColors[start] = RED;

  while (!q.empty()) {
    int node = q.front().first;
    int color = q.front().second;
    q.pop();

    for (int i = 0; i < graph[node].size(); i++) {
      int nextNode = graph[node][i];
      int nextColor = (color == RED ? BLUE : RED);
      if (nodeColors[nextNode] == 0) {
        nodeColors[nextNode] = nextColor;
        q.push({nextNode, nextColor});
      } else if (nodeColors[nextNode] == color) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  freopen("example.txt", "r", stdin);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;

  for (int t = 0; t < k; t++) {
    int V, E;
    cin >> V >> E;
    reset(V);
    makeGraph(E);

    string answer = "YES";
    for (int i = 1; i <= V; i++) {
      if (nodeColors[i] == 0 && !bfs(i)) {
        answer = "NO";
        break;
      }
    }

    cout << answer << '\n';
  }
  return 0;
}