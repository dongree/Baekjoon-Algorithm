#include <iostream>
#include <map>

using namespace std;

int parent[200001];
int friendsNum[200001];

void init() {
  for (int i = 0; i <= 200000; i++) {
    parent[i] = i;
  }
  for (int i = 0; i <= 200000; i++) {
    friendsNum[i] = 1;
  }
}

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a < b) {
    parent[b] = a;
    friendsNum[a] += friendsNum[b];
  } else if (a > b) {
    parent[a] = b;
    friendsNum[b] += friendsNum[a];
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    init();
    map<string, int> dic;

    int dicNum = 1;
    while (N--) {
      string a, b;
      cin >> a >> b;
      if (dic.find(a) == dic.end()) dic.insert({a, dicNum++});
      if (dic.find(b) == dic.end()) dic.insert({b, dicNum++});

      unionParent(dic[a], dic[b]);

      cout << friendsNum[getParent(dic[a])] << '\n';
    }
  }

  return 0;
}