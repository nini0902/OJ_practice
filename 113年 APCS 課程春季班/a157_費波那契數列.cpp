#include <bits/stdc++.h>
using namespace std;

//計算費波那契數列
int fac(int n){
    if(n == 0) return 0;
    if(n <= 2) return 1;
    else{
        return fac(n-1) + fac(n-2); //前兩數相加
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << fac(n) << endl;
    }
return 0;
}
