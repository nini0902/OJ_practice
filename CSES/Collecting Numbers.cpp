#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i = 0; i < n; i++) cin >> vec[i];
  
  vector<int> idx(n);
  //儲存每個數字的索引
  for(int i = 0; i < n; i++) idx[vec[i]] = i;
  
  int cnt = 1;
  for(int i = 1; i < n; i++){
    if(idx[i] > idx[i+1]) cnt++;
  }
  
  cout << cnt << endl;
return 0;
}
