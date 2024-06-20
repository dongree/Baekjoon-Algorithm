#include <deque>
#include <iostream>

using namespace std;

deque<pair<int, int>> dq;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    dq.push_back({a, i});
  }

  while (!dq.empty()) {
    int k = dq.front().first;
    int num = dq.front().second;
    cout << num << ' ';

    dq.pop_front();

    if (dq.empty()) break;

    if (k > 0) {
      k -= 1;
      while (k--) {
        pair<int, int> temp = dq.front();
        dq.pop_front();
        dq.push_back(temp);
      }
    } else {
      while (k++) {
        pair<int, int> temp = dq.back();
        dq.pop_back();
        dq.push_front(temp);
      }
    }
  }

  return 0;
}