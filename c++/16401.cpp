#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int M, N;

bool isPossible(int k) {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += v[i] / k;
  }

  return sum >= M;
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> M >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  int start = 1;
  int end = v.back();

  while (start <= end) {
    int mid = (start + end) / 2;

    if (isPossible(mid)) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << end;

  return 0;
}