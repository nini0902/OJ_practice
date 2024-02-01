#include <iostream>
using namespace std;

int main(){
    int N,P,s,count = 0;
    cin >> N >> P;
    for(int i = 0; i < N;i++){
        cin >> s;
        if(s<P){
            count += 1;
        }
    }
    cout << count << endl;
return 0;
}
