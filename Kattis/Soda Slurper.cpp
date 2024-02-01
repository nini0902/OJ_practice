#include <iostream>
using namespace std;

int main(){
    int a,b,c,tt,t,count = 0;
    cin >> a >> b >> c;
    tt = a+b;
    while(tt>=c){
        count += tt/c;
        t = tt/c;
        tt%=c;
        tt += t;
    }
    cout << count << endl;
return 0;
}
