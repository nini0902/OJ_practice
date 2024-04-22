#include <bits/stdc++.h>
#define N 501
using namespace std;
int t[N][N];
int main(){
    int n,m,r;
    cin >> n >> m >> r;
    int r1,c1,r2,c2; //從(r1,c1)種到(r2,c2)
    
    for(int i = 0; i < r; i++){
        cin >> c1 >> r1 >> c2 >> r2;
        int dr = r2-r1;
        int dc = c2-c1;
        if(dr > 0) dr = 1; else if(dr < 0) dr = -1; //決定走的方向
        if(dc > 0) dc = 1; else if(dc < 0) dc = -1;

        t[r2][c2] = 1;

        if(r1 == r2){ //同一列，動c即可
            for(int c = c1; c!=c2; c += dc){
                t[r1][c] = 1;
            }
        }
        else{
            for(int r = r1, c = c1; r != r2; r += dr, c += dc){ //否則走斜線
                t[r][c] = 1;
            }
        }
    }
    
    int tsum = 0;
        for(int r = 1; r <= m; r++){
            for(int c = 1; c <= n; c++){
                tsum += t[r][c];
            }
        }

        cout << tsum << endl;
return 0;
}
