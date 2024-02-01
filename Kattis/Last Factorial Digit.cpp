#include <iostream>
using namespace std;

int main(){
    int N,a,b = 1;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;
        b = 1;
        for(int j = 1; j <= a; j++){
            b *= j;
        }
        cout << b%10 << endl;
    }
return 0;
}
