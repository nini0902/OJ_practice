#include <iostream>
using namespace std;

int main(){
    long long n,a,x,y;
    cin >> n >> a >> x >> y;
    if(n <= a){
        cout << n*x << endl;
    }
    else{
        cout << x*a+(n-a)*y << endl;
    }
return 0;
}
