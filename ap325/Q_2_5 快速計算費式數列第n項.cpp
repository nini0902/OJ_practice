#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL p = 1000000007;
vector<vector<LL>> f{{1,1},{1,0}};

vector<vector<LL>> mul(vector<vector<LL>> a, vector<vector<LL>> b){
    vector<vector<LL>> r(2, vector<LL>(2));
    for(int i = 0; i < 2 ;i++){
        for(int j = 0;j < 2 ;j++){
            r[i][j] = 0;
            for(int k = 0; k < 2; k++){
                r[i][j] = (r[i][j] + a[i][k] * b[k][j]%p)%p;
            }
        }
    }
    return r;
}

vector<vector<LL>> exp(vector<vector<LL>> m, LL n){
    if(n == 1) return m;
    if(n & 1) return mul(m, exp(mul(m,m), n/2));
    else return exp(mul(m,m), n/2);
}

LL fib(LL n){
    if (n == 0) return 0;
    vector<vector<LL>> fn = exp(f,n-1);
    return fn[0][0];
}

int main(){
    LL n = 0;
    while(1){
        cin >> n;
        if(n==-1) break;
        cout << fib(n) << endl;
    }
return 0;
}
