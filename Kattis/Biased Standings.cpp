#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    long long cnt;
    string s;
    cin >> n;
    vector<int> N;
    vector<int> T;
    vector<int> ex;

    while(n--){
        cin >> k;
        //初始化
        ex.assign(k+1,0);
        N.assign(1,0);
        T.assign(1,0);
        //讀入資料
        for(int i = 0,a; i < k; i++){
            cin >> s >> a;
            if(ex[a] == 1) N.push_back(a); //紀錄多出來的期望排名
            else ex[a] = 1;
        }
        
        for(int i = 1; i <= k; i++){
            if(ex[i] == 0) T.push_back(i); //紀錄空著的排名
        }

        sort(N.begin(),N.end());
        sort(T.begin(),T.end());

        cnt = 0;
        for(int i = 0; i < N.size(); i++){
            cnt += abs(N[i] - T[i]);
        }
        cout << cnt << endl;
    }
return 0;
}
