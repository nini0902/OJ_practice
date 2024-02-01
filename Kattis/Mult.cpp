#include <iostream>
using namespace std;

int main(){
   int a,b,n;
   cin >> n >> a;
   while(cin>>b){
    if(b%a==0){
        cin >> a;
        cout << b << endl;
    }
   }
return 0;
}
