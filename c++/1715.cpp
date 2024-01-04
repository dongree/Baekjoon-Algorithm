#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;

  cin >> n;

  priority_queue<int, vector<int>, greater<int>> pq;

  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    pq.push(num);
  }

  int answer = 0;
  while (pq.size() != 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    int subSum = a + b;
    answer += subSum;
    pq.push(subSum);
  }

  cout << answer;

  return 0;
}