#include <iostream>

using namespace std;

int a[101][101];
int b[101][101];

int main(){
  int n, m, k;
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int p;
      cin >> p;
      a[i][j] = p;
    }
  }
  cin >> m >> k;
  for(int i=0; i<m; i++){
    for(int j=0; j<k; j++){
      int q;
      cin >> q;
      b[i][j] = q;
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<k; j++){
      int sum = 0;
      for(int l=0; l<m; l++){
        sum += a[i][l]*b[l][j];
      }
      cout << sum << ' ';
    }
    cout << '\n';
  }

  return 0;
}