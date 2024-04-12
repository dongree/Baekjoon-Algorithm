// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <queue>

// using namespace std;

// int dy[4] = {0, 1, 0, -1};
// int dx[4] = {1, 0, -1, 0};

// int N, Q;
// int ice[64][64];
// int temp[64][64];
// bool isVisited[64][64];

// int bfs(int y, int x, int NN) {
//   queue<pair<int, int>> q;

//   q.push({y, x});
//   isVisited[y][x] = true;
//   int cnt = 1;

//   while (!q.empty()) {
//     int cy = q.front().first;
//     int cx = q.front().second;
//     q.pop();

//     for (int i = 0; i < 4; i++) {
//       int ny = cy + dy[i];
//       int nx = cx + dx[i];
//       if (0 <= ny && ny < NN && 0 <= nx && nx < NN && !isVisited[ny][nx] &&
//           ice[ny][nx] != 0) {
//         isVisited[ny][nx] = true;
//         cnt++;
//         q.push({ny, nx});
//       }
//     }
//   }

//   return cnt;
// }

// void rotate(int y, int x, int gap) {
//   for (int i = 0; i < gap; i++) {
//     for (int j = 0; j < gap; j++) {
//       temp[j][gap - i - 1] = ice[y + i][x + j];
//     }
//   }

//   for (int i = 0; i < gap; i++) {
//     for (int j = 0; j < gap; j++) {
//       ice[y + i][x + j] = temp[i][j];
//     }
//   }
// }

// void melt(int NN) {
//   int melting[64][64] = {
//       0,
//   };
//   for (int i = 0; i < NN; i++) {
//     for (int j = 0; j < NN; j++) {
//       if (ice[i][j] == 0) continue;

//       int cnt = 0;
//       for (int k = 0; k < 4; k++) {
//         int ny = i + dy[k];
//         int nx = j + dx[k];
//         if (0 <= ny && ny < NN && 0 <= nx && nx < NN && ice[ny][nx] > 0)
//         cnt++;
//       }
//       if (cnt < 3) melting[i][j]++;
//     }
//   }

//   for (int i = 0; i < NN; i++) {
//     for (int j = 0; j < NN; j++) {
//       ice[i][j] -= melting[i][j];
//     }
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N >> Q;

//   int NN = pow(2, N);

//   for (int i = 0; i < NN; i++) {
//     for (int j = 0; j < NN; j++) {
//       cin >> ice[i][j];
//     }
//   }

//   while (Q--) {
//     int L;
//     cin >> L;

//     int gap = pow(2, L);
//     // 모든 격자를 2^L * 2^L 크기로 나누기
//     for (int i = 0; i < NN; i += gap) {
//       for (int j = 0; j < NN; j += gap) {
//         rotate(i, j, gap);
//       }
//     }
//     melt(NN);
//   }
//   int answer = 0;
//   int answerCnt = 0;

//   for (int i = 0; i < NN; i++) {
//     for (int j = 0; j < NN; j++) {
//       if (!isVisited[i][j] && ice[i][j] != 0) {
//         answerCnt = max(answerCnt, bfs(i, j, NN));
//       }
//       answer += ice[i][j];
//     }
//   }

//   cout << answer << '\n' << answerCnt;

//   return 0;
// }

// my new solution
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>

#define MAX 64

using namespace std;

int board[MAX][MAX];
int temp[MAX][MAX];
bool isVisited[MAX][MAX];

int N, Q, n;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < n; }

void rotate(int y, int x, int gap) {
  for (int i = 0; i < gap; i++) {
    for (int j = 0; j < gap; j++) {
      temp[i][j] = board[y + i][x + j];
    }
  }

  for (int i = y; i < y + gap; i++) {
    for (int j = x; j < x + gap; j++) {
      board[i][j] = temp[x + gap - j - 1][i - y];
    }
  }
}

void fireStorm(int L) {
  int gap = pow(2, L);

  for (int i = 0; i < n; i += gap) {
    for (int j = 0; j < n; j += gap) {
      rotate(i, j, gap);
    }
  }

  memset(temp, 0, sizeof(temp));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0) {
        continue;
      }
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (inRange(ny, nx) && board[ny][nx] != 0) cnt++;
      }
      if (cnt <= 2) {
        temp[i][j] = board[i][j] - 1;
      } else {
        temp[i][j] = board[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = temp[i][j];
    }
  }
}

int getIceSum() {
  int iceSum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      iceSum += board[i][j];
    }
  }
  return iceSum;
}

int getLargestIce() {
  queue<pair<int, int>> q;
  int maxCnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0 || isVisited[i][j]) continue;

      q.push({i, j});
      isVisited[i][j] = true;
      int cnt = 1;

      while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
          int ny = y + dy[k];
          int nx = x + dx[k];
          if (inRange(ny, nx) && !isVisited[ny][nx] && board[ny][nx] != 0) {
            isVisited[ny][nx] = true;
            q.push({ny, nx});
            cnt++;
          }
        }
      }

      if (cnt > maxCnt) {
        maxCnt = cnt;
      }
    }
  }

  return maxCnt;
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;

  n = pow(2, N);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  while (Q--) {
    int L;
    cin >> L;
    fireStorm(L);
  }

  int iceSum = getIceSum();
  int largestIce = getLargestIce();

  cout << iceSum << '\n' << largestIce;
  return 0;
}