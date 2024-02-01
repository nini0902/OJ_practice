#include <iostream>
using namespace std;

int main(){
    int N,M,p,v = 0,tt = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> p;
        if((N-v)>=p){
            v += p;
        }
        else{
            tt += 1;
        }
    }
    cout << tt << endl;
return 0;
}
