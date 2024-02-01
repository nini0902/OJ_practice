#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> X;
    int num,a = -1000000,b = 1000000,n,count = 0;
    while(cin >> n){
        count += 1;
        for(int i = 0; i < n; i++){
            cin >> num;
            a = max(a,num);
            b = min(b,num);
        }
        cout << "Case " << count << ": " <<b << " " << a << " " << a-b << endl;
        a = -1000000;
        b = 1000000;
    }   
return 0;
}
