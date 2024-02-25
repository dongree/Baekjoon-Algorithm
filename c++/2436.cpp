#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long gcd, lcm;
vector<int> dividors;
long long answer[2];
long long minVal;

long long getGCD(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return getGCD(b, a % b);
}

void dfs(int idx, long long value) {
  long long a = value;
  long long b = gcd * lcm / value;
  if (getGCD(a, b) == gcd && a + b < minVal) {
    minVal = a + b;
    answer[0] = a;
    answer[1] = b;
  }

  if (idx == dividors.size()) return;

  for (int i = idx; i < dividors.size(); i++) {
    dfs(i + 1, value * dividors[i]);
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> gcd >> lcm;

  long long k = gcd * lcm;
  answer[0] = 1;
  answer[1] = k;
  minVal = k + 1;

  for (int i = 2; i * i <= gcd * lcm; i++) {
    while (k % i == 0) {
      k /= i;
      dividors.push_back(i);
    }
  }

  dfs(0, 1);

  sort(answer, answer + 2);

  cout << answer[0] << ' ' << answer[1];
  return 0;
}