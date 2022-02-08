// #include <iostream>
// #include <string>

// using namespace std;

// int n, m;
// int maze[101][101];
// int isVisited[101][101] = {false, };
// int minNum = 10000;

// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1 };

// void findRoute(int y, int x, int num){
//   if(!(y==n && x == m)){
//     isVisited[y][x] = true;
//   }
//   if(y==n && x == m && num < minNum){
//     minNum = num;
//     return;
//   }

//   for(int i=0; i<4; i++){
//     int nx = x+dx[i];
//     int ny = y+dy[i];
//     if (1 <= ny && ny <= n && 1 <= nx && nx <= m && maze[ny][nx] && !(isVisited[ny][nx])){
//       findRoute(ny, nx, num+1);
//     } 
//   }
// }

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);
  
//   cin >> n >> m;
//   for(int i=1; i<=n; i++){
//     string r;
//     cin >> r;
    
//     for(int j=1; j<=m; j++){
//       maze[i][j] = r[j-1]-'0';
//     }
//   }

//   findRoute(1, 1, 1);

//   cout << minNum;
//   return 0;
// }

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m;
int maze[101][101];
int isVisited[101][101] = {false, };
int dist[101][101];
queue<pair<int, int>> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1 };

void bfs(int y, int x){
  q.push(make_pair(y, x));
  isVisited[y][x] = true;
  dist[y][x] = 1;
  while(!(q.empty())){
    y = q.front().first;
    x = q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (1 <= ny && ny <= n && 1 <= nx && nx <= m && maze[ny][nx] && !(isVisited[ny][nx])){
        q.push(make_pair(ny, nx));
        isVisited[ny][nx] = true;
        dist[ny][nx] = dist[y][x] + 1;
      } 
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    string r;
    cin >> r;
    
    for(int j=1; j<=m; j++){
      maze[i][j] = r[j-1]-'0';
    }
  }

  bfs(1, 1);

  cout << dist[n][m];
  return 0;
}