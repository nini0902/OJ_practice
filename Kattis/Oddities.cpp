#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a;
    while(cin >> b){
        if(b%2==0){
            cout << b << " is even" << endl;
        }
        else{
            cout << b << " is odd" << endl;
        }
    }
return 0;
}
