#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> pizza1;
vector<int> pizza2;
vector<int> sum1;
vector<int> sum2;

int main() {
  freopen("example.txt", "r", stdin);

  int target;
  cin >> target;

  int m, n;
  cin >> m >> n;

  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    pizza1.push_back(a);
  }

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    pizza2.push_back(a);
  }

  sum1.push_back(0);
  for (int i = 0; i < m; i++) {
    int k = 0;
    for (int j = i; j < i + m - 1; j++) {
      k += pizza1[j % m];
      sum1.push_back(k);
    }
  }
  int k = 0;
  for (int i = 0; i < m; i++) {
    k += pizza1[i];
  }
  sum1.push_back(k);

  sum2.push_back(0);
  for (int i = 0; i < n; i++) {
    int k = 0;
    for (int j = i; j < i + n - 1; j++) {
      k += pizza2[j % n];
      sum2.push_back(k);
    }
  }
  k = 0;
  for (int i = 0; i < n; i++) {
    k += pizza2[i];
  }
  sum2.push_back(k);

  sort(sum1.begin(), sum1.end());
  sort(sum2.begin(), sum2.end());

  int ans = 0;

  for (int i = 0; i < sum1.size(); i++) {
    int value = target - sum1[i];
    if (value < 0) break;

    int low = lower_bound(sum2.begin(), sum2.end(), value) - sum2.begin();
    int high = upper_bound(sum2.begin(), sum2.end(), value) - sum2.begin();
    ans += high - low;
  }

  cout << ans;

  return 0;
}