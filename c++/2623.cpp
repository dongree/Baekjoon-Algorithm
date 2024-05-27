// bfs
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// vector<int> adjList[1001];
// int indegree[1001];

// int main() {
//   freopen("example.txt", "r", stdin);

//   int N, M;
//   cin >> N >> M;

//   while (M--) {
//     int n;
//     cin >> n;
//     vector<int> v;
//     while (n--) {
//       int a;
//       cin >> a;
//       v.push_back(a);
//     }

//     for (int i = 0; i < v.size() - 1; i++) {
//       adjList[v[i]].push_back(v[i + 1]);
//       indegree[v[i + 1]]++;
//     }
//   }

//   queue<int> q;
//   vector<int> ans;

//   for (int i = 1; i <= N; i++) {
//     if (indegree[i] == 0) q.push(i);
//   }

//   while (!q.empty()) {
//     int n = q.front();
//     q.pop();
//     ans.push_back(n);

//     for (int i = 0; i < adjList[n].size(); i++) {
//       int nn = adjList[n][i];

//       indegree[nn]--;
//       if (indegree[nn] == 0) {
//         q.push(nn);
//       }
//     }
//   }

//   if (ans.size() != N) {
//     cout << 0;
//     return 0;
//   }

//   for (int i = 0; i < ans.size(); i++) {
//     cout << ans[i] << '\n';
//   }

//   return 0;
// }

// dfs
#include <iostream>
#include <vector>

using namespace std;

vector<int> adjList[1001];
vector<int> stack;
bool isVisited[1001];
bool finish[1001];
bool isCycle = false;

void dfs(int n) {
  isVisited[n] = true;

  for (int i = 0; i < adjList[n].size(); i++) {
    int nn = adjList[n][i];
    if (!isVisited[nn]) {
      dfs(nn);
    } else if (!finish[nn]) {
      isCycle = true;
    }
  }
  finish[n] = true;
  stack.push_back(n);
}

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  while (M--) {
    int n;
    cin >> n;
    vector<int> v;
    while (n--) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    for (int i = 0; i < v.size() - 1; i++) {
      adjList[v[i]].push_back(v[i + 1]);
    }
  }
  for (int i = 1; i <= N; i++) {
    if (!isVisited[i]) {
      dfs(i);
    }
  }

  if (isCycle) {
    cout << 0;
    return 0;
  }

  for (int i = stack.size() - 1; i >= 0; i--) {
    cout << stack[i] << '\n';
  }

  return 0;
}