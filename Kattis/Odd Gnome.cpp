#include <iostream>
using namespace std;

int main(){
    int n,g,a,b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> g;
        cin >> a;
        for(int j = 2; j <= g; j++){
            cin >> b;
            if(b!=(a+1)){
                cout << j << endl;
            }
            else{
                a += 1;
            }
        }
    }
return 0;
}
