#include <iostream>
using namespace std;

int main(){
    int a,n;
    cin >> a;
    n = a;
    for(int i = 1; i < n/2 ; i+=2){
        a-=i*i;
        if(a==0){
            cout << (i+1)/2 << endl;
            break;
        }
        else if(a<0){
            cout << ((i+1)/2)-1 << endl;
            break;
        }
    }
return 0;
}
