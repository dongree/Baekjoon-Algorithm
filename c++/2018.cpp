#include <iostream>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  int start = 1;
  int end = 1;
  int sum = 1;
  int cnt = 0;

  while (end <= N && start <= end) {
    if (sum <= N) {
      if (sum == N) cnt++;
      sum += ++end;
    } else {
      sum -= start++;
    }
  }

  cout << cnt;

  return 0;
}