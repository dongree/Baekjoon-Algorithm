#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
bool isVisited[100001];

bool check(int n) {
  if (!(0 <= n && n <= 100000)) return false;
  if (isVisited[n]) return false;
  return true;
}

int main() {
  freopen("example.txt", "r", stdin);
  int N, K;
  cin >> N >> K;

  q.push({N, 0});
  isVisited[N] = true;

  while (!q.empty()) {
    int n = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if (n == K) {
      cout << cnt;
      return 0;
    }

    if (check(2 * n)) {
      isVisited[2 * n] = true;
      q.push({2 * n, cnt + 1});
    }

    if (check(n + 1)) {
      isVisited[n + 1] = true;
      q.push({n + 1, cnt + 1});
    }

    if (check(n - 1)) {
      isVisited[n - 1] = true;
      q.push({n - 1, cnt + 1});
    }
  }

  return 0;
}