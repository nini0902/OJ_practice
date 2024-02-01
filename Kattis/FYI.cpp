#include <iostream>
using namespace std;

int main(){
    char a;
    int count = 0;
    for(int i = 0; i < 3; i++){
        cin >> a;
        if((int(a)-48)==5){
            count += 1;
        }
    }
    if(count==3){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
return 0;
}
