#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    if(a >= 90){
        cout << "expert" << endl;
    }
    else if(a < 40){
        cout << 40-a << endl;
    }
    else if(a<70){
        cout << 70-a << endl;
    }
    else if(a<90){
        cout << 90-a << endl;
    }
return 0;
}
