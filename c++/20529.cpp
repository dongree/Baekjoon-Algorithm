#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> mbtis;
vector<string> selected;
int minDist;

void init() {
  minDist = 20;
  while (!mbtis.empty()) {
    mbtis.pop_back();
  }
}

void dfs(int idx) {
  if (selected.size() == 3) {
    int dist = 0;
    for (int i = 0; i < 4; i++) {
      if (selected[0][i] != selected[1][i]) dist++;
      if (selected[0][i] != selected[2][i]) dist++;
      if (selected[1][i] != selected[2][i]) dist++;
    }
    minDist = min(minDist, dist);
    return;
  }
  for (int i = idx; i < mbtis.size(); i++) {
    selected.push_back(mbtis[i]);
    dfs(i + 1);
    selected.pop_back();
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;

    init();

    for (int j = 0; j < N; j++) {
      string s;
      cin >> s;
      mbtis.push_back(s);
    }

    if (N > 32) {
      cout << 0 << '\n';
      continue;
    }

    dfs(0);

    cout << minDist << '\n';
  }

  return 0;
}