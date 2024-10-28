//sort + binary
#include <bits/stdc++.h>
#define s first
#define e second
using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int>& b){
  return a.e < b.e;
}

int main(){
  int n,k;
  cin >> n >> k;
  vector<pair<int,int>> vec(n);
  for(int i = 0; i < n; i++) cin >> vec[i].s;
  for(int i = 0; i < n; i++) cin >> vec[i].e; 
  
  sort(vec.begin(), vec.end(), comp);
  
  multiset<int> st;
  int ans = 0;
  for(int i = 0; i < k; i++) st.insert(0); //放入k個機器
  
  for(auto v : vec){
    auto it = st.lower_bound(v.s); //檢查有沒有最早可用的機器
    
    if(it != st.begin()){ //表示有找到機器
      --it; //lower_bound找到>=開始時間的第一台，所以-1才是最早可以用的
      ans++;
      st.erase(it); //刪掉可用機器
      st.insert(v.e); //加入新的結束時間
    }
  }
  cout << ans << endl;
  return 0;
}v
