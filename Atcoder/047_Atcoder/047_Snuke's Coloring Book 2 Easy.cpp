#include <bits/stdc++.h>
using namespace std;

int main(){
    int W,H,n,x,y,d,cnt = 0;
    cin >> W >> H >> n;
    vector<vector<int>> p(H,vector<int>(W,0));

    for(int i = 0; i < n; i++){
        cin >> x >> y >> d;
        if(d==1){
            for(int i = 0; i < x; i++){
                for(int j = 0; j < H; j++) p[j][i] = 1;
            }
        }
        else if(d==2){
            for(int i = x; i < W; i++){
                for(int j = 0; j < H; j++) p[j][i] = 1;
            }
        }
        else if(d==3){
            for(int i = H-y; i < H; i++){
                for(int j = 0; j < W; j++) p[i][j] = 1;
            }
        }
        else if(d==4){
            for(int i = 0; i < H-y; i++){
                for(int j = 0; j < W; j++) p[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(p[i][j]==0) cnt++;
        }
    }
    cout << cnt << endl;
return 0;
}
