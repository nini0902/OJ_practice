#include <iostream>
using namespace std;

int main(){
    long long n,p,x,y;
    cin >> n >> p >> x >> y;
    //每n個一組，其中"我"會講n-1頁，求出的組數就是喵念的頁數
    cout << p*x+p/(n-1)*y << endl; 
return 0;
}
