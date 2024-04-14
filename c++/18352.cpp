#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adjList[300001];
int dist[300001];
vector<int> answer;

int main() {
  freopen("example.txt", "r", stdin);
  int N, M, K, X;

  cin >> N >> M >> K >> X;

  while (M--) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
  }

  for (int i = 1; i <= N; i++) {
    dist[i] = -1;
  }

  queue<int> q;
  q.push(X);
  dist[X] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    if (dist[node] == K) {
      answer.push_back(node);
    }

    for (int i = 0; i < adjList[node].size(); i++) {
      int next = adjList[node][i];
      if (dist[next] == -1) {
        dist[next] = dist[node] + 1;
        q.push(next);
      }
    }
  }

  if (answer.size() == 0) {
    cout << -1;
  } else {
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << '\n';
    }
  }

  return 0;
}