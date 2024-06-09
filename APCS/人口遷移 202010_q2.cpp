#include <bits/stdc++.h>
using namespace std;

int main(){
    int R,C,k,m;
    int po,mi = INT_MAX,M = INT_MIN,mo;
    cin >> R >> C >> k >> m;
    vector<vector<int>> c(R,vector<int>(C,0));
    vector<vector<int>> c1(R,vector<int>(C,0));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> c[i][j];
        }
    }

    while(m--){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(c[i][j] == -1) continue;
                mo = 0; //計算等一下c[i][j]要減掉出少人
                po = c[i][j] / k; //移出人口

                if(i-1 >= 0 && c[i-1][j] != -1) {c1[i-1][j] += po;mo++;}
                if(i+1 < R && c[i+1][j] != -1) {c1[i+1][j] += po;mo++;}
                if(j-1 >= 0 && c[i][j-1] != -1) {c1[i][j-1] += po;mo++;}
                if(j+1 < C && c[i][j+1] != -1) {c1[i][j+1] += po;mo++;}
                c1[i][j] -= po*mo;
            }
        }//for

        for(int i = 0; i < R; i++){ //把剛剛移動的人口加進去
            for(int j = 0; j < C; j++){
                if(c[i][j] == -1) continue;
                c[i][j] += c1[i][j];
                c1[i][j] = 0;
            }
        }//for
    }
    for(int i = 0; i < R; i++){ //找最大和最小
            for(int j = 0; j < C; j++){
                M = max(M,c[i][j]);
                if(c[i][j] == -1) continue;
                mi = min(mi, c[i][j]);
            }
        }//for
    cout << mi << endl;
    cout << M << endl;
return 0;
}
