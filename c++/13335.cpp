#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;
int ans, idx, currW;

int main() {
  freopen("example.txt", "r", stdin);

  int n, w, L;
  cin >> n >> L >> w;

  vector<int> truckWeights;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    truckWeights.push_back(a);
  }

  while (1) {
    if (idx == n) {
      ans += L;
      break;
    }

    ans++;

    if (q.size() == L) {
      currW -= q.front();
      q.pop();
    }

    int tw = truckWeights[idx];
    if (currW + tw <= w) {
      currW += tw;
      q.push(tw);
      idx++;
    } else {
      q.push(0);
    }
  }
  cout << ans;

  return 0;
}