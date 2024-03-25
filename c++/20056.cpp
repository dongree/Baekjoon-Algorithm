// 1시간 14분 소요

#include <iostream>
#include <vector>

using namespace std;

struct fireball {
  int m, s, d;
};
struct info {
  int y, x, m, s, d;
};

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M, K;
vector<fireball> board[51][51];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;

  while (M--) {
    int r, c, m, d, s;
    cin >> r >> c >> m >> s >> d;
    board[r][c].push_back({m, s, d});
  }

  // 이동 명령
  while (K--) {
    // 1. 모든 파이어볼, 자신의 방향 d로 속력 s만큼 이동
    vector<info> temp;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (board[i][j].size() == 0) continue;

        for (int k = 0; k < board[i][j].size(); k++) {
          int m = board[i][j][k].m;
          int s = board[i][j][k].s;
          int d = board[i][j][k].d;

          int y = i + dy[d] * (s % N);
          if (y < 1) y += N;
          if (y > N) y %= N;
          int x = j + dx[d] * (s % N);
          if (x < 1) x += N;
          if (x > N) x %= N;
          temp.push_back({y, x, m, s, d});
        }
        while (!board[i][j].empty()) {
          board[i][j].pop_back();
        }
      }
    }
    for (int i = 0; i < temp.size(); i++) {
      int y = temp[i].y;
      int x = temp[i].x;
      int m = temp[i].m;
      int s = temp[i].s;
      int d = temp[i].d;

      board[y][x].push_back({m, s, d});
    }

    // 2. 2개 이상의 파이어볼이 있는 경우 처리하기
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (board[i][j].size() < 2) continue;

        int n = board[i][j].size();
        int newM = 0;
        int newS = 0;
        bool flag = true;
        int tmp = (board[i][j][0].d) % 2;
        for (int k = 0; k < n; k++) {
          newM += board[i][j][k].m;
          newS += board[i][j][k].s;
          if (board[i][j][k].d % 2 != tmp) flag = false;
        }
        newM /= 5;
        newS /= n;

        while (!board[i][j].empty()) {
          board[i][j].pop_back();
        }
        if (newM == 0) continue;

        for (int dir = 0; dir < 8; dir++) {
          if (flag && dir % 2 == 0)
            board[i][j].push_back({newM, newS, dir});
          else if (!flag && dir % 2 == 1)
            board[i][j].push_back({newM, newS, dir});
        }
      }
    }
  }

  // 남아있는 파이어볼 질량 합 구하기

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j].size() != 0) {
        for (int k = 0; k < board[i][j].size(); k++) {
          answer += board[i][j][k].m;
        }
      }
    }
  }
  cout << answer;

  return 0;
}