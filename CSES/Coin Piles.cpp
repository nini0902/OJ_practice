#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int l,r;
  for(int i = 0; i < n; i++){
    cin >> l >> r;
    
    if((r==0&&l!=0)||(l==0&&r!=0) || (2*l-r < 0) || (2*r-l < 0)) cout << "NO" << endl;
    else if((2*l-r)%3 == 0 && (2*r-l)%3 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
