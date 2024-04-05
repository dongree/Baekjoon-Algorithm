// 12:04 start

#include <iostream>

using namespace std;

int A[201];
int belt[201];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, K;

  cin >> N >> K;

  int length = 2 * N;

  for (int i = 1; i <= length; i++) {
    cin >> A[i];
  }

  int round = 1;

  while (true) {
    // 1. 벨트 회전
    int temp = belt[length];
    int temp2 = A[length];
    for (int i = length; i > 1; i--) {
      belt[i] = belt[i - 1];
      A[i] = A[i - 1];
    }
    belt[1] = temp;
    A[1] = temp2;

    belt[N] = 0;

    // 2. 로봇 이동
    for (int i = N - 1; i >= 1; i--) {
      if (belt[i] != 0 && belt[i + 1] == 0 && A[i + 1] >= 1) {
        belt[i + 1] = 1;
        belt[i] = 0;
        A[i + 1]--;
      }
    }
    belt[N] = 0;

    // 3. 로봇 두기
    if (belt[1] == 0 && A[1] != 0) {
      belt[1] = 1;
      A[1]--;
    }

    // 내구도 0 계산
    int cnt = 0;
    for (int i = 1; i <= length; i++) {
      if (A[i] == 0) cnt++;
    }
    if (cnt >= K) break;

    round++;
  }

  cout << round;

  return 0;
}