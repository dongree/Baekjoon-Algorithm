// 1:00 start

#include <iostream>

using namespace std;

int A[51][51];
int cloud[51][51];
int temp[51][51];
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int N, M;

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }

void bibaragi() {
  cloud[N][1] = 1;
  cloud[N][2] = 1;
  cloud[N - 1][1] = 1;
  cloud[N - 1][2] = 1;
}

void moveCloud(int d, int s) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int ny = i + s * dy[d];
      int nx = j + s * dx[d];
      if (ny < 1)
        ny += N;
      else if (ny > N)
        ny = (ny - 1) % N + 1;
      if (nx < 1)
        nx += N;
      else if (nx > N)
        nx = (nx - 1) % N + 1;
      temp[ny][nx] = cloud[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cloud[i][j] = temp[i][j];
    }
  }
}

void dropRain() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (cloud[i][j] == 1) {
        A[i][j] += 1;
      }
    }
  }
}

void byeCloud() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (cloud[i][j] == 1) {
        cloud[i][j] = -1;
      }
    }
  }
}

void waterCopyMagic() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (cloud[i][j] == -1) {
        int cnt = 0;
        for (int d = 2; d <= 8; d += 2) {
          int ny = i + dy[d];
          int nx = j + dx[d];
          if (inRange(ny, nx) && A[ny][nx] > 0) cnt++;
        }
        A[i][j] += cnt;
      }
    }
  }
}

void createCloud() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (cloud[i][j] == -1) {
        cloud[i][j] = 0;
        continue;
      }

      if (A[i][j] >= 2) {
        cloud[i][j] = 1;
        A[i][j] -= 2;
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }

  bibaragi();

  while (M--) {
    int d, s;
    cin >> d >> s;

    moveCloud(d, s % N);
    dropRain();
    byeCloud();
    waterCopyMagic();
    createCloud();
  }

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      answer += A[i][j];
    }
  }

  cout << answer;

  return 0;
}