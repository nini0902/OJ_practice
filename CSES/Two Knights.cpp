#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  
  int pre[4] = {0,0,6,28};
  for(int i = 1; i <= min(3,n); i++) cout << pre[i] << endl;
  for(long long i = 4; i <= n; i++){
    cout << (i*i*(i*i-1))/2 - 4*(i-1)*(i-2) << endl;
  }
  return 0;
}
