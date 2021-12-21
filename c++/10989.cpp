#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  int array[10001] = {0};
  cin >> n;

  for(int i=0; i<n; i++){
    int index;
    cin >> index;
    array[index]++;
  }

  for(int i=0; i<10001; i++){
    for(int j=0; j<array[i]; j++){
      cout << i << '\n';
    }
  }

  return 0;
}