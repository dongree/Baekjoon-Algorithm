#include <deque>
#include <iostream>

using namespace std;

int arr[1000001];
deque<int> dq;

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = N - 1; i >= 0; i--) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    if (arr[i] == 1) {
      dq.push_front(i + 1);
    } else if (arr[i] == 2) {
      int temp = dq.front();
      dq.pop_front();
      dq.push_front(i + 1);
      dq.push_front(temp);
    } else {
      dq.push_back(i + 1);
    }
  }

  for (int i = 0; i < N; i++) {
    cout << dq[i] << ' ';
  }

  return 0;
}