#include <bits/stdc++.h>
using namespace std;
map<int, pair<int,int>> mp;
int a[5][5] = {0};

int check(int n){
    int ans = 0, sum;
    int x = mp[n].first, y = mp[n].second;
    //是否連成一直行
    sum = a[0][y] + a[1][y] + a[2][y] + a[3][y] + a[4][y];
    if(sum == 4) ans ++;
    //是否連成一橫列
    sum = a[x][0] + a[x][1] + a[x][2] + a[x][3] + a[x][4];
    if(sum == 4) ans ++;
    //是否連成左上右下對角線
    if(x == y){
        sum = a[0][0] + a[1][1] + a[2][2] + a[3][3] + a[4][4];
        if(sum == 4) ans ++;
    }
    //是否連成左下右上對角線
    if(x+y == 4){
        sum = a[0][4] + a[1][3] + a[2][2] + a[3][1] + a[4][0];
        if(sum == 4) ans ++;
    }
    return ans;
}

int main(){
    int x;
    set<int> s;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> x;
            mp[x] = {i,j};   
            s.insert(x);
        }
    }

    cin >> x;
    while(x != -1){
        a[mp[x].first][mp[x].second] = 1;
        s.erase(x);
        cin >> x;
    }

    int score = -1, ans;
    for(auto i : s){
        int x = check(i);
        if(x > score) score = x, ans = i;
    }

    cout << ans << endl;
return 0;
}
