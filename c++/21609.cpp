#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 20

using namespace std;

struct BlockGroup {
  int size, rainbowCnt, criY, criX;
};

int N, M;
int board[MAX][MAX];
bool isVisited[MAX][MAX];
int temp[MAX][MAX];
vector<BlockGroup> groups;
int score;
queue<pair<int, int>> q;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool compare(BlockGroup A, BlockGroup B) {
  if (A.size == B.size) {
    if (A.rainbowCnt == B.rainbowCnt) {
      if (A.criY == B.criY) {
        return A.criX > B.criX;
      }
      return A.criY > B.criY;
    }
    return A.rainbowCnt > B.rainbowCnt;
  }
  return A.size > B.size;
}

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

bool searchBlockGroup() {
  groups.clear();
  memset(isVisited, false, sizeof(isVisited));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] >= 1 && !isVisited[i][j]) {
        q.push({i, j});
        isVisited[i][j] = true;
        int num = board[i][j];
        int size = 1;
        int criY = i;
        int criX = j;
        vector<pair<int, int>> rainbow;

        while (!q.empty()) {
          int y = q.front().first;
          int x = q.front().second;
          q.pop();

          for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (inRange(ny, nx) && !isVisited[ny][nx] &&
                (board[ny][nx] == num || board[ny][nx] == 0)) {
              if (board[ny][nx] == 0) {
                rainbow.push_back({ny, nx});
              } else {
                if (ny < criY || (ny == criY && nx < criX)) {
                  criY = ny;
                  criX = nx;
                }
              }
              q.push({ny, nx});
              isVisited[ny][nx] = true;
              size++;
            }
          }
        }
        int rainbowCnt = rainbow.size();

        if (size >= 2) groups.push_back({size, rainbowCnt, criY, criX});

        for (int i = 0; i < rainbow.size(); i++) {
          int y = rainbow[i].first;
          int x = rainbow[i].second;
          isVisited[y][x] = false;
        }
      }
    }
  }

  sort(groups.begin(), groups.end(), compare);

  if (groups.size() == 0) return false;

  return true;
}

void deleteBlocks() {
  memset(isVisited, false, sizeof(isVisited));

  BlockGroup group = groups[0];
  score += (group.size * group.size);
  int cy = group.criY;
  int cx = group.criX;
  q.push({cy, cx});
  isVisited[cy][cx] = true;
  int num = board[cy][cx];
  board[cy][cx] = -2;  // -2 : 없는 블록

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];

      if (inRange(ny, nx) && !isVisited[ny][nx] &&
          (board[ny][nx] == num || board[ny][nx] == 0)) {
        q.push({ny, nx});
        board[ny][nx] = -2;
        isVisited[ny][nx] = true;
      }
    }
  }
}

void gravity() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      temp[i][j] = -2;
    }
  }

  vector<int> v;
  int sIdx;

  for (int i = 0; i < N; i++) {
    sIdx = N - 1;
    for (int j = N - 1; j >= 0; j--) {
      if (board[j][i] == -2) continue;

      if (board[j][i] == -1) {
        for (int k = 0; k < v.size(); k++) {
          temp[sIdx - k][i] = v[k];
        }

        temp[j][i] = -1;
        sIdx = j - 1;
        v.clear();
        continue;
      }

      v.push_back(board[j][i]);
    }
    for (int k = 0; k < v.size(); k++) {
      temp[sIdx - k][i] = v[k];
    }
    v.clear();
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = temp[i][j];
    }
  }
}

void rotate() {
  memset(temp, 0, sizeof(temp));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      temp[i][j] = board[j][N - i - 1];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = temp[i][j];
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  while (true) {
    if (!searchBlockGroup()) break;
    deleteBlocks();
    gravity();
    rotate();
    gravity();
  }

  cout << score;

  return 0;
}