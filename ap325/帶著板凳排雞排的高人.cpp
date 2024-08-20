#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long ans = 0;
    cin >> n;
    vector<long long> h(n+1);
    vector<long long> p(n+1);
    map<int,int> mp;
    
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> p[i];
    h[0] = LLONG_MAX, p[0] = 0;
    mp[h[0]] = 0;

    for(int i = 1; i <= n; i++){
        auto it = mp.upper_bound(h[i] + p[i]); //找到第一個符合條件的人
        ans += i - it->second - 1;

        it = mp.upper_bound(h[i]); //找到第一個比i高的人
        mp.erase(mp.begin(), it); //刪掉所有小於等於i的
        mp[h[i]] = i;
    }

    cout << ans << endl;
    return 0;
}
