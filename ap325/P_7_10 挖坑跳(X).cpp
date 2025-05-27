#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<vector<pair<int,int>>> parent;
vector<vector<int>> d;

pair<int,int> find(pair<int,int> pos) {
  int x = pos.first, y = pos.second;
  while(parent[x][y] == pos) {
    return pos;
  }
  return parent[x][y] = find(parent[x][y]);
}

void union_set(pair<int,int> a, pair<int,int> b) {
  pair<int,int> pa = find(a);
  pair<int,int> pb = find(b);
  if(pa != pb) parent[a.first][a.second] = pb;
}

int main(){
  cin >> n >> m >> k;
  d.assign(n+2, vector<int>(m+2, 0));
  parent.assign(n+2, vector<pair<int,int>>(m+2));
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> d[i][j];
    }
  }
  
  // initialize parent
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      parent[i][j] = {i, j};
    }
  }
  
  // union the same water ceil
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(d[i][j] != 1) continue; // not water ceil
      for(int x = -1; x <= 1; x++) {
        for(int y = -1; y <= 1; y++) {
          // dir: {-1,0}, {1,0}, {0,-1}, {0,1}
          if(abs(x) + abs(y) != 1) continue;
          int nx = i + x, ny = j + y;
          if(d[nx][ny] == 1) { // is water ceil 
            union_set({i,j}, {nx,ny});
          }
        }
      }
    }
  }
  
  int px,py;
  for(int i = 0; i < k; i++) {
    cin >> px >> py;
    d[px][py] = 1;
    for(int x = -1; x <= 1; x++) {
      for(int y = -1; y <= 1; y++) {
        int nx = px+x, ny = py + y;
        if(d[nx][ny] == 1) {
          union_set({px,py}, {nx,ny});
        }
      }
    }
  }
  return 0;
}
