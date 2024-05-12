#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  while (true) {
    int a;
    cin >> a;

    if (a > 0) {
      if (q.size() < N) q.push(a);
    } else if (a == 0) {
      q.pop();
    } else if (a == -1) {
      if (q.size() == 0)
        cout << "empty";
      else {
        while (!q.empty()) {
          cout << q.front() << ' ';
          q.pop();
        }
      }
      break;
    }
  }

  return 0;
}