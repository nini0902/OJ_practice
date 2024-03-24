#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> a(r+1,vector<int>(c+1,0));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            a[i][0] += a[i][j];
        }
    }

    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= r; j++){
            a[0][i] += a[j][i];
        }
    }

    for(int i = 1; i <=r; i++){
        for(int j = 1; j <= c; j++){
            cout << a[i][0] + a[0][j] - a[i][j] << " ";
        }
        cout << endl;
    }
return 0;
}
