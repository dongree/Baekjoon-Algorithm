#include <iostream>

using namespace std;

int N, M;
int answer;
int arr[300][300];
int melting[300][300];
bool isVisited[300][300];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      melting[i][j] = 0;
      isVisited[i][j] = false;
    }
  }
}

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

void dfs(int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (inRange(ny, nx) && arr[ny][nx] != 0 && !isVisited[ny][nx]) {
      isVisited[ny][nx] = true;
      dfs(ny, nx);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  while (true) {
    init();
    answer++;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (arr[i][j] != 0) {
          int cnt = 0;
          for (int d = 0; d < 4; d++) {
            int ny = i + dy[d];
            int nx = j + dx[d];
            if (arr[ny][nx] == 0) cnt++;
          }
          melting[i][j] = cnt;
        }
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (arr[i][j] != 0) {
          arr[i][j] =
              (arr[i][j] - melting[i][j] < 0) ? 0 : arr[i][j] - melting[i][j];
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (arr[i][j] != 0 && !isVisited[i][j]) {
          dfs(i, j);
          cnt++;
        }
      }
    }

    if (cnt >= 2)
      break;
    else if (cnt == 0) {
      answer = 0;
      break;
    }
  }

  cout << answer;

  return 0;
}