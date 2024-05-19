#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,cnt = 0;
    cin >> a >> b;

    while(a != b){
        if((a%2!=0) || (a < b)) {cnt++;a++;}
        else {a/=2;cnt++;} 
    }
    cout << cnt << endl;
return 0;
}
