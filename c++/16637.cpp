#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> operands;
vector<char> operators;
int ans = -1e9;

int calc(char oper, int a, int b) {
  if (oper == '+')
    return a + b;
  else if (oper == '-')
    return a - b;
  else
    return a * b;
}

void dfs(int idx, int result) {
  if (idx == operators.size()) {
    ans = max(ans, result);
    return;
  }

  dfs(idx + 1, calc(operators[idx], result, operands[idx + 1]));

  if (idx + 2 <= operators.size()) {
    int temp = calc(operators[idx + 1], operands[idx + 1], operands[idx + 2]);
    dfs(idx + 2, calc(operators[idx], result, temp));
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  string s;
  cin >> s;

  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      operands.push_back(s[i] - '0');
    else
      operators.push_back(s[i]);
  }

  dfs(0, operands[0]);

  cout << ans;

  return 0;
}
