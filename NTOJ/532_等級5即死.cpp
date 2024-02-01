#include <iostream>
using namespace std;

int main(){
    int a,b,count,count1;
    cin >> a >> b;
    if(a%2==0){
        count+=1;
    }
    if(b%2==0){
        count+=1;
    }
    if(a%3==0){
        count1 += 1;
    }
    if(b%3==0){
        count1 += 1;
    }
    cout << count << " " << count1 << endl;
return 0;
}
