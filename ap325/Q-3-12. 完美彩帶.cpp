#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    int ans = 0, tt = 0;
    cin >> m >> n;
    queue<int> q;
    map<int, int> mp;

    for(int i = 0,c; i < n; i++){
        cin >> c;
        mp[c]++;
        q.push(c);

        if(mp[c] == 1) tt++; //新的顏色

        while(!q.empty() && mp[c] > 1){ //調整區間
            mp[q.front()]--;
            if(mp[q.front()] == 0) tt--; //顏色變少了
            q.pop();
        }

        if(tt == m) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
