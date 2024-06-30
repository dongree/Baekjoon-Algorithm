#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq;
pair<int, int> jewelry[300001];
vector<int> bags;

int main() {
  freopen("example.txt", "r", stdin);
  int N, K;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> jewelry[i].first >> jewelry[i].second;
  }

  for (int i = 0; i < K; i++) {
    int a;
    cin >> a;
    bags.push_back(a);
  }

  sort(jewelry, jewelry + N);
  sort(bags.begin(), bags.end());

  long long sum = 0;
  int idx = 0;

  for (int i = 0; i < K; i++) {
    while (idx < N && jewelry[idx].first <= bags[i]) {
      pq.push(jewelry[idx++].second);
    }
    if (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
  }

  cout << sum;

  return 0;
}