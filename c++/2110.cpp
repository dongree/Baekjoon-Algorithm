#include <algorithm>
#include <iostream>

using namespace std;

int loc[200000];

int main() {
  int N, C;
  cin >> N >> C;

  for (int i = 0; i < N; i++) {
    cin >> loc[i];
  }

  sort(loc, loc + N);

  int start = 1;
  int end = loc[N - 1] - loc[0];

  while (start <= end) {
    int mid = (start + end) / 2;

    int cnt = 1;
    int prev = loc[0];
    for (int i = 1; i < N; i++) {
      if (loc[i] - prev < mid) continue;
      cnt++;
      prev = loc[i];
    }

    if (cnt < C)
      end = mid - 1;
    else
      start = mid + 1;
  }

  cout << end;

  return 0;
}