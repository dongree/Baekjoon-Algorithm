#include <deque>
#include <iostream>

using namespace std;

deque<int> dq;
int ans;

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    dq.push_back(i);
  }

  while (M--) {
    int a;
    cin >> a;

    int idx;
    for (int i = 0; i < dq.size(); i++) {
      if (dq[i] == a) {
        idx = i;
        break;
      }
    }

    int cri = dq.size() / 2;
    if (idx <= cri) {
      while (dq[0] != a) {
        int k = dq.front();
        dq.pop_front();
        dq.push_back(k);
        ans++;
      }
    } else {
      while (dq[0] != a) {
        int k = dq.back();
        dq.pop_back();
        dq.push_front(k);
        ans++;
      }
    }

    dq.pop_front();
  }

  cout << ans;

  return 0;
}