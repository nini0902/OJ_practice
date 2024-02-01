#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if(max(a,b)!=a){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
return 0;
}
