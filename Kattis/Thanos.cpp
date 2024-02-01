#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,d;
    cin >> a;
    for(int i = 0; i < a; i++){
        long long n = 0;
        cin >> b >> c >> d;
        while(b <= d){
            b *= c;
            n++;
        }
        cout << n << endl;  
    }
return 0;
}
