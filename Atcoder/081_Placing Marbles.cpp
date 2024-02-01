#include <iostream>
using namespace std;

int main(){
    char a;
    int count = 0;
    for(int i = 0; i < 3; i++){
        cin >> a;
        if(int(a)-48==1){
            count += 1;
        }
    }
    cout << count << endl;
return 0;
}
