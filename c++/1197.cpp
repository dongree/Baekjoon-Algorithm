// kruskal
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> v;
int parent[10001];
int answer;

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;
}

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  return a == b;
}

int main() {
  freopen("example.txt", "r", stdin);
  int V, E;
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    v.push_back({C, {A, B}});
  }

  sort(v.begin(), v.end());

  for (int i = 1; i <= V; i++) {
    parent[i] = i;
  }

  int cnt = 0;
  for (int i = 0; i < E; i++) {
    int weight = v[i].first;
    int from = v[i].second.first;
    int to = v[i].second.second;

    if (!sameParent(from, to)) {
      unionParent(from, to);
      answer += weight;
      cnt++;
    }

    if (cnt == V - 1) break;
  }

  cout << answer;

  return 0;
}

// prim
// #include <iostream>
// #include <queue>

// using namespace std;

// int V, E;
// vector<pair<int, int>> v[10001];
// bool isVisited[10001];

// long long prim() {
//   long long ans = 0;
//   priority_queue<pair<int, int>, vector<pair<int, int>>,
//                  greater<pair<int, int>>>
//       pq;
//   pq.push({0, 1});

//   while (!pq.empty()) {
//     int weight = pq.top().first;
//     int currNode = pq.top().second;
//     pq.pop();

//     if (isVisited[currNode]) continue;
//     isVisited[currNode] = true;
//     ans += weight;

//     for (int i = 0; i < v[currNode].size(); i++) {
//       int nextWeight = v[currNode][i].first;
//       int nextNode = v[currNode][i].second;
//       if (!isVisited[nextNode]) {
//         pq.push({nextWeight, nextNode});
//       }
//     }
//   }
//   return ans;
// }

// int main() {
//   freopen("example.txt", "r", stdin);
//   cin >> V >> E;

//   while (E--) {
//     int A, B, C;
//     cin >> A >> B >> C;
//     v[A].push_back({C, B});
//     v[B].push_back({C, A});
//   }

//   cout << prim();

//   return 0;
// }