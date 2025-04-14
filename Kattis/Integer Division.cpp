#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  
  map<int,int> mp;
  for(int i = 0,a; i < n; i++){
    cin >> a;
    mp[a/k]++; //紀錄每個商出現的次數
  }
  
  long long cnt = 0;
  for(const auto& num : mp){
    long long x = num.second;
    cnt += (x * (x-1))/2;
  }
  
  cout << cnt << endl;
  return 0;
}
