// bfs

// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// int indegree[32001];
// vector<int> adjList[32001];
// queue<int> q;

// int main() {
//   freopen("example.txt", "r", stdin);
//   int N, M;
//   cin >> N >> M;

//   while (M--) {
//     int a, b;
//     cin >> a >> b;
//     adjList[a].push_back(b);
//     indegree[b]++;
//   }

//   for (int i = 1; i <= N; i++) {
//     if (indegree[i] == 0) {
//       q.push(i);
//     }
//   }

//   while (!q.empty()) {
//     int curr = q.front();
//     q.pop();
//     cout << curr << ' ';

//     for (int i = 0; i < adjList[curr].size(); i++) {
//       int next = adjList[curr][i];
//       indegree[next]--;
//       if (indegree[next] == 0) q.push(next);
//     }
//   }

//   return 0;
// }

// dfs
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> adjList[32001];
stack<int> st;
bool isVisited[32001];

void dfs(int s) {
  isVisited[s] = true;

  for (int i = 0; i < adjList[s].size(); i++) {
    int next = adjList[s][i];
    if (!isVisited[next]) {
      dfs(next);
    }
  }
  st.push(s);
}

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  while (M--) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
  }

  for (int i = 1; i <= N; i++) {
    if (!isVisited[i]) {
      dfs(i);
    }
  }

  while (!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }

  return 0;
}
