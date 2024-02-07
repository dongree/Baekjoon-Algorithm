#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;

bool isVisited[1000001];

int bfs() {
  queue<pair<int, int>> q;
  q.push({S, 0});
  isVisited[S] = true;

  while (!q.empty()) {
    int num = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (num == G) return cnt;

    int next1 = num + U;
    if (1 <= next1 && next1 <= F && !isVisited[next1]) {
      isVisited[next1] = true;
      q.push({next1, cnt + 1});
    }

    int next2 = num - D;
    if (1 <= next2 && next2 <= F && !isVisited[next2]) {
      isVisited[next2] = true;
      q.push({next2, cnt + 1});
    }
  }

  return -1;
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> F >> S >> G >> U >> D;

  int answer = bfs();
  if (answer == -1)
    cout << "use the stairs";
  else
    cout << answer;

  return 0;
}