#include <algorithm>
#include <iostream>

#define INF 1e9

using namespace std;

int dist[101][101];

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      dist[i][j] = INF;
    }
  }

  while (M--) {
    int A, B;
    cin >> A >> B;
    dist[A][B] = 1;
    dist[B][A] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int result[3];
  result[0] = 1;
  result[1] = 2;
  result[2] = INF;

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      int roundT = 0;
      for (int k = 1; k <= N; k++) {
        roundT += min(dist[i][k], dist[j][k]) * 2;
      }
      if (roundT < result[2]) {
        result[0] = i;
        result[1] = j;
        result[2] = roundT;
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    cout << result[i] << ' ';
  }

  return 0;
}