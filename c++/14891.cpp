#include <iostream>
#include <string>

using namespace std;

string wheel[5];

void rotate(int dir, int num){
  char temp;
  string sub;
  if(dir==1){
    temp=wheel[num][7];
    sub=wheel[num].substr(0,7);
    wheel[num]=temp+sub;
  }else{
    temp=wheel[num][0];
    sub=wheel[num].substr(1);
    wheel[num]=sub+temp;
  }
}

void action(int dir, int num, bool left){
  int op_dir = (dir==1) ? -1 : 1;
  if(1<=num&&num<=4){
    if(left){
      if(wheel[num][2]!=wheel[num+1][6]){
        action(op_dir, num-1, left);
        rotate(op_dir, num);
      };
    }else{
      if(wheel[num-1][2]!=wheel[num][6]){
        action(op_dir, num+1, left);
        rotate(op_dir, num);
      };
    }
  }
  return;
}

int main(){
  for(int i=1; i<=4; i++){
    cin >> wheel[i];
  }
  int k;
  cin >> k;
  for(int i=0; i<k; i++){
    int n,dir;
    cin >> n >> dir;
    action(dir,n-1, true);
    action(dir,n+1, false);
    rotate(dir, n);
  }
  int score=0;
  for(int i=1; i<=4; i++){
    if(wheel[i][0]=='1'){
      int a=1;
      for(int j=0; j<i-1; j++){
        a*=2;
      }
      score+=a;
    }
  }
  cout << score;
  return 0;
}
