#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0, M = 0;
    map<int,int> mp;
    queue<int> q;

    for(int i = 0,c; i < n; i++){
        cin >> c;
        mp[c]++; //該顏色加一
        M++;
        q.push(c);

        while(!q.empty() && mp[c] > 1){ //調整區間(直到顏色i只出現一次)
            mp[q.front()]--;
            q.pop();
            M--;//長度--
        }

        ans = max(M, ans); //計算目前長度
    }

    cout << ans << endl;

    return 0;
}
