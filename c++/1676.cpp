#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  int fiveN = 0;
  for(int i=2; i<=n; i++){
    int b=i;
    while(b%5 == 0){
      b = b/5;
      fiveN += 1;
    }
  }

  cout << fiveN;
  return 0;
}