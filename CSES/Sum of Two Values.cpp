#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
    int n,max_index,yn = 0;
    LL x,k;
    cin >> n >> x;
    map<LL,int> m;
    vector<LL> vec;
    set<LL> s;

    for(int i = 1; i <= n; i++){
        cin >> k;
        s.insert(k);
        m[k] = i;
    } 

    vec.insert(vec.end(),s.begin(),s.end());
    max_index = n;

    for(auto b : s){
        if(max_index <= b) break;
        for(int i = max_index; i > b; i--){
            if(vec[i] == abs(x-b)) cout << m[vec[i]] << " " <<  m[b] << " ";
            max_index = i;
            yn = 1;
        }
    }
    if(!yn) cout << "IMPOSSIBLE";
    cout << endl;
return 0;
}
