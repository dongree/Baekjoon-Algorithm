#include <cmath>
#include <iostream>

using namespace std;

int N, M;
bool crushed[10];
int answer;

void dfs(int length, int cnt, int sum) {
  if (length == cnt) {
    answer = min(answer, abs(N - sum) + cnt);
    return;
  }

  for (int i = 0; i <= 9; i++) {
    if (!crushed[i]) {
      dfs(length, cnt + 1, sum + pow(10, cnt) * i);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  answer = abs(100 - N);

  if (M != 0) {
    for (int i = 0; i < M; i++) {
      int a;
      cin >> a;
      crushed[a] = true;
    }
  }

  for (int i = 1; i <= 6; i++) {
    dfs(i, 0, 0);
  }
  cout << answer;

  return 0;
}