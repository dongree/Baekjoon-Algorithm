#include <iostream>
#include <vector>

using namespace std;

vector<int> difficulty;
int ps[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int d;
    cin >> d;
    difficulty.push_back(d);
  };

  for (int i = 0; i < N - 1; i++) {
    if (difficulty[i] > difficulty[i + 1]) {
      ps[i + 1] = 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    ps[i] += ps[i - 1];
  }

  int Q;
  cin >> Q;

  while (Q--) {
    int x, y;
    cin >> x >> y;
    cout << ps[y - 1] - ps[x - 1] << '\n';
  }

  return 0;
}