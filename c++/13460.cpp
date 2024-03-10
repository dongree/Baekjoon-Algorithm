// 내 풀이
// #include <iostream>
// #include <string>

// using namespace std;

// int N, M;
// char board[10][10];
// int by, bx, ry, rx, ty, tx;
// int answer = 100;

// void dfs(int cnt, int by, int bx, int ry, int rx) {
//   if (answer <= cnt || cnt > 10) return;

//   if (by == ty && bx == tx) {
//     return;
//   }

//   if (ry == ty && rx == tx) {
//     answer = cnt;
//     return;
//   }

//   for (int dir = 0; dir < 4; dir++) {
//     char temp[10][10];

//     for (int i = 0; i < N; i++) {
//       for (int j = 0; j < M; j++) {
//         temp[i][j] = board[i][j];
//       }
//     }
//     int tempBy = by;
//     int tempBx = bx;
//     int tempRy = ry;
//     int tempRx = rx;

//     switch (dir) {
//       case 0: {
//         if (bx < rx) {
//           board[by][bx] = '.';
//           while (board[by][bx - 1] == '.') {
//             bx--;
//           }
//           if (board[by][bx - 1] == 'O') {
//             bx--;
//           } else {
//             board[by][bx] = 'B';
//           }

//           board[ry][rx] = '.';
//           while (board[ry][rx - 1] == '.') {
//             rx--;
//           }
//           if (board[ry][rx - 1] == 'O') {
//             rx--;
//           } else {
//             board[ry][rx] = 'R';
//           }
//         } else {
//           board[ry][rx] = '.';
//           while (board[ry][rx - 1] == '.') {
//             rx--;
//           }
//           if (board[ry][rx - 1] == 'O') {
//             rx--;
//           } else {
//             board[ry][rx] = 'R';
//           }

//           board[by][bx] = '.';
//           while (board[by][bx - 1] == '.') {
//             bx--;
//           }
//           if (board[by][bx - 1] == 'O') {
//             bx--;
//           } else {
//             board[by][bx] = 'B';
//           }
//         }
//         break;
//       }
//       case 1: {
//         if (bx < rx) {
//           board[ry][rx] = '.';
//           while (board[ry][rx + 1] == '.') {
//             rx++;
//           }
//           if (board[ry][rx + 1] == 'O') {
//             rx++;
//           } else {
//             board[ry][rx] = 'R';
//           }

//           board[by][bx] = '.';
//           while (board[by][bx + 1] == '.') {
//             bx++;
//           }
//           if (board[by][bx + 1] == 'O') {
//             bx++;
//           } else {
//             board[by][bx] = 'B';
//           }
//         } else {
//           board[by][bx] = '.';
//           while (board[by][bx + 1] == '.') {
//             bx++;
//           }
//           if (board[by][bx + 1] == 'O') {
//             bx++;
//           } else {
//             board[by][bx] = 'B';
//           }

//           board[ry][rx] = '.';
//           while (board[ry][rx + 1] == '.') {
//             rx++;
//           }
//           if (board[ry][rx + 1] == 'O') {
//             rx++;
//           } else {
//             board[ry][rx] = 'R';
//           }
//         }
//         break;
//       }
//       case 2: {
//         if (by < ry) {
//           board[by][bx] = '.';
//           while (board[by - 1][bx] == '.') {
//             by--;
//           }
//           if (board[by - 1][bx] == 'O') {
//             by--;
//           } else {
//             board[by][bx] = 'B';
//           }

//           board[ry][rx] = '.';
//           while (board[ry - 1][rx] == '.') {
//             ry--;
//           }
//           if (board[ry - 1][rx] == 'O') {
//             ry--;
//           } else {
//             board[ry][rx] = 'R';
//           }
//         } else {
//           board[ry][rx] = '.';
//           while (board[ry - 1][rx] == '.') {
//             ry--;
//           }
//           if (board[ry - 1][rx] == 'O') {
//             ry--;
//           } else {
//             board[ry][rx] = 'R';
//           }

