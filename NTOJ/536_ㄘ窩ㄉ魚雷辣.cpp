#include <iostream>
using namespace std;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if((a<=c)&&(c<=b)){
        cout <<"yes" << endl;
    }
    else if((a<=d)&&(d<=b)){
        cout << "yes" << endl;
    }
    else if(((c<=a)&&(d>=a))||((c<=b)&&(d>+b))){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
return 0;
}
