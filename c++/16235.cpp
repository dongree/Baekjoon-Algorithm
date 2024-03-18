#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 현재 땅 양분 정보
int board[11][11];
// 겨울마다 추가되는 양분 정보
int A[11][11];
// 나무 위치에 따른 나이 정보
vector<int> trees[11][11];

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M, K;
  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
      board[i][j] = 5;
    }
  }

  while (M--) {
    int x, y, z;
    cin >> x >> y >> z;
    trees[x][y].push_back(z);
  }

  while (K--) {
    // 봄
    // 나무 자신의 나이만큼 양분 먹고, 나이 증가 | 여러 개 나무가 있는 경우 나이
    // 어린 나무 부터 양분 꿀꺽, 양분이 부족하면 죽음

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        vector<int> deadTrees;

        int n = trees[i][j].size();
        if (n == 0) continue;
        sort(trees[i][j].begin(), trees[i][j].end());
        int deadNum = 0;
        for (int k = 0; k < n; k++) {
          if (trees[i][j][k] <= board[i][j]) {
            board[i][j] -= trees[i][j][k];
            trees[i][j][k]++;
          } else {
            deadNum = n - k;
            break;
          }
        }
        if (deadNum == 0) continue;
        while (deadNum--) {
          deadTrees.push_back(trees[i][j].back());
          trees[i][j].pop_back();
        }

        // 여름
        // 죽은 나무가 양분으로 변함 - 죽은 나무 나이를 2로 나눈 값이 그 칸에
        // 양분으로 추가
        for (int k = 0; k < deadTrees.size(); k++) {
          board[i][j] += deadTrees[k] / 2;
        }
      }
    }

    int temp[11][11] = {0};
    // 가을
    // 나무 번식 - 나무의 나이가 5의 배수이면 주변 8칸에 나이가 1인 나무 생김
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        int n = trees[i][j].size();
        if (n == 0) continue;
        for (int k = 0; k < n; k++) {
          if (trees[i][j][k] % 5 == 0) {
            for (int l = 0; l < 8; l++) {
              int nx = dx[l] + i;
              int ny = dy[l] + j;
              if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                trees[nx][ny].push_back(1);
              }
            }
          }
        }
      }
    }

    // 겨울
    // 땅을 돌아다니며 양분 추가
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        board[i][j] += A[i][j];
      }
    }
  }

  int result = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      result += trees[i][j].size();
    }
  }

  cout << result;

  return 0;
}