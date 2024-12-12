#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long P = 10009, A[26];

void rec(int i,int prod){
    if(i>=n){
        if(prod==1) ans++;
        return;
    }
    rec(i+1,(prod * A[i])%P);
    rec(i+1, prod);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    rec(0,1);
    cout << ans-1 << endl;
return 0;
}
