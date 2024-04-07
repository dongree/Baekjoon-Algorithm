#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool inRange(int x) { return 0 <= x && x <= 100000; }

int main() {
  freopen("example.txt", "r", stdin);
  int N, K;
  cin >> N >> K;

  int temp[100001];
  for (int i = 0; i <= 100000; i++) {
    temp[i] = -1;
  }

  queue<pair<int, int>> q;
  q.push({N, 0});

  while (!q.empty()) {
    int x = q.front().first;
    int cnt = q.front().second;

    if (x == K) {
      cout << cnt << '\n';
      break;
    }

    q.pop();

    if (inRange(x - 1) && temp[x - 1] == -1) {
      q.push({x - 1, cnt + 1});
      temp[x - 1] = x;
    }

    if (inRange(x + 1) && temp[x + 1] == -1) {
      q.push({x + 1, cnt + 1});
      temp[x + 1] = x;
    }

    if (inRange(2 * x) && temp[2 * x] == -1) {
      q.push({2 * x, cnt + 1});
      temp[2 * x] = x;
    }
  }

  vector<int> v;
  v.push_back(K);

  int c = K;
  while (!(c == N)) {
    c = temp[c];
    v.push_back(c);
  }

  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << ' ';
  }

  return 0;
}