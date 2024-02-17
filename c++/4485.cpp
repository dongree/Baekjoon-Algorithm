#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int N;
int cave[125][125];
int minDist[125][125];

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> cave[i][j];
      minDist[i][j] = INT_MAX;
    }
  }
  minDist[0][0] = cave[0][0];
}

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

int main() {
  freopen("example.txt", "r", stdin);

  int num = 1;
  while (cin >> N) {
    if (N == 0) break;
    init();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    pq.push({cave[0][0], {0, 0}});

    while (!pq.empty()) {
      int weight = pq.top().first;
      int y = pq.top().second.first;
      int x = pq.top().second.second;
      pq.pop();
      if (weight < minDist[y][x]) continue;

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (inRange(ny, nx)) {
          int nw = weight + cave[ny][nx];
          if (minDist[ny][nx] > nw) {
            minDist[ny][nx] = nw;
            pq.push({nw, {ny, nx}});
          }
        }
      };
    }

    cout << "Problem " << num << ": " << minDist[N - 1][N - 1] << '\n';
    num++;
  };

  return 0;
}