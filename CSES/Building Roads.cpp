#include <bits/stdc++.h>
using namespace std;
int n, r, cnt = 0, cnt1 = 1;
vector<bool> visited;
vector<vector<int>> vec;

void dfs(int root){
  visited[root] = true;
  
  for(int k : vec[root]){
    if(visited[k]) continue;
    dfs(k);
  }
}

int main(){
  cin >> r >> n;
  
  vec.resize(r+1);
  visited.resize(r+1, false);
  for(int i = 0,from,to; i < n; i++){
    cin >> from >> to;
    vec[from].push_back(to);
    vec[to].push_back(from);
  }
  
  vector<int> ans;
  for(int i = 1; i <= r; i++){
    if(visited[i] == false) {
      ans.push_back(i); //無法連通的路
      dfs(i); //建造路後重新走一次
    }
  }
  
  cout << ans.size()-1 << endl; //n個城市間只會有n-1條路
  for(int i = 0; i < ans.size()-1; i++) cout << ans[i] << " " << ans[i+1] << endl;
  return 0;
}
