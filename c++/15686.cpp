#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[51][51];
int answer = INT_MAX;
vector<pair<int, int>> homes;
vector<pair<int, int>> chickens;
vector<pair<int, int>> running;

void dfs(int idx) {
  if (running.size() == m) {
    int chikenDistInCity = 0;
    for (int i = 0; i < homes.size(); i++) {
      int homeY = homes[i].first;
      int homeX = homes[i].second;
      int chickenDist = INT_MAX;
      for (int j = 0; j < running.size(); j++) {
        int resY = running[j].first;
        int resX = running[j].second;
        int dist = abs(homeY - resY) + abs(homeX - resX);
        chickenDist = min(chickenDist, dist);
      }
      chikenDistInCity += chickenDist;
    }
    answer = min(answer, chikenDistInCity);
    return;
  }

  for (int i = idx; i < chickens.size(); i++) {
    running.push_back(chickens[i]);
    dfs(i + 1);
    running.pop_back();
  }
}

int main() {
  // freopen("example.txt", "r", stdin);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a == 1)
        homes.push_back(make_pair(i, j));
      else if (a == 2)
        chickens.push_back(make_pair(i, j));
    }
  }

  dfs(0);
  cout << answer;
}