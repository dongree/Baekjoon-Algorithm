#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> arr;

int main() {
  freopen("example.txt", "r", stdin);
  int M, N;
  cin >> M >> N;

  for (int i = 0; i < M; i++) {
    unordered_map<int, int> dic;
    vector<int> v;
    for (int j = 0; j < N; j++) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    vector<int> temp = v;
    sort(v.begin(), v.end());
    int idx = 1;
    for (int j = 0; j < N; j++) {
      dic[v[j]] = idx++;
    }

    string s;
    for (int j = 0; j < N; j++) {
      s += to_string(dic[temp[j]]);
    }
    arr.push_back(s);
  }

  int ans = 0;
  for (int i = 0; i < M - 1; i++) {
    for (int j = i + 1; j < M; j++) {
      if (arr[i] == arr[j]) ans++;
    }
  }

  cout << ans;

  return 0;
}