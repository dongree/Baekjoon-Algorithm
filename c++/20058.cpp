#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int N, Q;
int ice[64][64];
int temp[64][64];
bool isVisited[64][64];

int bfs(int y, int x, int NN) {
  queue<pair<int, int>> q;

  q.push({y, x});
  isVisited[y][x] = true;
  int cnt = 1;

  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (0 <= ny && ny < NN && 0 <= nx && nx < NN && !isVisited[ny][nx] &&
          ice[ny][nx] != 0) {
        isVisited[ny][nx] = true;
        cnt++;
        q.push({ny, nx});
      }
    }
  }

  return cnt;
}

void rotate(int y, int x, int gap) {
  for (int i = 0; i < gap; i++) {
    for (int j = 0; j < gap; j++) {
      temp[j][gap - i - 1] = ice[y + i][x + j];
    }
  }

  for (int i = 0; i < gap; i++) {
    for (int j = 0; j < gap; j++) {
      ice[y + i][x + j] = temp[i][j];
    }
  }
}

void melt(int NN) {
  int melting[64][64] = {
      0,
  };
  for (int i = 0; i < NN; i++) {
    for (int j = 0; j < NN; j++) {
      if (ice[i][j] == 0) continue;

      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (0 <= ny && ny < NN && 0 <= nx && nx < NN && ice[ny][nx] > 0) cnt++;
      }
      if (cnt < 3) melting[i][j]++;
    }
  }

  for (int i = 0; i < NN; i++) {
    for (int j = 0; j < NN; j++) {
      ice[i][j] -= melting[i][j];
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;

  int NN = pow(2, N);

  for (int i = 0; i < NN; i++) {
    for (int j = 0; j < NN; j++) {
      cin >> ice[i][j];
    }
  }

  while (Q--) {
    int L;
    cin >> L;

    int gap = pow(2, L);
    // 모든 격자를 2^L * 2^L 크기로 나누기
    for (int i = 0; i < NN; i += gap) {
      for (int j = 0; j < NN; j += gap) {
        rotate(i, j, gap);
      }
    }
    melt(NN);
  }
  int answer = 0;
  int answerCnt = 0;

  for (int i = 0; i < NN; i++) {
    for (int j = 0; j < NN; j++) {
      if (!isVisited[i][j] && ice[i][j] != 0) {
        answerCnt = max(answerCnt, bfs(i, j, NN));
      }
      answer += ice[i][j];
    }
  }

  cout << answer << '\n' << answerCnt;

  return 0;
}