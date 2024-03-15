// 내 풀이
// #include <algorithm>
// #include <iostream>

// using namespace std;

// int N;
// int board[10][10];
// bool isVisited[10][10];
// int nums = 0;

// int dy[4] = {1, 1, -1, -1};
// int dx[4] = {1, -1, 1, -1};

// bool isOk(int y, int x) {
//   for (int i = 0; i < 4; i++) {
//     int ny = y + dy[i];
//     int nx = x + dx[i];
//     while (0 <= ny && ny < N && 0 <= nx && nx < N) {
//       if (isVisited[ny][nx]) return false;
//       ny += dy[i];
//       nx += dx[i];
//     }
//   }
//   return true;
// }

// void dfs(int cur, int cnt, bool color) {
//   nums = max(nums, cnt);

//   for (int i = cur; i < N * N; i++) {
//     int y = i / N;
//     int x = i % N;

//     if (color && (x + y) % 2 == 0) continue;
//     if (!color && (x + y) % 2 == 1) continue;

//     if (!isVisited[y][x] && board[y][x] && isOk(y, x)) {
//       isVisited[y][x] = true;
//       dfs(i + 1, cnt + 1, color);
//       isVisited[y][x] = false;
//     }
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N;

//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       cin >> board[i][j];
//     }
//   }

//   int result = 0;
//   dfs(0, 0, false);
//   result += nums;
//   nums = 0;

//   dfs(0, 0, true);
//   result += nums;

//   cout << result;

//   return 0;
// }

// 다른 사람 풀이
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int board[10][10];
bool isVisited1[20];
bool isVisited2[20];
int nums = 0;

void dfs(int cur, int cnt, bool color) {
  nums = max(nums, cnt);

  for (int i = cur; i < N * N; i++) {
    int y = i / N;
    int x = i % N;

    if (color && (x + y) % 2 == 0) continue;
    if (!color && (x + y) % 2 == 1) continue;

    if (board[y][x] && !isVisited1[y + x] && !isVisited2[y - x + N]) {
      isVisited1[y + x] = true;
      isVisited2[y - x + N] = true;
      dfs(i + 1, cnt + 1, color);
      isVisited1[y + x] = false;
      isVisited2[y - x + N] = false;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  int result = 0;
  dfs(0, 0, false);
  result += nums;
  nums = 0;

  dfs(0, 0, true);
  result += nums;

  cout << result;

  return 0;
}