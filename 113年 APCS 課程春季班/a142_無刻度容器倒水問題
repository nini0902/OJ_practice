#include <bits/stdc++.h>
#define N 2000
using namespace std;
int a[N][N];
//計算當兩容器做了幾步

int bfs(int x, int y, int z){
    a[0][0] = 0; //初始為0步
    queue<pair<int,int>> q;
    q.push({0,0}); 
    bool check[N][N] = {0};
    check[0][0] = true; 

    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();
        int mn = now.first, mx = now.second;
        int d[6][2] = {
            {max(0, mn-(y-mx)), min(mx+mn, y)},{min(mn+mx, x), max(0,mx-(x-mn))},{x,mx},{mn,y},{0,mx},{mn,0}
        };
        for(int i = 0; i < 6; i++){ //窮舉所有可能
            int nx = d[i][0], ny = d[i][1];
            if(nx == z || ny == z) return a[mn][mx]+1;
            if(!check[nx][ny]){
                a[nx][ny] = a[mn][mx]+1; //步驟加一
                check[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}

int main(){
    int n,x,y,z;
    cin >> n;
    while(n--){
        cin >> x >> y >> z;
        if(x > y) swap(x,y);
        cout << bfs(x,y,z) << endl;
    }
    return 0;
}
