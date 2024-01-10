#include <iostream>

using namespace std;

int n, x;
int arr[250001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("example.txt", "r", stdin);

  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int visitedNum = 0;
  for (int i = 0; i < x; i++) {
    visitedNum += arr[i];
  }
  int maxVisitedNum = visitedNum;
  int cnt = 1;

  for (int i = 0; i < n - x; i++) {
    visitedNum -= arr[i];
    visitedNum += arr[i + x];
    if (visitedNum > maxVisitedNum) {
      maxVisitedNum = visitedNum;
      cnt = 1;
    } else if (visitedNum == maxVisitedNum)
      cnt++;
  }

  if (maxVisitedNum == 0)
    cout << "SAD";
  else
    cout << maxVisitedNum << '\n' << cnt;
  cout << '\n';

  return 0;
}