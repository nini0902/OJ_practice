#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  unordered_map<int, pair<int,int>> mp;
  vector<pair<int,int>> vec(n);
  
  for(int i = 0; i < n; i++) {cin >> vec[i].first; vec[i].second = i+1;}
  sort(vec.begin(), vec.end());
  
  //哈希表(窮組所有兩數和組合)
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      mp[vec[i].first + vec[j].first] = {i,j};
    }
  }
  
  if(n < 4) cout << "IMPOSSIBLE" << endl; //不到四個數字
  
  for(int i = 0; i < n-1; i++){
    if(n < 4) break;
    for(int j = i+1; j < n; j++){
      int sum = m-vec[i].first-vec[j].first;
      
      if(mp.count(sum)){
        auto[a,b] = mp[sum];
        //找不重複的組合
        if(a != i && a != j && b != i && b!= j){
          cout << vec[a].second << " " << vec[b].second << " ";
          cout << vec[i].second << " " << vec[j].second << endl;
          j = n, i = n;
        }
        else if(i == n-2 && j == n-1) cout << "IMPOSSIBLE" << endl;
      }
      else if(i == n-2 && j == n-1) cout << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}
