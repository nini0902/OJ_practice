#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  
  for(int i = 0; i < n ; i++){
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  
  int start = vec[0];
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(vec[i] != vec[i-1]+1){
      if(start == vec[i-1]) cout << start << " ";
      else if(cnt > 1) cout << start << "-" << vec[i-1] << " ";
      else cout << start << " " << vec[i-1] << " ";
      cnt = 0;
      start = vec[i];
      continue;
    }
    cnt++;
    if(i == n){
      if(start == vec[i-1]) cout << start << " ";
      else if(cnt > 1) cout << start << "-" << vec[i-1] << " ";
      else cout << start << " " << vec[i-1] << " ";
    }
  }
  
  
  return 0;
}
