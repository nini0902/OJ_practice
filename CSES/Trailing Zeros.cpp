#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  long long cnt = 0;
  //計算n!有多少個因數5
  while(n){
    cnt += (n/5);
    n /= 5;
  }
  cout << cnt << endl;
  return 0;
}
