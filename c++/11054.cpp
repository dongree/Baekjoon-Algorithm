#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int dp1[1001];
int dp2[1001];

int main() {
  freopen("example.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }

  for (int i = 0; i < n; i++) {
    int max1 = 0;
    int max2 = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i] && dp1[j] > max1) max1 = dp1[j];
      if (arr[n - j - 1] < arr[n - i - 1] && dp2[j] > max2) max2 = dp2[j];
    }
    dp1[i] = max1 + 1;
    dp2[i] = max2 + 1;
  }

  int answer = 0;
  for (int i = 0; i < n; i++) {
    answer = max(answer, dp1[i] + dp2[n - i - 1] - 1);
  }
  cout << answer;

  return 0;
}