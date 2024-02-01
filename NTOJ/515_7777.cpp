#include <iostream>
using namespace std;

int main(){
    long long a;
    cin >> a;
    if((a>9999)||(a<1111)){
        cout << "OAQ" << endl;
    }
    else if(a%1111==0){
        cout << "GREAT!!" << endl;
    }
    else{
        cout << "OAQ" << endl;
    }
return 0;
}
