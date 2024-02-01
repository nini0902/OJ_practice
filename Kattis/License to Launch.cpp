#include <iostream>
using namespace std;

int main(){
    long long n,d,count = 0,c;
    cin >> n;
    cin >> d;
    c = d;
    for(int i = 0; i < n-1; i++){
        cin >> d;
        if(c>d){
            c = d;
            count = i+1;
        }
    }
    cout << count << endl;
return 0;
}
