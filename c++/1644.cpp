#include <iostream>
#include <vector>

using namespace std;

bool isNotPrime[4000001];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 2; i * i <= N; i++) {
    if (!isNotPrime[i]) {
      for (int j = i * i; j <= N; j += i) {
        isNotPrime[j] = true;
      }
    }
  }
  vector<int> v;

  for (int i = 2; i <= N; i++) {
    if (!isNotPrime[i]) v.push_back(i);
  }

  int p1 = 0;
  int p2 = 0;
  int sum = 2;
  int answer = 0;

  while (p1 <= p2 && p2 < v.size()) {
    if (sum >= N) {
      if (sum == N) answer++;
      sum -= v[p1++];
    } else {
      sum += v[++p2];
    }
  }

  cout << answer;

  return 0;
}