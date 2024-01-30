#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

bool isDotted[MAX][MAX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int x, y, d, g;
int cnt;
vector<int> direction;

void makeDragonCurve() {
  int size = direction.size();
  for (int i = size - 1; i >= 0; i--) {
    int nd = (direction[i] + 1) % 4;
    y += dy[nd];
    x += dx[nd];
    isDotted[y][x] = true;
    direction.push_back(nd);
  }
}

void countSquare() {
  for (int i = 0; i < MAX - 1; i++) {
    for (int j = 0; j < MAX - 1; j++) {
      if (isDotted[i][j] && isDotted[i + 1][j] && isDotted[i][j + 1] &&
          isDotted[i + 1][j + 1])
        cnt++;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  while (N--) {
    direction.clear();
    cin >> x >> y >> d >> g;

    isDotted[y][x] = true;

    // 0 generation
    y += dy[d];
    x += dx[d];

    isDotted[y][x] = true;
    direction.push_back(d);

    while (g--) {
      makeDragonCurve();
    }
  }

  countSquare();

  cout << cnt;

  return 0;
}