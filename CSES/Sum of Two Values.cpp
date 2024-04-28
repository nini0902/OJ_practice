#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    int n,max_index,yn = 0;
    LL x,k;
    cin >> n >> x;
    map<LL,int> m; //方便最後要找位置
    vector<LL> vec; //方便找對應數字
    set<LL> s; //去除重複 + 排序
    
    for(int i = 1; i <= n; i++){
        cin >> k;
        s.insert(k);
        m[k] = i; //紀錄位置
    } 

    vec.insert(vec.end(),s.begin(),s.end());
    max_index = vec.size()-1; //確認末位

    for(auto b : s){
        for(int i = max_index; vec[i] > b; i--){
            if(vec[i] + b == x){
                cout << m[vec[i]] << " " <<  m[b] << " ";
                max_index = m[vec[i]];
                yn = 1;
            }
        }
    }
    if(!yn) cout << "IMPOSSIBLE";
    cout << endl;
return 0;
}
