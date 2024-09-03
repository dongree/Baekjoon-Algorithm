#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> points;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    points.push_back(p);
  }

  sort(points.begin(), points.end());

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    cout << upper_bound(points.begin(), points.end(), b) -
                lower_bound(points.begin(), points.end(), a)
         << '\n';
  }

  return 0;
}