#include <iostream>
#include <queue>

using namespace std;

long long A, B;

long long bfs() {
  queue<pair<long long, long long>> q;
  q.push({1, A});

  while (!q.empty()) {
    long long cnt = q.front().first;
    long long value = q.front().second;
    q.pop();

    if (value == B) {
      return cnt;
    }

    if (value * 2 <= B) {
      q.push({cnt + 1, value * 2});
    }
    if (value * 10 + 1 <= B) {
      q.push({cnt + 1, value * 10 + 1});
    }
  }

  return -1;
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> A >> B;

  cout << bfs();

  return 0;
}