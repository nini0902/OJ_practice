#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    if(n%9==0){
        cout << n+9 << endl;
    }
    else{
        cout << 9*(n/9+1) << endl;
    }
return 0;
}
