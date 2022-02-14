#include <iostream>
#include <algorithm>

using namespace std;

int people[1000];

int main(){
  int n, result = 0;
  cin >> n;
  
  for(int i=0; i<n; i++){
    cin >> people[i];
  }

  sort(people, people+n);

  for(int i=0; i<n; i++){
    result += people[i]*(n-i);
  }

  cout << result;

  return 0;
}

