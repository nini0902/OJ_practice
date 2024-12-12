#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exp(LL x, LL y, LL p){
    if(y==0) return 1;
    LL t = exp(x,y/2,p);
    if(y & 1) return (t*t%p)*x%p;
    return (t*t)%p;
}

int main(){
    string n;
    LL y,p,r = 0;
    cin >> n >> y >> p;
    for(char d : n) r = (r*10+(d-'0'))%p;

    cout << exp(r,y,p) << endl;
    return 0;
}
