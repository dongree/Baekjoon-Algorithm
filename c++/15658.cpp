#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A[11];
int operatorCnt[4];
int N;
int maxV = -1e9;
int minV = 1e9;

void dfs(int result, int idx) {
  if (idx == N) {
    maxV = max(maxV, result);
    minV = min(minV, result);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (operatorCnt[i] == 0) continue;
    int nextResult = result;
    if (i == 0)
      nextResult += A[idx];
    else if (i == 1)
      nextResult -= A[idx];
    else if (i == 2)
      nextResult *= A[idx];
    else
      nextResult /= A[idx];

    operatorCnt[i]--;
    dfs(nextResult, idx + 1);
    operatorCnt[i]++;
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < 4; i++) {
    cin >> operatorCnt[i];
  }

  dfs(A[0], 1);

  cout << maxV << '\n' << minV;

  return 0;
}