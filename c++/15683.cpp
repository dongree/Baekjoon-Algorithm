// 첫번째 풀이
// #include <algorithm>
// #include <iostream>

// using namespace std;

// int N, M;
// int arr[8][8];
// int cctvRange[8][8];
// int answer = 100;
// int cctvNum;

// void shot(int y, int x, int direction, bool isEnd) {
//   int value = isEnd ? -1 : 1;
//   // 동, 남, 서 , 북
//   switch (direction) {
//     case 0: {
//       for (int i = x + 1; i < M; i++) {
//         if (arr[y][i] == 6) break;
//         if (arr[y][i] != 0) continue;
//         cctvRange[y][i] += value;
//       }
//       break;
//     }
//     case 1: {
//       for (int i = y + 1; i < N; i++) {
//         if (arr[i][x] == 6) break;
//         if (arr[i][x] != 0) continue;
//         cctvRange[i][x] += value;
//       }
//       break;
//     }
//     case 2: {
//       for (int i = x - 1; i >= 0; i--) {
//         if (arr[y][i] == 6) break;
//         if (arr[y][i] != 0) continue;
//         cctvRange[y][i] += value;
//       }
//       break;
//     }
//     case 3: {
//       for (int i = y - 1; i >= 0; i--) {
//         if (arr[i][x] == 6) break;
//         if (arr[i][x] != 0) continue;
//         cctvRange[i][x] += value;
//       }
//       break;
//     }
//     default:
//       break;
//   }
// }

// void dfs(int y, int x, int cnt) {
//   if (cctvNum == cnt) {
//     int aCnt = 0;
//     for (int i = 0; i < N; i++) {
//       for (int j = 0; j < M; j++) {
//         if (cctvRange[i][j] == 0) aCnt++;
//       }
//     }

//     answer = min(answer, aCnt);
//     return;
//   }

//   for (int i = y; i < N; i++) {
//     for (int j = 0; j < M; j++) {
//       if (i == y && j <= x) continue;

//       int cctv = arr[i][j];
//       switch (cctv) {
//         case 1: {
//           for (int k = 0; k < 4; k++) {
//             shot(i, j, k, false);
//             dfs(i, j, cnt + 1);
//             shot(i, j, k, true);
//           }
//           break;
//         }
//         case 2: {
//           for (int k = 0; k < 2; k++) {
//             shot(i, j, k, false);
//             shot(i, j, k + 2, false);
//             dfs(i, j, cnt + 1);
//             shot(i, j, k, true);
//             shot(i, j, k + 2, true);
//           }
//           break;
//         }
//         case 3: {
//           for (int k = 0; k < 4; k++) {
//             shot(i, j, k, false);
//             shot(i, j, (k + 1) % 4, false);
//             dfs(i, j, cnt + 1);
//             shot(i, j, k, true);
//             shot(i, j, (k + 1) % 4, true);
//           }
//           break;
//         }
//         case 4: {
//           for (int k = 0; k < 4; k++) {
//             shot(i, j, k, false);
//             shot(i, j, (k + 1) % 4, false);
//             shot(i, j, (k + 2) % 4, false);
//             dfs(i, j, cnt + 1);
//             shot(i, j, k, true);
//             shot(i, j, (k + 1) % 4, true);
//             shot(i, j, (k + 2) % 4, true);
//           }
//           break;
//         }
//         case 5: {
//           shot(i, j, 0, false);
//           shot(i, j, 1, false);
//           shot(i, j, 2, false);
//           shot(i, j, 3, false);
//           dfs(i, j, cnt + 1);
//           shot(i, j, 0, true);
//           shot(i, j, 1, true);
//           shot(i, j, 2, true);
//           shot(i, j, 3, true);
//           break;
//         }
//         default:
//           break;
//       }
//     }
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cin >> N >> M;

//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < M; j++) {
//       cin >> arr[i][j];
//       cctvRange[i][j] = arr[i][j];
//       if (1 <= arr[i][j] && arr[i][j] <= 5) {
//         cctvNum++;
//       }
//     }
//   }
//   dfs(0, -1, 0);

//   cout << answer;
//   return 0;
// }

// 다른 사람풀이 (+리팩토링)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[8][8];
vector<pair<int, int>> cctv;
int answer = 100;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void check(int y, int x, int dir) {
  dir %= 4;
  while (1) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    y = ny;
    x = nx;
    if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) return;
    if (arr[ny][nx] == 6) return;
    if (arr[ny][nx] != 0) continue;
    arr[ny][nx] = -1;
  }
}

void dfs(int idx) {
  if (cctv.size() == idx) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (arr[i][j] == 0) cnt++;
      }
    }
    answer = min(answer, cnt);
    return;
  }

  int y = cctv[idx].first;
  int x = cctv[idx].second;
  int tmp[8][8];

  for (int dir = 0; dir < 4; dir++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        tmp[i][j] = arr[i][j];
      }
    }

    switch (arr[y][x]) {
      case 1: {
        check(y, x, dir);
        break;
      }
      case 2: {
        check(y, x, dir);
        check(y, x, dir + 2);
        break;
      }
      case 3: {
        check(y, x, dir);
        check(y, x, dir + 1);
        break;
      }
      case 4: {
        check(y, x, dir);
        check(y, x, dir + 1);
        check(y, x, dir + 2);
        break;
      }
      case 5: {
        check(y, x, dir);
        check(y, x, dir + 1);
        check(y, x, dir + 2);
        check(y, x, dir + 3);
        break;
      }
      default:
        break;
    }

    dfs(idx + 1);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        arr[i][j] = tmp[i][j];
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
      if (1 <= arr[i][j] && arr[i][j] <= 5) {
        cctv.push_back({i, j});
      }
    }
  }
  dfs(0);

  cout << answer;
  return 0;
}
