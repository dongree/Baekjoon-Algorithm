// 내 풀이 - 모든 bfs가 끝나고 난 후 인구 분배
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int N, L, R;
int day = -1;
int A[50][50];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int unionFlag[50][50];
int unionMeanPerContury[2501];
int unionPeopleNum;
int unionNum;
int u = 1;

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      unionFlag[i][j] = 0;
    }
  }
  for (int i = 0; i <= N * N; i++) {
    unionMeanPerContury[i] = 0;
  }
  u = 1;
}

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

void bfs(int y, int x) {
  queue<pair<int, int>> q;

  q.push({y, x});

  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      int d = abs(A[cy][cx] - A[ny][nx]);
      if (unionFlag[ny][nx] == 0 && inRange(ny, nx) && L <= d && d <= R) {
        unionFlag[ny][nx] = u;
        unionPeopleNum += A[ny][nx];
        unionNum++;
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> L >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  while (u <= N * N) {
    init();

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (unionFlag[i][j] == 0) {
          unionPeopleNum = A[i][j];
          unionNum = 1;
          unionFlag[i][j] = u;
          bfs(i, j);
          unionMeanPerContury[u] = unionPeopleNum / unionNum;
          u++;
        }
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        A[i][j] = unionMeanPerContury[unionFlag[i][j]];
      }
    }

    day++;
  }

  cout << day;
  return 0;
}

// 다른 사람 풀이 변형 - bfs 하나가 끝나고 인구분배, q를 2개 사용 -> 시간이 더
// 오래 걸림 #include <cmath> #include <iostream> #include <queue>

// using namespace std;

// int N, L, R;
// int day = -1;
// int A[50][50];
// int dy[4] = {1, 0, -1, 0};
// int dx[4] = {0, 1, 0, -1};
// bool canMove = true;
// bool isVisited[50][50];

// void init() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       isVisited[i][j] = false;
//     }
//   }
// }

// bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

// void bfs(int y, int x) {
//   queue<pair<int, int>> q;
//   queue<pair<int, int>> unionQ;
//   int unionPeopleNum = A[y][x];
//   int unionNum = 1;

//   q.push({y, x});
//   unionQ.push({y, x});

//   while (!q.empty()) {
//     int cy = q.front().first;
//     int cx = q.front().second;
//     q.pop();

//     for (int i = 0; i < 4; i++) {
//       int ny = cy + dy[i];
//       int nx = cx + dx[i];

//       int d = abs(A[cy][cx] - A[ny][nx]);
//       if (!isVisited[ny][nx] && inRange(ny, nx) && L <= d && d <= R) {
//         isVisited[ny][nx] = true;
//         unionPeopleNum += A[ny][nx];
//         unionNum++;
//         canMove = true;
//         q.push({ny, nx});
//         unionQ.push({ny, nx});
//       }
//     }
//   }

//   int unionMean = unionPeopleNum / unionNum;
//   while (!unionQ.empty()) {
//     int qy = unionQ.front().first;
//     int qx = unionQ.front().second;
//     A[qy][qx] = unionMean;
//     unionQ.pop();
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N >> L >> R;

//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       cin >> A[i][j];
//     }
//   }

//   while (canMove) {
//     init();
//     canMove = false;
//     for (int i = 0; i < N; i++) {
//       for (int j = 0; j < N; j++) {
//         if (isVisited[i][j] == 0) {
//           isVisited[i][j] = true;
//           bfs(i, j);
//         }
//       }
//     }
//     day++;
//   }

//   cout << day;
//   return 0;
// }