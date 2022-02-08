// #include <iostream>

// using namespace std;

// int map[101][101];
// bool isVisited[101] = {false, };
// int computerN, pairN;
// int infectedN = 0;

// void dfs(int node){
//   isVisited[node] = true;
//   for(int i=1; i<=computerN; i++){
//     if(map[node][i] && !(isVisited[i])){
//       infectedN++;
//       dfs(i);
//     }
//   }
// }

// int main(){
//   cin >> computerN >> pairN;

//   for(int i=0; i<pairN; i++){
//     int x, y;
//     cin >> y >> x;
//     map[x][y] = map[y][x] = 1;
//   }

//   dfs(1);

//   cout << infectedN;
//   return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
bool isVisited[101] = {false, };
int computerN, pairN;
int infectedN = 0;
queue<int> q;

void bfs(int node){
  q.push(node);
  isVisited[node] = true;

  while(!q.empty()){
    node = q.front();
    q.pop();

    for(int i=1; i<=computerN; i++){
      if(map[node][i]==1 && !(isVisited[i])){
        q.push(i);
        isVisited[i] = true;
        infectedN++;
      }
    }
  }
}

int main(){
  cin >> computerN >> pairN;

  for(int i=0; i<pairN; i++){
    int x, y;
    cin >> y >> x;
    map[x][y] = map[y][x] = 1;
  }

  bfs(1);

  cout << infectedN;
  return 0;
}
