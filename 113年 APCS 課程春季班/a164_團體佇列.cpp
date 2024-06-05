#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,c = 0;
    while(cin >> t){
        if(t == 0) break;
        map<int, int> mp;
        for(int i = 0, n, x; i < t; i++){
            cin >> n;
            while(n--){
                cin >> x;
                mp[x] = i;
            }
        }
        queue<int> Q;
        queue<int> t[1000];
        string cmd;
        cout << "Scenario #" << ++c << endl;
        while(cin >> cmd){
            int x;
            if(cmd[0]=='E'){ //排進去
                cin >> x;
                if(t[mp[x]].empty()) Q.push(mp[x]);
                t[mp[x]].push(x);
            }
            else if(cmd[0]=='D'){ //把最前面的元素丟出來，然後pop掉他
                int team = Q.front();
                cout << t[team].front() << endl;
                t[team].pop();
                if(t[team].empty()) Q.pop();
            }
            else if(cmd[0]=='S'){
                cout << endl;
                break;
            }
        }
    }
return 0;
}
