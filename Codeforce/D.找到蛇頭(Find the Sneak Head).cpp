#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin >> n;
    vector<vector<int>> S(n+1,vector<int>(n+1,0));
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            cin >> a >> b;
            S[a][b] = 1;
        }
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= n; j++){
            if(S[i][j]==0){
                cout << i << " " << j << endl;
                break;
            }     
        }
    }
    return 0;
}
