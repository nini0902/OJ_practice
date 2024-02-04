#include <iostream>
using namespace std;

int main(){
    char n;
    int num, count = 0,a = 0, b = 0;
    while(cin >> n){
        num = n - '0';
        if(count%2==0){
            a += num;
            count += 1;
        }
        else{
            b += num;
            count += 1;
        }
    }
    if(a-b>0){
        cout << a-b << endl;
    }
    else{
        cout << (a-b)*-1 << endl;
    }
return 0;
}
