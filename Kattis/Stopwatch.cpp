#include <iostream>
using namespace std;

int main(){
    int N,a,b,count = 0,t = 0;
    cin >> N;
    if(N%2!=0){
        t = 0;
    }
    else{
        t = 1;
        for(int i = 0; i < N/2; i++){
            cin >> a >> b;
            count += (b-a);
        }
    }
    if(t){
        cout << count << endl;
    }
    else{
        cout << "still running" << endl;
    }
return 0;
}
