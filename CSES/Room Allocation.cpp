#include <bits/stdc++.h>
using namespace std;

struct customer{
  int s;
  int e;
  int idx;
};

int main(){
  int n;
  cin >> n;
  vector<customer> vec(n);
  
  for(int i = 0; i < n; i++) {cin >> vec[i].s >> vec[i].e; vec[i].idx = i;}
  sort(vec.begin(), vec.end(), [](const customer&a, customer &b){
    return a.s < b.s;
  });
  
  //紀錄目前每間房間上一位離開的時間+房間編號
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> ans(n);
  int last_room = 1;
  pq.push({vec[0].e, 1});
  ans[vec[0].idx] = 1;
  
  for(int i = 1; i < n; i++){
    if(pq.top().first >= vec[i].s){
      last_room++;
      pq.push({vec[i].e, last_room});
      ans[vec[i].idx] = last_room;
    }
    else {
      auto it = pq.top();
      pq.pop();
      pq.push({vec[i].e, it.second});
      ans[vec[i].idx] = it.second;
    }
  }
  cout << last_room << endl;
  for(int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
