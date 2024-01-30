#include <algorithm>
#include <iostream>

using namespace std;

int pay[100000];

int main() {
  freopen("example.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  long long currProfit = 0;

  for (int i = 0; i < n; i++) {
    cin >> pay[i];
    if (i < m) currProfit += pay[i];
  }

  long long answer = currProfit;

  for (int i = 0; i < n - m; i++) {
    currProfit -= pay[i];
    currProfit += pay[i + m];
    answer = max(answer, currProfit);
  }

  cout << answer;

  return 0;
}