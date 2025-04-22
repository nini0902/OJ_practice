#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>& p1, pair<int,int>& p2){
  return p1.second < p2.second;
}

int main(){
  int n,k,num;
  cin >> n >> k;
  
  map<int,int> ball;
  for(int i = 0; i < n; i++){
    cin >> num;
    ball[num]++;
  }
  
  vector<pair<int, int>> vec;
  for(auto& b : ball) vec.push_back({b.first, b.second});
  sort(vec.begin(), vec.end(), comp);
  
  int cnt = 0;
  for(int i = 0; i < max(0,int(vec.size())-k); i++){
    cnt += vec[i].second;
  }
  cout << cnt << endl;
  return 0;
}
