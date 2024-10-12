#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> vec(n);
  for(int i = 0; i < n; i++) cin >> vec[i];
  
  queue<int> Q;
  int cnt = 0, now = 0;
  for(int i = 0; i < n; i++){
    Q.push(vec[i]);
    now += vec[i];
    while(!Q.empty() && now > k){
      now -= Q.front();
      Q.pop();
    }
    if(now == k) cnt++;
  }
  
  cout << cnt << endl;
  return 0;
}
