#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> t(n,vector<int>(n,0));

int main(){
    int m;
    cin >> n;
    for(int i = 1; i < n+1; i++){
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> t[i][j];
        }
    }
    
return 0;
}