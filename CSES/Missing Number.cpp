#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, ans = 0;
  cin >> n;
  
  for(int i = 1, t; i < n; i++){
    cin >> t;
    ans += (i-t);
  }
  cout << ans+n << endl;
  return 0;
}
