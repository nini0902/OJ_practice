#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long a,b,c,d;
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> b >> c;
        d = b;
        for(int j = 1; j < c; j++){
            d*=b;
        }
        if(c==0){
            cout << 1 << endl;
        }
        else{
            cout << d << endl;
        }
    }
return 0;
}
