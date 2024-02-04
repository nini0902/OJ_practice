#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c;
    vector<int> abc(3,0);
    for(int i = 0; i < 3; i++){
        cin >> abc[i];
    }
    sort(abc.begin(),abc.end());
    for(int i = 0; i < 3; i++){
        cout << abc[i] << " ";
    }
    cout << endl;
    a = abc[0];
    b = abc[1];
    c = abc[2];
    if(a+b<=c){
        cout << "No" << endl;
    }
    else if(a*a+b*b<c*c){
        cout << "Obtuse" << endl;
    }
    else if(a*a+b*b==c*c){
        cout << "Right" << endl;
    }
    else if(a*a+b*b>c*c){
        cout << "Acute" << endl;
    }

return 0;
}
