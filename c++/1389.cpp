// Floyd warshall 풀이
#include <climits>
#include <iostream>

#define MAX 200

using namespace std;

int relationship[101][101];

int main() {
  freopen("example.txt", "r", stdin);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) relationship[i][j] = MAX;
    }
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    relationship[a][b] = 1;
    relationship[b][a] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (relationship[i][k] + relationship[k][j] < relationship[i][j]) {
          relationship[i][j] = relationship[i][k] + relationship[k][j];
        }
      }
    }
  }

  int answerNum = INT_MAX;
  int answerIdx = 0;

  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += relationship[i][j];
    }
    if (sum < answerNum) {
      answerNum = sum;
      answerIdx = i;
    }
  }

  cout << answerIdx;

  return 0;
}

// BFS 풀이
// #include <climits>
// #include <iostream>
// #include <queue>
// #include <utility>
// #include <vector>

// #define MAX 200

// using namespace std;

// int n, m;
// vector<int> relationship[101];
// bool isVisited[101];
// int bacon[101];

// void reset() {
//   for (int i = 1; i <= n; i++) {
//     isVisited[i] = false;
//   }
// }

// void bfs(int start) {
//   queue<pair<int, int>> q;
//   q.push({start, 0});
//   while (!q.empty()) {
//     int node = q.front().first;
//     int cnt = q.front().second;
//     q.pop();

//     if (!isVisited[node]) {
//       isVisited[node] = true;
//       bacon[node] += cnt;
//       for (int i = 0; i < relationship[node].size(); i++) {
//         q.push({relationship[node][i], cnt + 1});
//       }
//     }
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);

//   cin >> n >> m;

//   for (int i = 0; i < m; i++) {
//     int a, b;
//     cin >> a >> b;
//     relationship[a].push_back(b);
//     relationship[b].push_back(a);
//   }

//   for (int i = 1; i <= n; i++) {
//     reset();
//     bfs(i);
//   }

//   int answerNum = INT_MAX;
//   int answerIdx = 0;

//   for (int i = 1; i <= n; i++) {
//     if (bacon[i] < answerNum) {
//       answerNum = bacon[i];
//       answerIdx = i;
//     }
//   }

//   cout << answerIdx;

//   return 0;
// }