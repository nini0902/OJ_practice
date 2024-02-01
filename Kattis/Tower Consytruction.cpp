#include <iostream>
using namespace std;

int main(){
    long long N,count = 1,a = 1000000,b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> b;
        if(b<=a){
            a = b;
        }
        else{
            count += 1;
            a = b;
        }
    }
    cout << count << endl;
return 0;
}
