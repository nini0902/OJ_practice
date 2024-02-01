#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,a = 0,b,count = 0;
    vector<int> c;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> b;
        if(b>a){
            c.push_back(b);
            a = b;
            count += 1;
        }
    }
    cout << count << endl;
    for(int i = 0; i < count; i++){
        cout << c[i] << " ";
    }
    cout << endl;
return 0;
}
