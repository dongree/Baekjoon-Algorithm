#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[20][20];
int visited[20];
int answer = 1e9;

void dfs(int curr, int cnt) {
  if (cnt == N / 2) {
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < N; i++) {
      if (visited[i])
        a.push_back(i);
      else
        b.push_back(i);
    }

    int aa = 0;
    int bb = 0;

    for (int i = 0; i < N / 2; i++) {
      for (int j = 0; j < N / 2; j++) {
        aa += arr[a[i]][a[j]];
        bb += arr[b[i]][b[j]];
      }
    }

    if (abs(aa - bb) < answer) {
      answer = abs(aa - bb);
    }

    return;
  }

  for (int i = curr; i < N; i++) {
    visited[i] = true;
    dfs(i + 1, cnt + 1);
    visited[i] = false;
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  dfs(0, 0);

  cout << answer;

  return 0;
}