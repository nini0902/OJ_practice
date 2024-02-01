#include <bits/stdc++.h>
using namespace std;

int main(){
    int t = 0,a,b,h,c = 1;
    cin >> a >> b >> h;
    while(c){
        h -= a;
        t++;
        if(h<=0) c = 0;
        h += b;
    }
    cout << t << endl;
return 0;
}
