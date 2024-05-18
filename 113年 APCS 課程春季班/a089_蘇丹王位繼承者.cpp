#include <bits/stdc++.h>
#define QSIZE 8
using namespace std;
int Q[QSIZE], ans, G[QSIZE][QSIZE];

bool collide(int r, int c){
    for(int i = 0; i < r; i++){
        //確認這個位置(r,c)會不會被其他皇后攻擊
        if(c==Q[i] || abs(r-i)==abs(c-Q[i])) return true;
        //確認方式1 如果這條c有沒有其他Queen
        //確認方式2 如果這個位置和某個Queen的x,y軸差距相同(斜對角)
    }
    return false;
}

void Queen(int r){
    if(r == QSIZE){
        int sum = 0;
        //計算皇后位置數字的總和
        for(int i = 0; i < QSIZE; i++){
            sum += G[i][Q[i]];
        }
        if(sum > ans) ans = sum; //如果更大就更新資料
        return;
    }
    for(int i = 0; i < QSIZE; i++){
        if(collide(r,i)) continue; //這個位置會被攻擊
        Q[r] = i;
        Queen(r+1);
    }
    return;
}

int main(){
    int k;
    cin >> k;
    while(k--){
      //讀入資料
        for(int i = 0; i < QSIZE; i++){
            for(int j = 0; j < QSIZE; j++){
                cin >> G[i][j];
            }
        }
        ans = 0;
        Queen(0);
        cout << ans << endl;
    }
    return 0;
}
