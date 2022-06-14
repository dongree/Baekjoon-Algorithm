#include <iostream>

using namespace std;

bool check[246913];

int main(){
  for(int i=2; i*i<=246912; i++){
    if(!check[i]){
      for(int j=i*i; j<=246912; j+=i){
        check[j] = true;
      }
    }
  }
  while(true){
    int n;
    cin >> n;
    if(n==0) break;
    int cnt = 0;
    for(int i=n+1; i<=2*n; i++){
      if(!check[i]) cnt++;
    }
    cout << cnt << '\n';
  }
  return 0;
}