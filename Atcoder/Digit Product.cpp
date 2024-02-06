#include <bits/stdc++.h>
using namespace std;

int d(int x){
    int a,b,c;
    if(x%10==x) return x;

    if(x/100==0) a = 1;
    else a = x/100;
    if((x/10)%10==0) b = 1;
    else b = (x/10)%10;
    if(x%10==0) c = 1;
    else c = x%10;

    return d(a*b*c);
}

int main(){
    int x;
    cin >> x;
    cout << d(x) << endl;
return 0;
}
