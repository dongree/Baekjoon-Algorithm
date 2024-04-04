#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;

  while (T--) {
    priority_queue<int, vector<int>, greater<int>> pq1;  // 최소 힙
    priority_queue<int, vector<int>> pq2;                // 최대 힙
    map<int, int> mp;

    int k;
    cin >> k;

    while (k--) {
      char c;
      int n;
      cin >> c >> n;

      if (c == 'I') {
        pq1.push(n);
        pq2.push(n);
        if (mp.find(n) == mp.end()) {
          mp[n] = 1;
        } else {
          mp[n]++;
        }
      } else {
        if (n == 1) {
          while (!pq2.empty()) {
            int top = pq2.top();
            if (mp[top] == 0) {
              pq2.pop();
            } else {
              pq2.pop();
              mp[top]--;
              break;
            }
          }
        } else {
          while (!pq1.empty()) {
            int top = pq1.top();
            if (mp[top] == 0) {
              pq1.pop();
            } else {
              pq1.pop();
              mp[top]--;
              break;
            }
          }
        }
      }
    }

    while (!pq1.empty()) {
      int top = pq1.top();
      if (mp[top] == 0) {
        pq1.pop();
      } else {
        break;
      }
    }

    while (!pq2.empty()) {
      int top = pq2.top();
      if (mp[top] == 0) {
        pq2.pop();
      } else {
        break;
      }
    }

    if (pq1.size() == 0 && pq2.size() == 0)
      cout << "EMPTY" << '\n';
    else
      cout << pq2.top() << ' ' << pq1.top() << '\n';
  }

  return 0;
}