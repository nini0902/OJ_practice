#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, size;
  
  DSU(int n) {
    parent.resize(n+2);
    size.resize(n+2);
    for(int i = 1; i < n+1; i++) {
      parent[i] = i;
      size[i] = 0;
    }
  }
  
  int find(int x) {
    if(parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  
  void unite(int x, int y, multiset<int>& all_sizes) {
    int rx = find(x);
    int ry = find(y);
    
    all_sizes.erase(all_sizes.find(size[rx]));
    all_sizes.erase(all_sizes.find(size[ry]));
    
    parent[ry] = rx;
    size[rx] += size[ry];
    
    all_sizes.insert(size[rx]);
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n,m;
  cin >> n >> m;
  
  vector<int> ribbon(n+3, 0);
  DSU dsu(n);
  multiset<int> all_sizes;
  
  for(int i = 1; i < n+1; i++) {
    cin >> ribbon[i];
    if(ribbon[i] == 1) {
      dsu.parent[i] = i;
      dsu.size[i] = 1;
      all_sizes.insert(1);
      
      if(ribbon[i-1] == 1) {
        dsu.unite(i, i-1, all_sizes);
      }
    }
  }
  
  long long sum_max = 0, sum_min = 0;
  
  if(!all_sizes.empty()) {
    sum_max += *all_sizes.rbegin();
    sum_min += *all_sizes.begin();
  }
  
  for(int i = 0; i < m; i++) {
    int pos;
    cin >> pos;
    
    ribbon[pos] = 1; // make it red 
    dsu.parent[pos] = pos;
    dsu.size[pos] = 1;
    all_sizes.insert(1);
    
    // check left
    if(ribbon[pos-1] == 1) {
      dsu.unite(pos, pos-1, all_sizes);
    }
    
    // check right
    if(ribbon[pos+1] == 1) {
      dsu.unite(pos, pos+1, all_sizes);
    }
    
    sum_max += *all_sizes.rbegin();
    sum_min += *all_sizes.begin();
  }
  
  cout << sum_max << endl;
  cout << sum_min << endl;
  
  
  return 0;
}
