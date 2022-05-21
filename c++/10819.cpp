#include <iostream>

using namespace std;

int arr[8];
int arr2[8];
int isVisited[8];
int n;
int maxValue = -1;

void dfs(int cnt){
  if(cnt==n){
    int result = 0;
    for(int i=0; i<n-1; i++){
      result += abs(arr2[i+1]-arr2[i]);
    }
    if(result>maxValue) maxValue = result;
    return;
  }
  for(int i=0; i<n; i++){
    if(!isVisited[i]){
      isVisited[i] = true;
      arr2[cnt] = arr[i];
      dfs(cnt+1);
      isVisited[i] = false;
    }
  }
}

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  dfs(0);
  cout << maxValue;
  return 0;
}