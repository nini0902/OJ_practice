#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
  LL n, K;
  cin >> n >> K;
  
  vector<LL> vec(n);
  map<LL, LL> mp;
  
  for(LL i = 0, id; i < n; i++){
    cin >> id;
    mp[i] = id; //儲存每個ID的位置
    vec[i] = id;
  }
  
  sort(vec.begin(), vec.end());
  
  LL a = K/n, b = K%n; // a是每個人至少能拿到的，b是多少人能拿第二顆
  for(LL i = 0; i < n; i++){
    if(mp[i] >= vec[b]) cout << a << " ";
    else cout << a+1 << " ";
  }
  cout << endl;
  return 0;
}
