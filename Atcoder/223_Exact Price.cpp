#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    if((a>=100)&&(a%100==0)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
return 0;
}
