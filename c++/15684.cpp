#include <iostream>
#define INF 1000000

using namespace std;

int N, M, H;

int sadari[31][11];
int answer = INF;

bool isGoal() {
  for (int i = 1; i <= N; i++) {
    int loc = i;
    for (int j = 1; j <= H; j++) {
      if (sadari[j][loc] == 1) {
        loc += 1;
      } else if (sadari[j][loc] == -1) {
        loc -= 1;
      }
    }
    if (i != loc) return false;
  }
  return true;
}

void installSadari(int y, int x, int cnt) {
  if (cnt > 3) return;

  if (cnt < answer && isGoal()) {
    answer = cnt;
    return;
  }

  for (int i = y; i <= H; i++) {
    for (int j = 1; j < N; j++) {
      if (i == y && j <= x) continue;
      if (sadari[i][j] == 0 && sadari[i][j + 1] == 0) {
        sadari[i][j] = 1;
        sadari[i][j + 1] = -1;
        installSadari(i, j, cnt + 1);
        sadari[i][j] = 0;
        sadari[i][j + 1] = 0;
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> H;

  while (M--) {
    int a, b;
    cin >> a >> b;
    sadari[a][b] = 1;
    sadari[a][b + 1] = -1;
  }

  installSadari(1, 0, 0);

  if (answer == INF)
    cout << -1;
  else
    cout << answer;

  return 0;
}