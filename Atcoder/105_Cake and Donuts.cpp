#include <iostream>
using namespace std;

int main(){
    int N,t = 0,i = 0;
    cin >> N;
    if((N<7)&&(N!=4)){
        t = 0;
    }
    else{
        while(N-7*i>0){
            if((N-i*4)%7==0){
                t = 1;
                break;
            }
            if((N-7*i)%4==0){
                t = 1;
                break;
            }
            i+=1;
        }
    }
    if(t){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
return 0;
}
