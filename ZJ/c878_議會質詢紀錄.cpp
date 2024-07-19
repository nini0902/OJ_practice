#include <bits/stdc++.h>
using namespace std;
long long a[2][3] = {0};
int mod = 100000007;

void cnt_n(int n){
    a[0][0] = 1;
    for(int i = 1; i <= n; i++){
        long long b[2][3] = {};
        b[0][0] = (a[0][0] + a[0][1] + a[0][2]) % mod;
        b[1][0] = (a[0][0] + a[0][1] + a[0][2] + a[1][0] + a[1][1] + a[1][2]) % mod;
        b[1][1] = a[1][0];
        b[0][1] = a[0][0];
        b[1][2] = a[1][1];
        b[0][2] = a[0][1];
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 3; k++){
                a[j][k] = b[j][k];
            }
        }
    }
    long long tt = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            tt += a[i][j];
            tt %= mod;
        }
    }
    cout << tt << endl;
}

int main(){
    int n;
    cin >> n;
    cnt_n(n);
    return 0;
}
