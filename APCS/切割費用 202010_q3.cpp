//參考：https://yuihuang.com/zj-f607/
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,l;
    long long ans = 0;
    set<int> s;
    vector<pair<int,int>> p;
    cin >> n >> l;
    s.insert(0);
    s.insert(l);
    
    for(int i = 0,a,b; i < n; i++){
        cin >> a >> b;
        p.push_back({b,a}); //b是第幾刀，a是切的位置
    }
    sort(p.begin(), p.end()); //將b先排序
    
    for(auto [i,x] : p){
        s.insert(x); //把這次切的位置加入
        auto it = s.upper_bound(x); //找到第一個大於等於x的值
        auto pre = s.lower_bound(x); //找到第一個小於x的值
        //*it - *pre就會是這刀切下去的棍子長度
        if(pre != s.begin()) pre--; //如果pre不是第一個就要減一(因為減一才會是第一個小於x的值)
        ans += (*it - *pre);
    }
    cout << ans << endl;
    return 0;
}
