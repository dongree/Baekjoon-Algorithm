#include <iostream>

using namespace std;

int main(){
  int e, s, m;
  cin >> e >> s >> m;
  int countE=1;
  int countS=1;
  int countM=1;
  int year = 1;
  while(true){
    if((e==countE)&&(s==countS)&&(m==countM)) break;
    year++;
    countE++;
    countS++;
    countM++;
    if(countE>15) countE=1;
    if(countS>28) countS=1;
    if(countM>19) countM=1;
  }
  cout << year;

  return 0;
}