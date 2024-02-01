#include <iostream>
#include <vector>
using namespace std;

int main(){
    int A,B,C,D,count = 0;
    cin >> A >> B >> C >> D;
    vector<int> f(100,0);
    vector<int> s(100,0);
    for(int i = A; i <= B; i++){
        f[i]=1;
    }
    for(int i = C; i <= D; i++){
        s[i]=1;
    }
    for(int i = 0; i < 101; i++){
        if((f[i]==s[i])&&(f[i]==1)){
            count += 1;
        }
    }
    if(count==0){
        cout << 0 << endl;
    }
    else{
        cout << count-1 << endl;
    }
return 0;
}
