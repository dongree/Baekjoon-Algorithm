#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N * N; i++) {
    int temp;
    cin >> temp;
    pq.push(temp);
    if (pq.size() > N) pq.pop();
  }

  cout << pq.top();

  return 0;
}