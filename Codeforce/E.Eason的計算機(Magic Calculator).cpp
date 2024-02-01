#include <iostream>
using namespace std;

int main(){
    int q,it = 0;
    int arr[105];
    arr[0]=1;
    cin >> q;
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        if(s=="LS"){
            if(arr[0]==0) continue;
            arr[++it] = 0;
        }
        else if(s=="RS"){
            if(it==0) arr[it] = 0;
            else it--;
        }
        else{
            int x;
            cin >> x;
            arr[it] = x;
        }
    }
    for(int i = 0;i<=it;i++){
        cout << arr[i];
    }
    cout << endl;
return 0;
}
