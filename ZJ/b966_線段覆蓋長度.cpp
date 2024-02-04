#include <iostream>
#include <vector>
using namespace std;

void resize_len(int n, vector<int>& len){
    len.resize(n+1,0);
}
int main(){
    vector<int> len;
    int l;
    cin >> l;
    int start;
    int end;
    int max = 0;
    int sum = 0;
    while(cin >> start >> end){
        if(end>max){
            max = end;
            resize_len(max,len);
        }
        for(int i = start+1; i<=end;i++){
            len[i] = 1;
        }
    }
    for(int i = 0; i <= max;i++){
        if(len[i]==1){
            sum += 1;
        }
    }
    cout << sum << endl;
return 0;
}
