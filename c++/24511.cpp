#include <deque>
#include <iostream>

using namespace std;

int flag[100000];
deque<int> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> flag[i];
  }
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (flag[i] == 0) dq.push_back(a);
  }

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    dq.push_front(a);
    cout << dq.back() << ' ';
    dq.pop_back();
  }

  return 0;
}