#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;

int O(int t,double m, LL n){
    LL i;
    switch(t){
        case 1:
        //從1乘到n去比第16比測資會爆
            for(i = n; i >= 2; i--){
                m /= i;
                if(m < 1) return 0;
            }
            return 1;
        case 2:
            if(m >= pow(2,n)) return 1;
            return 0;
        case 3:
            if(m >= pow(n,4)) return 1;
            return 0;
        case 4:
            if(m >= pow(n,3)) return 1;
            return 0;
        case 5:
            if(m >= pow(n,2)) return 1;
            return 0;
        case 6:
        //原本都用log，後來才發現原來有log2(以2為底的)
            if(m >= n*log2(n)) return 1;
            return 0;
        case 7:
            if(m >= n) return 1;
            return 0;
        default: 
            return 0;
    }
}

int main(){
    LL m,n,t;
    cin >> m >> n >> t;
    if(O(t,m,n)) cout << "AC" << endl;
    else cout << "TLE" << endl;
return 0;
}
