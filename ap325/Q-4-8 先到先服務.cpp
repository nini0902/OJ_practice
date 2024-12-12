#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<LL,vector<LL>,greater<LL>> PQ;
    for(int i = 0 ; i < m; i++) PQ.push(0); //新增m個櫃台(預設都是0)

    for(int i = 0,t; i < n; i++){
        cin >> t; //第 i 位客人的服務時間
        LL s = PQ.top(); //取出最早服務完成的櫃台
        PQ.pop(); 
        s += t; //櫃台加上服務第 i 人的時間
        PQ.push(s); //把櫃台push回去
    }

    LL M = 0;
    while(!PQ.empty()){ //檢查每個櫃台
        M = max(M, PQ.top()); //找最長的
        PQ.pop();
    }

    cout << M << endl;
    return 0;
}
