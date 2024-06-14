#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> p;
int L[100000];
int R[100000];

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    p.push_back({x, y});
  }

  for (int i = 0; i < N - 1; i++) {
    int dist =
        abs(p[i + 1].first - p[i].first) + abs(p[i + 1].second - p[i].second);
    L[i + 1] = L[i] + dist;
  }

  for (int i = N - 1; i > 0; i--) {
    int dist =
        abs(p[i].first - p[i - 1].first) + abs(p[i].second - p[i - 1].second);
    R[i - 1] = R[i] + dist;
  }

  int ans = 1e9;

  for (int i = 1; i < N - 1; i++) {
    int dist = abs(p[i + 1].first - p[i - 1].first) +
               abs(p[i + 1].second - p[i - 1].second);
    int result = L[i - 1] + R[i + 1] + dist;
    if (ans > result) ans = result;
  }

  cout << ans;

  return 0;
}