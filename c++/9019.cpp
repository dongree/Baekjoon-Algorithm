
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool isVisited[10000];
string commands[10000];

int D(int n) { return (n * 2) % 10000; }
int S(int n) {
  if (n == 0) return 9999;
  return n - 1;
}
int L(int n) {
  int k = n / 1000;
  n = n % 1000;
  n = n * 10 + k;
  return n;
}
int R(int n) {
  int k = n % 10;
  n = n / 10;
  n = k * 1000 + n;
  return n;
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    queue<int> q;
    memset(isVisited, false, sizeof(isVisited));
    for (int i = 0; i < 10000; i++) {
      commands[i] = "";
    }

    int a, b;
    cin >> a >> b;

    q.push(a);
    isVisited[a] = true;

    while (!q.empty()) {
      int num = q.front();
      q.pop();

      if (num == b) {
        cout << commands[b] << '\n';
        break;
      }

      int numD = D(num);
      if (!isVisited[numD]) {
        isVisited[numD] = true;
        commands[numD] = commands[num] + 'D';
        q.push(numD);
      }
      int numS = S(num);
      if (!isVisited[numS]) {
        isVisited[numS] = true;
        commands[numS] = commands[num] + 'S';
        q.push(numS);
      }
      int numL = L(num);
      if (!isVisited[numL]) {
        isVisited[numL] = true;
        commands[numL] = commands[num] + 'L';
        q.push(numL);
      }
      int numR = R(num);
      if (!isVisited[numR]) {
        isVisited[numR] = true;
        commands[numR] = commands[num] + 'R';
        q.push(numR);
      }
    }
  }

  return 0;
}