//           board[by][bx] = '.';
//           while (board[by - 1][bx] == '.') {
//             by--;
//           }
//           if (board[by - 1][bx] == 'O') {
//             by--;
//           } else {
//             board[by][bx] = 'B';
//           }
//         }
//         break;
//       }
//       case 3: {
//         if (by < ry) {
//           board[ry][rx] = '.';
//           while (board[ry + 1][rx] == '.') {
//             ry++;
//           }
//           if (board[ry + 1][rx] == 'O') {
//             ry++;
//           } else {
//             board[ry][rx] = 'R';
//           }

//           board[by][bx] = '.';
//           while (board[by + 1][bx] == '.') {
//             by++;
//           }
//           if (board[by + 1][bx] == 'O') {
//             by++;
//           } else {
//             board[by][bx] = 'B';
//           }
//         } else {
//           board[by][bx] = '.';
//           while (board[by + 1][bx] == '.') {
//             by++;
//           }
//           if (board[by + 1][bx] == 'O') {
//             by++;
//           } else {
//             board[by][bx] = 'B';
//           }

//           board[ry][rx] = '.';
//           while (board[ry + 1][rx] == '.') {
//             ry++;
//           }
//           if (board[ry + 1][rx] == 'O') {
//             ry++;
//           } else {
//             board[ry][rx] = 'R';
//           }
//         }
//         break;
//       }
//       default:
//         break;
//     }

//     dfs(cnt + 1, by, bx, ry, rx);

//     for (int i = 0; i < N; i++) {
//       for (int j = 0; j < M; j++) {
//         board[i][j] = temp[i][j];
//       }
//     }
//     by = tempBy;
//     bx = tempBx;
//     ry = tempRy;
//     rx = tempRx;
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N >> M;

//   for (int i = 0; i < N; i++) {
//     string s;
//     cin >> s;
//     for (int j = 0; j < M; j++) {
//       board[i][j] = s[j];
//       if (s[j] == 'B') {
//         by = i;
//         bx = j;
//       } else if (s[j] == 'R') {
//         ry = i;
//         rx = j;
//       } else if (s[j] == 'O') {
//         ty = i;
//         tx = j;
//       }
//     }
//   }

//   dfs(0, by, bx, ry, rx);

//   if (answer == 100) {
//     answer = -1;
//   }

//   cout << answer;

//   return 0;
// }

// 다른 사람 풀이
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct step {
  int ry;
  int rx;
  int by;
  int bx;
  int cnt;
};

int N, M;
char board[10][10];
bool isVisited[10][10][10][10];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int answer = -1;

int bfs(int Ry, int Rx, int By, int Bx) {
  queue<step> q;
  q.push({Ry, Rx, By, Bx, 0});
  isVisited[Ry][Rx][By][Bx] = true;

  while (!q.empty()) {
    int ry = q.front().ry;
    int rx = q.front().rx;
    int by = q.front().by;
    int bx = q.front().bx;
    int cnt = q.front().cnt;
    q.pop();

    if (cnt > 10) break;
    if (board[ry][rx] == 'O' && board[by][bx] != 'O') {
      answer = cnt;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nry = ry;
      int nrx = rx;
      int nby = by;
      int nbx = bx;

      while (board[nry + dy[i]][nrx + dx[i]] != '#' && board[nry][nrx] != 'O') {
        nry += dy[i];
        nrx += dx[i];
      }

      while (board[nby + dy[i]][nbx + dx[i]] != '#' && board[nby][nbx] != 'O') {
        nby += dy[i];
        nbx += dx[i];
      }

      if (nrx == nbx && nry == nby) {
        if (board[nry][nrx] != 'O') {
          int rdist = abs(nry - ry) + abs(nrx - rx);
          int bdist = abs(nby - by) + abs(nbx - bx);
          if (rdist > bdist) {
            nry -= dy[i];
            nrx -= dx[i];
          } else {
            nby -= dy[i];
            nbx -= dx[i];
          }
        }
      }

      if (!isVisited[nry][nrx][nby][nbx]) {
        isVisited[nry][nrx][nby][nbx] = true;
        q.push({nry, nrx, nby, nbx, cnt + 1});
      }
    }
  }

  return answer;
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  int ry, rx, by, bx;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R') {
        ry = i;
        rx = j;
      } else if (board[i][j] == 'B') {
        by = i;
        bx = j;
      }
    }
  }

  cout << bfs(ry, rx, by, bx);

  return 0;
}