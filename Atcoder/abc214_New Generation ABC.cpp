#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    if((a>=1)&&(a<=125)){
        cout << 4 << endl;
    }
    else if((a>=126)&&(a<=211)){
        cout << 6 << endl;
    }
    else{
        cout << 8 << endl;
    }
return 0;
}
