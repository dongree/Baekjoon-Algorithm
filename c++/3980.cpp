#include <iostream>

using namespace std;

int arr[11][11];
bool isVisited[11];
int result;

void dfs(int idx, int score) {
  if (idx == 11) {
    if (result < score) result = score;
    return;
  }

  for (int i = 0; i < 11; i++) {
    if (arr[idx][i] == 0 || isVisited[i]) continue;
    isVisited[i] = true;
    dfs(idx + 1, score + arr[idx][i]);
    isVisited[i] = false;
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int T;
  cin >> T;

  while (T--) {
    result = 0;
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j < 11; j++) {
        cin >> arr[i][j];
      }
    }

    dfs(0, 0);
    cout << result << '\n';
  }
  return 0;
}
