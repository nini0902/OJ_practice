#include <iostream>
using namespace std;

int main(){
    long long N,e,tt = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> e;
        if(e<0){
            tt -= e;
        }
    }
    cout << tt << endl;
return 0;
}
