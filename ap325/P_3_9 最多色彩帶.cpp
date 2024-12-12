#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    int ans = 0, M = 0;
    map<int,int> mp;
    queue<int> q;

    //先把 queue 填到剛好l個
    for(int i = 0,c; i < l; i++){
        cin >> c;
        mp[c]++; //顏色c加一
        q.push(c); 
        if(mp[c] == 1) M++; //c只有出現一次，是新的顏色
    }
    ans = max(ans, M); //檢查第一組

    for(int i = l, c; i < n; i++){
        cin >> c;
        mp[c]++;
        if(mp[c] == 1) M++;
        q.push(c);
        
        mp[q.front()]--; //開頭丟掉的顏色減一
        if(mp[q.front()] == 0) M--; //表示區段內沒有這個顏色了
        q.pop();
        
        ans = max(ans,M);
    }
    cout << ans << endl;
    return 0;
}
