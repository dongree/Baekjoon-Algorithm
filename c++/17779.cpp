#include <algorithm>
#include <iostream>

using namespace std;

int A[21][21];
int N;
int allPeopleNum = 0;
int minDiff = 1e9;

bool check(int x, int y, int d1, int d2) {
  int x0 = x, y0 = y;
  int x1 = x + d1, y1 = y - d1;
  int x2 = x + d1 + d2, y2 = y - d1 + d2;
  int x3 = x + d2, y3 = y + d2;

  if (x1 > N || y1 < 1) return false;
  if (x2 > N || y2 > N) return false;
  if (x3 > N || y3 > N) return false;
  if (x3 > N || y3 < 1)
    return false;
  else
    return true;
}

void splitLine(int x, int y, int d1, int d2) {
  int arr[21][21] = {0};
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      arr[i][j] = 0;
    }
  }

  for (int i = 0; i <= d1; i++) {
    arr[x + i][y - i] = 5;
    arr[x + d2 + i][y + d2 - i] = 5;
  }

  for (int i = 0; i <= d2; i++) {
    arr[x + i][y + i] = 5;
    arr[x + d1 + i][y - d1 + i] = 5;
  }

  for (int i = x + 1; i <= x + d1 + d2 - 1; i++) {
    bool flag = false;
    for (int j = 0; j <= N; j++) {
      if (flag) {
        if (arr[i][j] == 0)
          arr[i][j] = 5;
        else if (arr[i][j] == 5)
          break;
      } else if (!flag && arr[i][j] == 5)
        flag = true;
    }
  }

  int num[5] = {0};

  // 1번 선거구 만들기
  for (int i = 1; i < x + d1; i++) {
    for (int j = 1; j <= y; j++) {
      if (arr[i][j] == 5) break;
      num[0] += A[i][j];
      arr[i][j] = 1;
    }
  }

  // 2번 선거구 만들기
  for (int i = 1; i <= x + d2; i++) {
    for (int j = y + 1; j <= N; j++) {
      if (arr[i][j] == 5) continue;
      num[1] += A[i][j];
      arr[i][j] = 2;
    }
  }

  // 3번 선거구 만들기
  for (int i = x + d1; i <= N; i++) {
    for (int j = 1; j < y - d1 + d2; j++) {
      if (arr[i][j] == 5) break;
      num[2] += A[i][j];
      arr[i][j] = 3;
    }
  }

  // 4번 선거구 만들기
  for (int i = x + d2 + 1; i <= N; i++) {
    for (int j = y - d1 + d2; j <= N; j++) {
      if (arr[i][j] == 5) continue;
      num[3] += A[i][j];
      arr[i][j] = 4;
    }
  }

  num[4] = allPeopleNum - num[0] - num[1] - num[2] - num[3];

  sort(num, num + 5);

  if ((num[4] - num[0]) < minDiff) {
    minDiff = num[4] - num[0];
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
      allPeopleNum += A[i][j];
    }
  }

  for (int d1 = 1; d1 <= N; d1++) {
    for (int d2 = 1; d2 <= N; d2++) {
      for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
          if (!check(x, y, d1, d2)) continue;
          splitLine(x, y, d1, d2);
        }
      }
    }
  }

  cout << minDiff;

  return 0;
}