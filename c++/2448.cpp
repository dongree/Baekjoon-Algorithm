#include <iostream>

using namespace std;

string tree[3] = {"  *  ", " * * ", "*****"};
char arr[10000][10000];

void star(int y, int x, int n) {
  if (n == 3) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 5; j++) {
        arr[y + i][x + j] = tree[i][j];
      }
    }
    return;
  }

  star(y, x + n / 2, n / 2);
  star(y + n / 2, x, n / 2);
  star(y + n / 2, x + n, n / 2);
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  star(0, 0, N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * N - 1; j++) {
      if (!arr[i][j])
        cout << ' ';
      else
        cout << arr[i][j];
    }
    cout << '\n';
  }

  return 0;
}