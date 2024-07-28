//DP
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> f(n+1, vector<int>(n+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> f[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
            //f[a][b]表示a*b方格內的收穫總和
        }
    }

    int ans = 0;
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            for(int a = 0; a < x; a++){
                for(int b = 0; b < y; b++){
                    ans = max(ans, f[x][y] - f[a][y] - f[x][b] + f[a][b]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
