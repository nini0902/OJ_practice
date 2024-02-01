#include <iostream>
using namespace std;

int main(){
    int N,c = 0;
    cin >> N;
    for(int i = 1; i < 10; i++){
        if((N%i==0)&&(N/i<10)){
            cout << "Yes" << endl;
            c = 1;
            break;
        }
    }
    if(c == 0){
        cout << "No" << endl;
    }
return 0;
}
