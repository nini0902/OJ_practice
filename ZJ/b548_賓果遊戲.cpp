#include <bits/stdc++.h>
#define N 100
using namespace std;
int n;
char na[N] = {0}, l[N][10] = {0};
pair<int,int> mp[N][17];

bool check(int i, int p){
    int r = mp[i][p].first;
    int c = mp[i][p].second;
    l[i][r]++; //該列機率+1
    if(l[i][r] == 4) return true;
    l[i][c+4]++; //該行機率+1
    if(l[i][c+4] == 4) return true;
    if((r+c) == 3){
        l[i][8]++;
        if(l[i][8] == 4) return true;
    }
    if(r==c){
        l[i][9]++;
        if(l[i][9] == 4) return true;
    }
    return false;
}

int main(){
    char ch;
    int v;
    cin >> ch >> n;
    for(int i = 0; i < n; i++){
        cin >> na[i];
        for(int j = 0; j < 16; j++){
            cin >> v;
            mp[i][v] = {j/4,j%4};
        }
    }

    char cp;
    int p, cnt = 16;
    bool s = false;
    cin >> cp;
    while(cnt--){
        cin >> p;
        cout << p << " ";
        for(int i = 0; i < n; i++){
            if(check(i,p)){
                cout << na[i] << " ";
                s = true;
            }
        }
        if(s) return 0;
    }
return 0;
}
