#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int count;
    char c;
    int a[4] = {0,0,0,0};
    int b[4] = {0,0,0,0};
    int d[4] = {0,0,0,0};
    for(int i = 0; i < 4; i++){
        cin >> c;
        a[i] = int(c)-'0';
    }
    for(int i = 0; i < 4; i++){
        cin >> c;
        b[i] = int(c)-'0';
        if(a[i]==b[i]){
            d[i] = 1;
        }
        else{
            d[i] = 2;
        }
    }
    cout << d[1]*d[2]*d[3]*d[0] << endl;
    
return 0;
}
