//非原創，程式碼解法參考：https://yuihuang.com/zj-b967/
#include <bits/stdc++.h>
using namespace std;
vector<int> f[100005];
int rel[100005];

void dfs(int now, int pre){
    for(auto i : f[now]){
        if(i != pre){ //pre避免無線循環(因為f紀錄的是雙向的關係)
            rel[i] = rel[now]+1;
            dfs(i,now);
        }
    }
}

int main(){
    int n,p,k,M = 0,d;
    cin >> n;
    for(int i = 0; i < n; i++){
        f[i].clear();
        rel[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cin >> p >> k;
        f[p].push_back(k); //建立雙向的連結
        f[k].push_back(p);
    }
    dfs(0,-1); //-1是因為沒有前一個，所以找完就可以跳出來了
    for(int i = 0; i < n; i++){
        if(rel[i] > M) {M = rel[i];d = i;} //d要儲存最底下的人
        rel[i] = 0; //rel要重置，第二次DFS才不會有問題
    }
    dfs(d,-1);
    for(int i = 0; i < n; i++){
        if(rel[i] > M) M = rel[i];
    }
    cout << M << endl;
    return 0;
}
