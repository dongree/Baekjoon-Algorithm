#include <iostream>
#include <string>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  string S;
  cin >> N >> M >> S;

  int i = 0;
  int cnt = 0;
  int answer = 0;

  while (i <= M - 2) {
    if (S.substr(i, 3).compare("IOI") == 0) {
      i += 2;
      cnt += 1;
      if (cnt == N) {
        cnt -= 1;
        answer += 1;
      }
    } else {
      i += 1;
      cnt = 0;
    }
  }

  cout << answer;
  return 0;
}