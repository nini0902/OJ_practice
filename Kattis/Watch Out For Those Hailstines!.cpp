#include <iostream>
using namespace std;

int main(){
    long long n,count = 0;
    cin >> n;
    count = n;
    while(n!=1){
        if(n%2==0){
            n/=2;
        }
        else{
            n = n*3+1;
        }
        count += n;
    }
    cout << count << endl; 
return 0;
}
