// backtracking
#include <iostream>

using namespace std;

char arr[10];
char arr2[10];
bool isVisited[10];
string s;
int n, count;
bool flag;

void dfs(int cnt){
  if(cnt==s.length()){
    count++;
    if(count==n){
      flag = false;
      for(int i=0; i<s.length(); i++){
        cout << arr2[i];
      }
      cout << '\n';
    }
    return;
  }

  for(int i=0; i<s.length(); i++){
    if(!isVisited[i]){
      isVisited[i] = true;
      arr2[cnt] = arr[i];
      dfs(cnt+1);
      isVisited[i] = false;
    }
  }
}

int main(){
  while(cin >> s >> n){
    for(int i=0; i<s.length(); i++){
      arr[i] = s[i];
    }
    count = 0;
    flag = true;
    cout << s << ' ' << n << " = ";
    dfs(0);
    if(flag){
      cout << "No permutation" << '\n';
    }
  }
  return 0;
}