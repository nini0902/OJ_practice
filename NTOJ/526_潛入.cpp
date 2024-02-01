#include <iostream>
#include <vector>
using namespace std;

int main(){
    char a;
    int num,count = 0;
    vector<int> b(1,1);
    while(cin >> a){
        num = int(a)-48;
        count += 1;
        b.push_back(num);
    }
    if((b[3]==0)&&b[2]==0){
        cout << b[1] << endl;
    }
    else if(b[3]!=0){
        cout << b[3] << b[2] << b[1] << endl;
    }
    else{
        cout << b[2] << b[1] << endl;
    }
return 0;
}
