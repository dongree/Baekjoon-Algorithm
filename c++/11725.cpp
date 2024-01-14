#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adjList[100001];
int parents[100001];
queue<int> q;

int main() {
  freopen("example.txt", "r", stdin);
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  q.push(1);
  parents[1] = -1;

  while (!q.empty()) {
    int front = q.front();
    q.pop();

    for (int i = 0; i < adjList[front].size(); i++) {
      int nodeNum = adjList[front][i];
      if (parents[nodeNum] == 0) {
        parents[nodeNum] = front;
        q.push(nodeNum);
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << parents[i] << '\n';
  }

  return 0;
}