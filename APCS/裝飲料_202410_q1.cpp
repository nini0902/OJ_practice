#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int w1, w2, h1, h2;
  cin >> w1 >> w2 >> h1 >> h2;
  int c1 = (w1*w1)*h1;
  int c2 = (w2*w2)*h2;
  
  int M = 0;
  for(int i = 0, wa; i < n; i++){
    cin >> wa;
    if(wa <= c1){
      M = max(M, wa/(w1*w1));
      c1 -= wa;
    }
    else if(wa <= c1+c2){
      wa -= c1;
      M = max(M, c1/(w1*w1)+wa/(w2*w2));
      c2 -= wa;
      c1 = 0;
    }
    else{
      M = max(M, c2/(w2*w2) + c1/(w1*w1));
      break;
    }
  }
  cout << M << endl;
  return 0;
}
