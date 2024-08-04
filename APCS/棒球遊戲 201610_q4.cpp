//非原創，程式碼來源：113APCS春季班
#include <bits/stdc++.h>
using namespace std;
map<int,queue<string>> mp;

int main(){
    int a,b;
    for(int i = 0; i < 9; i++){
        cin >> a;
        string s;
        while(a--){
            cin >> s;
            mp[i].push(s);
        }
    }
    cin >> b; //紀錄b出局時遊戲結束

    int out = 0;
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    int score = 0;
    int n = -1; //打者號碼
    while(1){
        int t = 0;
        n = (n+1)%9;
        string hit = mp[n].front(); //hit為該打者這次的打擊結果
        mp[n].pop();
        if(hit == "SO" || hit == "GO" || hit == "FO"){
            out++;
            if(out == b) break; //遊戲結束
            if(out % 3 == 0){ //三出局，清壘
                b1 = 0, b2 = 0, b3 = 0, b4 = 0;
                continue;
            }
        }
        else if(hit == "HR") t = 4;
        else t = hit[0] - '0';

        for(int i = 1; i <= t; i++){
            b4 = b3;
            b3 = b2;
            b2 = b1;
            if(i == 1) b1 = 1; //一壘有人
            else b1 = 0; //一壘沒人(跑到二壘以上去了)
            if(b4 == 1) score++; //跑回本壘
        }
    }
    cout << score << endl;
    return 0;
}
