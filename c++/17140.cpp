#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  int r, c, k;
  cin >> r >> c >> k;

  int row = 3;
  int col = 3;

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> arr[i][j];
    }
  }

  int t = 0;

  while (t <= 100) {
    if (arr[r][c] == k) {
      cout << t;
      return 0;
    }

    if (row >= col) {
      for (int i = 1; i <= row; i++) {
        int temp[101] = {0};
        vector<pair<int, int>> v;
        int maxNum = 0;
        for (int j = 1; j <= col; j++) {
          int num = arr[i][j];
          temp[num]++;
        }
        for (int j = 1; j <= 100; j++) {
          if (temp[j] != 0) {
            v.push_back({j, temp[j]});
          }
        }
        sort(v.begin(), v.end(), compare);
        for (int j = 1; j <= col; j++) arr[i][j] = 0;
        if (v.size() * 2 > col) col = v.size() * 2;
        int idx = 1;
        for (int j = 0; j < v.size(); j++) {
          arr[i][idx++] = v[j].first;
          arr[i][idx++] = v[j].second;
        }
      }
    } else {
      for (int i = 1; i <= col; i++) {
        int temp[101] = {0};
        vector<pair<int, int>> v;
        int maxNum = 0;
        for (int j = 1; j <= row; j++) {
          int num = arr[j][i];
          temp[num]++;
        }
        for (int j = 1; j <= 100; j++) {
          if (temp[j] != 0) {
            v.push_back({j, temp[j]});
          }
        }
        sort(v.begin(), v.end(), compare);
        for (int j = 1; j <= row; j++) arr[j][i] = 0;
        if (v.size() * 2 > row) row = v.size() * 2;
        int idx = 1;
        for (int j = 0; j < v.size(); j++) {
          arr[idx++][i] = v[j].first;
          arr[idx++][i] = v[j].second;
        }
      }
    }
    t++;
  }

  cout << -1;

  return 0;
}