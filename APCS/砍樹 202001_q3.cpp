#include <bits/stdc++.h>
#define pos first
#define h second
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,l;
    cin >> n >> l;
    vector<pair<int,int>> t(n+2);
    vector<vector<int>> pnt(n+2,vector<int>(2)); //用來記錄前後最近的樹

    for(int i = 1; i <= n; i++) cin >> t[i].pos;
    for(int i = 1; i <= n; i++) cin >> t[i].h;

    //設定邊界
    t[0] = {1,0};
    t[n+1] = {l,0};

    for(int i = 0; i <= n+1; i++){
        pnt[i][0] = i-1;
        pnt[i][1] = i+1;
    }

    int maxh = 0, now = 1, cnt = 0;
    while(now <= n){
        int p = t[now].pos, hi = t[now].h;
        int lt = pnt[now][0], nt = pnt[now][1]; //now的上一棵樹和下一棵樹
        if((p-hi >= t[lt].pos) || (p+hi <= t[nt].pos)){
            cnt++;
            maxh = max(maxh, hi);
            pnt[lt][1] = pnt[now][1]; //上一棵樹的下一棵從now變成now的下一棵
            pnt[nt][0] = pnt[now][0]; //下一棵樹的上一棵從now變成now的上一棵

            if(pnt[now][0] != 0) now = pnt[now][0]; //如果now前面還有樹，now往前推
            else now = pnt[now][1]; //否則就只能往後找了
        }
        else now = pnt[now][1];
        if(now > n) break; //已經檢查到最後了
    }
    cout << cnt << endl;
    cout << maxh << endl;
    return 0;
}
