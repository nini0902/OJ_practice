#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  long long ans = 1;
  const long long MOD = 1000000007;
  while(n--) ans = (ans*2)%MOD;
  cout << ans << endl;
  return 0;
}
