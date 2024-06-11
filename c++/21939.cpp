#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

struct compare1 {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }
    return a.second > b.second;
  }
};

struct compare2 {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare1>
    pq1;  // 쉬운 순
priority_queue<pair<int, int>, vector<pair<int, int>>, compare2>
    pq2;  // 어려운 순

unordered_map<int, int> dic;

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  while (N--) {
    int a, b;
    cin >> a >> b;
    pq1.push({a, b});
    pq2.push({a, b});
  }

  int M;
  cin >> M;

  while (M--) {
    string s;
    cin >> s;

    if (s == "add") {
      int a, b;
      cin >> a >> b;
      pq1.push({a, b});
      pq2.push({a, b});
    } else if (s == "recommend") {
      int x;
      cin >> x;
      if (x == -1) {
        while (dic[pq1.top().first] == 1) {
          dic[pq1.top().first] = 0;
          pq1.pop();
        };
        cout << pq1.top().first << '\n';
      } else {
        while (dic[pq2.top().first] == 1) {
          dic[pq2.top().first] = 0;
          pq2.pop();
        };
        cout << pq2.top().first << '\n';
      }
    } else if (s == "solved") {
      int x;
      cin >> x;
      dic[x] = 1;
    }
  }
}