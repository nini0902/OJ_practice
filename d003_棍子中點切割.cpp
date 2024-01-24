#include <bits/stdc++.h>
#define N 50010
using namespace std;
typedef long long ll;

ll p[N];

ll cut(int l,int r){
    if(r-l<=1) return 0;
    ll len = p[r]-p[l],k = (p[r]+p[l])/2;
    ll m = l;
    while(p[m]<k) m++;
    if(p[m-1]-p[l] >= p[r]-p[m]) m --;
    return len + cut(l,m) + cut(m,r);
}

int main(){
    int n,l,t;
    cin >> n >> l;
    p[0] = 0,p[n+1] = l;
    for(int i = 1; i <=n; i++){
        cin >> t;
        p[i] = t;
    }
    cout << cut(0,n+1) << endl;
return 0;
}
