#include <iostream>
using namespace std;

int main(){
    int N,a,b;
    cin >> N;
    cin >> a;
    for(int i = 0; i < N-1; i++){
        cin >> b;
        a += b;
        a-=1;
    }
    cout << a << endl;
return 0;
}
