#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int ansT;
int ansCnt = 1;
bool flag = false;

bool inRange(int n) { return 0 <= n && n <= 100000; }
bool isVisited[100001];

int main() {
  freopen("example.txt", "r", stdin);
  int N, K;
  cin >> N >> K;

  q.push({N, 0});

  while (!q.empty()) {
    int n = q.front().first;
    int t = q.front().second;

    q.pop();
    isVisited[n] = true;

    if (n == K) {
      ansT = t;
      break;
    }

    if (inRange(n - 1) && !isVisited[n - 1]) {
      q.push({n - 1, t + 1});
    }
    if (inRange(n + 1) && !isVisited[n + 1]) {
      q.push({n + 1, t + 1});
    }
    if (inRange(n * 2) && !isVisited[n * 2]) {
      q.push({n * 2, t + 1});
    }
  }

  while (!q.empty()) {
    int n = q.front().first;
    int t = q.front().second;
    q.pop();

    if (t > ansT) break;

    if (n == K) ansCnt++;
  }

  cout << ansT << '\n' << ansCnt;

  return 0;
}