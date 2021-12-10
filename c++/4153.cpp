#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int line[3] ={0};

  while(true){
    for(int i=0; i<3; i++){
      cin >> line[i];
    }
    sort(line, line+3);

    if(line[0]==0 && line[1]==0 && line[2]==0){
      break;
    }
    if(line[0]*line[0] + line[1]*line[1] == line[2]*line[2]){
      cout << "right" << '\n';
    } else{
      cout << "wrong" << '\n';
    }
  }

  return 0;
}