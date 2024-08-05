//非原創，參考程式碼：https://yuihuang.com/zj-f581/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> pre(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        if(i==0) pre[i] = p[i];
        else pre[i] = pre[i-1]+p[i];
    }

    int s = 0;
    while(m--){
        cin >> q;
        if(s != 0) q += pre[s-1]; //不是第一筆，就加上上次的資料
        if(q > pre[n-1]) q -= pre[n-1]; //超出就減回來
        s = (lower_bound(pre.begin(), pre.end(), q) - pre.begin())+1;
        s %= n;
    }
    cout << s << endl;
    return 0;
}
