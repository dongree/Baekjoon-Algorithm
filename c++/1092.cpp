#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> crains;
vector<int> boxes;

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    crains.push_back(a);
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    boxes.push_back(a);
  }

  sort(crains.begin(), crains.end(), greater<int>());
  sort(boxes.begin(), boxes.end(), greater<int>());

  if (crains[0] < boxes[0]) {
    cout << -1;
    return 0;
  }

  int t = 0;

  while (boxes.size()) {
    int cIdx = 0;
    int bIdx = 0;
    while (cIdx < crains.size() && bIdx < boxes.size()) {
      if (boxes[bIdx] <= crains[cIdx]) {
        boxes.erase(boxes.begin() + bIdx);
        cIdx++;
      } else {
        bIdx++;
      }
    }

    t++;
  }

  cout << t;

  return 0;
}
