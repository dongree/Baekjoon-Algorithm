#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, k;
string w;

int main() {
  freopen("example.txt", "r", stdin);

  cin >> t;

  for (int t_case = 0; t_case < t; t_case++) {
    vector<int> arr[26];

    cin >> w >> k;

    for (int i = 0; i < w.size(); i++) {
      arr[w[i] - 'a'].push_back(i);
    }

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    for (int i = 0; i < 26; i++) {
      if (arr[i].size() < k) continue;

      for (int j = 0; j < arr[i].size() - k + 1; j++) {
        minValue = min(minValue, arr[i][j + k - 1] - arr[i][j] + 1);
        maxValue = max(maxValue, arr[i][j + k - 1] - arr[i][j] + 1);
      }
    }
    if (minValue == INT_MAX)
      cout << -1;
    else
      cout << minValue << ' ' << maxValue;
    cout << '\n';
  }

  return 0;
}