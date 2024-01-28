#include <cmath>
#include <iostream>

using namespace std;

int N, L;
int map[100][100];
bool isVisited[100];
int answer;

void initIsVisited() {
  for (int i = 0; i < N; i++) {
    isVisited[i] = false;
  }
}

// dir | 0:가로 1:세로
bool checkRoad(int n, int dir) {
  initIsVisited();
  int prev = dir ? map[0][n] : map[n][0];
  for (int i = 1; i < N; i++) {
    int curr = dir ? map[i][n] : map[n][i];
    if (prev == curr) {
      prev = curr;
      continue;
    } else {
      if (abs(curr - prev) > 1) return false;
      if (prev < curr) {
        if (i - L < 0) return false;
        for (int j = i - L; j < i; j++) {
          if ((dir ? map[j][n] : map[n][j]) != prev || isVisited[j])
            return false;
          else
            isVisited[j] = true;
        }
      } else {
        if (i + L > N) return false;
        for (int j = i; j < i + L; j++) {
          if ((dir ? map[j][n] : map[n][j]) != curr || isVisited[j])
            return false;
          else
            isVisited[j] = true;
        }
      }
    }
    prev = curr;
  }
  return true;
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N >> L;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    if (checkRoad(i, 0)) answer++;
    if (checkRoad(i, 1)) answer++;
  }

  cout << answer;

  return 0;
}