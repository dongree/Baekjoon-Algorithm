#include <iostream>

using namespace std;

int arr[12];
int lotto[6];
int t;

void dfs(int num, int cnt){
  if(cnt==6){
    for(int i=0; i<6; i++){
      cout << lotto[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=num; i<t; i++){
    lotto[cnt] = arr[i];
    dfs(i+1, cnt+1);
  }
}

int main(){
  while(true){
    cin >> t;
    if(t==0) break;
    for(int i=0; i<t; i++){
      cin >> arr[i];
    }
    dfs(0, 0);
    cout << '\n';
  }
  return 0;
}