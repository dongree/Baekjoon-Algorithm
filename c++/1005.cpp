#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int N, K, W;
    int D[1001];
    int dp[1001] = {0};
    int indegree[1001] = {0};
    vector<int> graph[1001];

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
      cin >> D[i];
    }

    while (K--) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      indegree[b]++;
    }

    cin >> W;

    queue<int> q;

    for (int i = 1; i <= N; i++) {
      if (indegree[i] == 0) {
        q.push(i);
        dp[i] = D[i];
      }
    }

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (int i = 0; i < graph[curr].size(); i++) {
        int next = graph[curr][i];

        if (dp[next] < D[next] + dp[curr]) {
          dp[next] = D[next] + dp[curr];
        }

        indegree[next]--;
        if (indegree[next] == 0) q.push(next);
      }
    }

    cout << dp[W] << '\n';
  }

  return 0;
}