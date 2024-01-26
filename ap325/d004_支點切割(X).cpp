//這題我沒解出來，只是先丟著說不定哪天就通了
#include <bits/stdc++.h>
using namespace std;
#define N 50010
typedef long long ll;

ll p[N];
int cnt = 0;

int bc(int c, int l,int r){ 
    long long cl = 0, cr = 0;
    for(int i = l; i < c; i++){
        cl += p[i] * abs(c-i);
    }
    for(int i = c+1; i <= r; i++){
        cr += p[i] * abs(i-c);
    }
    return abs(cl-cr);
}

int cut(int l, int r,int k){
    if(cnt==k) return 0;
    if(r-l+1<=3) return 0;
    long long m = ((l+1)+(r-1))/2;cnt += 1;
    if(bc(m,l,r)>bc(m+1,l,r)) m += 1;
    return p[m] + cut(l,m-1,k) + cut(m+1,r,k);
}

int main(){
    long long n,K;
    cin >> n >> K;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    cout << cut(0,n-1,K) << endl;
return 0;
}
