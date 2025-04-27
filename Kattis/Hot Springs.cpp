#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> vec(n);
  
  for(int i = 0; i < n; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  
  vector<int> ans(n);
  int l = (n/2), r = l+1;
  ans[0] = vec[l];
  l--;
  
  for(int i = 1; i < n; i++){
    if(i %2 == 1){
      ans[i] = vec[l];
      l--;
    }
    else {
      ans[i] = vec[r];
      r++;
    }
  }
  
  for(int k : ans) cout << k << " ";
  cout << endl;
  return 0;
}
