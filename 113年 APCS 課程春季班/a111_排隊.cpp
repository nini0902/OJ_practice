#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,time = 0,ans = 0;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    for(int i = 0; i < n; i++){
        //如果要等，則總服務時間要整個加上去
        if(time >= v[i].first) time += v[i].second;
        //不用等就是來的時間加服務時間
        else time = v[i].first + v[i].second;

        int wait = 0;
        //計算最常等了幾個人
        for(int j = i+1; j < n && v[j].first <= time; j++) wait += 1;

        ans = max(wait,ans);
    }
    cout << ans << endl;
return 0;
}
