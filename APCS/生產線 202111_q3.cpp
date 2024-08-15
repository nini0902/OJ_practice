#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b){
    if(a > b) return true;
    return false;
}

int main(){
    int n,m;
    long long ans = 0;
    cin >> n >> m;
    vector<long long> pos(n,0);
    vector<long long> mac(n);

    int l,r,w;
    for(int i = 0; i < m; i++){
        cin >> l >> r >> w;
        pos[l-1] += w;
        pos[r] -= w;
    }

    for(int i = 1; i < n; i++) pos[i] += pos[i-1];
    for(int i = 0; i < n; i++) cin >> mac[i];

    sort(mac.begin(), mac.end()); //製作產品時間小到大排列
    sort(pos.begin(), pos.end(),comp); //製作商品量大到小排列

    for(int i = 0; i < n; i++){
        ans += pos[i] * mac[i];
    }
    
    cout << ans << endl;
    return 0;
}
