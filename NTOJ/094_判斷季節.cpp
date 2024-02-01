#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    int s[12] = {0,0,1,1,1,2,2,2,3,3,3,0};
    if(s[a-1]==0){
        cout << "Winter!" << endl;
    }
    else if(s[a-1]==1){
        cout << "Spring!" << endl;
    }
    else if(s[a-1]==2){
        cout << "Summer!" << endl;
    }
    else{
        cout << "Autumn!" << endl;
    }
return 0;
}
