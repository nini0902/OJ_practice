#include <bits/stdc++.h>
#define LL long long 
#define MOD 1000000007
using namespace std;

LL cal(int num, int t){
  if(t == 0) return 1;
  
  LL half = cal(num, t/2) % MOD;
  half = (half * half)%MOD;
  if(t%2==1) return (half*num)%MOD;
  else return half;
}

int main(){
  int n;
  cin >> n;
  
  for(int i = 0, k, t; i < n; i++){
    cin >> k >> t;
    cout << cal(k,t) << endl;
  }
  return 0;
}
