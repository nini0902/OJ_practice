#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  
  vector<int> kid(n);
  for(int i = 0; i < n; i++) cin >> kid[i];
  
  sort(kid.begin(), kid.end());
  
  int ans = 0, w = k;
  int i = 0, j = n-1;
  while(i <= j){
    ans++; w = k;
    w -= kid[j]; j--;
    if(w >= kid[i] && i <= j) i++;
  }
  cout << ans << endl;
  return 0;
}
