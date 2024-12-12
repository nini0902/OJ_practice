#include <bits/stdc++.h>
using namespace std;

int n,P,m = 0;
long long A[26];

void clo(int i,int p){
    if(i>=n){
        if((p>m)&&(p<P)){
            m = p;
        }
        return;
    }
    clo(i+1,p+A[i]);
    clo(i+1,p);
}

int main(){
    cin >> n >> P;
    for(int i = 0; i < n;i++) cin >> A[i];
    clo(0,0);
    cout << m << endl;
    return 0;
}
