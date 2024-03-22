#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  int answer = 1e9;

  for (int i = 1; i < (1 << N); i++) {
    int s = 1;
    int b = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        s *= v[j].first;
        b += v[j].second;
      }
    }
    answer = min(answer, abs(s - b));
  }

  cout << answer;

  return 0;
}