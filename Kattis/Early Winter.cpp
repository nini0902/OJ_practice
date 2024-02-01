#include <iostream>
using namespace std;

int main(){
    int n,d,d1,count = 0,n1;
    cin >> n >> d;
    n1 = n;
    while(n > 0){
        n-=1;
        cin >> d1;
        if(d1>d){
            count += 1;
            if(count==n1){
                count = -1;
            }
            else if(n==0){
                count -= 1;
            }
        }
        else{
            break;
        }
    }
    if(count >= 0){
        cout << "It hadn't snowed this early in " << count << " years!" << endl;
    }
    else{
        cout << "It had never snowed this early!" << endl;
    }
return 0;
}
