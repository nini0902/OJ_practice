#include <iostream>
using namespace std;

int main(){
    int y;
    cin >> y;
    if(y%4==0){
        if(y%100!=0){
            cout << "YES" << endl;
        }
        else{
            if(y%400==0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    else{
        cout << "NO" << endl;
    }
return 0;
}
