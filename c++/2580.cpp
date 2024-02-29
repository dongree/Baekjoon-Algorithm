#include <iostream>

using namespace std;

int sudoku[9][9];
int row[9][10];
int col[9][10];
int box[9][10];
bool endFlag = false;

void dfs(int cnt) {
  int y = cnt / 9;
  int x = cnt % 9;

  if (endFlag) return;

  if (cnt == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << sudoku[i][j] << ' ';
      }
      cout << '\n';
    }
    endFlag = true;
    return;
  }

  if (sudoku[y][x] == 0) {
    for (int k = 1; k <= 9; k++) {
      int boxLoc = y / 3 * 3 + x / 3;
      if (!row[y][k] && !col[x][k] && !box[boxLoc][k]) {
        sudoku[y][x] = k;
        row[y][k] = true;
        col[x][k] = true;
        box[boxLoc][k] = true;
        dfs(cnt + 1);
        sudoku[y][x] = 0;
        row[y][k] = false;
        col[x][k] = false;
        box[boxLoc][k] = false;
      }
    }
  } else {
    dfs(cnt + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int num;
      cin >> num;
      sudoku[i][j] = num;
      row[i][num] = true;
      col[j][num] = true;
      box[i / 3 * 3 + j / 3][num] = true;
    }
  }

  dfs(0);

  return 0;
}