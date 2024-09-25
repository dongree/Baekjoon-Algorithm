#include <iostream>
#include <string>

using namespace std;

bool isPrime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

bool isPellindrom(int n) {
  string s = to_string(n);

  int a = 0;
  int b = s.length() - 1;

  while (a < b) {
    if (s[a] != s[b]) return false;
    a++;
    b--;
  }

  return true;
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  while (true) {
    if (isPrime(N) && isPellindrom(N)) {
      cout << N;
      return 0;
    }
    N++;
  }

  return 0;
}