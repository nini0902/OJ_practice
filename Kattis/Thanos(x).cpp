#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,d,count,n;
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> b >> c >> d;
        count = 0;
        n = log(d) / log(c);
        while(b*pow(c,n)>d){
            n -= 1;
        }
        cout << n+1 << endl;  
    }
return 0;
}
