#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool isNotPrime[10000];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  for (int i = 2; i * i < 10000; i++) {
    if (!isNotPrime[i]) {
      for (int j = i * i; j < 10000; j += i) {
        isNotPrime[j] = true;
      }
    }
  }
  bool flag = true;

  while (T--) {
    string a, b;
    cin >> a >> b;

    bool isVisited[10000] = {
        false,
    };
    queue<pair<string, int>> q;
    q.push({a, 0});
    isVisited[stoi(a)] = true;

    while (!q.empty()) {
      string pn = q.front().first;
      int cnt = q.front().second;
      q.pop();

      if (pn == b) {
        flag = false;
        cout << cnt << '\n';
        break;
      }

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= 9; j++) {
          if (i == 0 && j == 0) continue;
          string temp = pn;
          temp[i] = '0' + j;
          int num = stoi(temp);
          if (pn.compare(temp) != 0 && !isNotPrime[num] && !isVisited[num]) {
            isVisited[num] = true;
            q.push({temp, cnt + 1});
          }
        }
      }
    }

    if (flag) cout << "Impossible" << '\n';
  }

  return 0;
}