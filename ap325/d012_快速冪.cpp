#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exp(LL x, LL y, LL p){
    if(y == 0) return 1;
    if(y & 1) return (exp(x, y-1, p)*x)%p;
    //otherwise y is even
    LL t = exp(x, y/2, p);
    return (t*t)%p;
}

int main(){
    long long x,y,p,res;
    cin >> x >> y >> p;
    res = exp(x,y,p);
    cout << res << endl;
return 0;
}
