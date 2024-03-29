// 1시간 20분 소요

#include <iostream>

using namespace std;

int N, M, T;
int circles[51][51];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= M; };

void rotate(int n, int d, int k) {
  if (d == 0) {
    while ((k--)) {
      int temp = circles[n][M];
      for (int i = M; i > 1; i--) {
        circles[n][i] = circles[n][i - 1];
      }
      circles[n][1] = temp;
    }
  } else {
    while ((k--)) {
      int temp = circles[n][1];
      for (int i = 0; i < M; i++) {
        circles[n][i] = circles[n][i + 1];
      }
      circles[n][M] = temp;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> T;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> circles[i][j];
    }
  }

  while (T--) {
    int x, d, k;
    cin >> x >> d >> k;

    // x 배수 원판 d방향으로 k칸 회전
    for (int i = x; i <= N; i += x) {
      rotate(i, d, k);
    }

    bool remainNumber = false;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (circles[i][j] > 0) {
          remainNumber = true;
          break;
        }
      }
      if (remainNumber) break;
    }

    if (remainNumber) {
      int temp[51][51] = {false};

      bool isAdj = false;
      double cnt = 0;
      double sum = 0;

      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
          if (circles[i][j] == 0) continue;
          bool isSubAdj = false;
          cnt++;
          sum += circles[i][j];
          for (int k = 0; k < 4; k++) {
            int ny = i + dy[k];
            int nx = (j + dx[k] - 1) % M + 1;
            if (inRange(ny, nx) && circles[i][j] == circles[ny][nx]) {
              isAdj = true;
              isSubAdj = true;
              temp[ny][nx] = true;
            }
          }
          if (isSubAdj) temp[i][j] = true;
        }
      }

      if (isAdj) {
        for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
            if (temp[i][j]) circles[i][j] = 0;
          }
        }
      } else {
        double mean = sum / cnt;
        for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= M; j++) {
            if (circles[i][j] == 0) continue;
            if (circles[i][j] > mean)
              circles[i][j]--;
            else if (circles[i][j] < mean)
              circles[i][j]++;
          }
        }
      }
    }
  }

  int answer = 0;
  // 원판에 적힌 수의 합 출력
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      answer += circles[i][j];
    }
  }
  cout << answer;

  return 0;
}
