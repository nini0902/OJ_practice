#include <bits/stdc++.h>
using namespace std;

int f(int x){
    if(x%10==x) return x;
    int a,b,c,d,e;
    a = x%10;
    b = (x/10)%10;
    c = (x/100)%10;
    d = (x/1000)%10;
    e = (x/10000)%10;
    
    return a+b+c+d+e;
}

int main(){
    int N,A,B,tt = 0;
    cin >> N >> A >> B;
    for(int i = 0; i <= N; i++){
        if((A<=f(i))&&(f(i)<=B)) tt += i;
    }
    cout << tt << endl;
return 0;
}
