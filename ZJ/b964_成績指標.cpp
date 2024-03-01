#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, sc;
    cin >> n;
    vector<int> sh;
    vector<int> sl;
    
    for(int i = 0; i < n; i++){
        cin >> sc;
        if(sc < 60) sl.push_back(sc);
        else sh.push_back(sc);
    }

    sort(sh.begin(),sh.end());
    sort(sl.begin(),sl.end());

    for(int i = 0; i < sl.size(); i++) cout << sl[i] << " ";
    for(int i = 0; i < sh.size(); i++) cout << sh[i] << " ";
    cout << endl;

    if(sh.size()==0){
        cout << sl[sl.size()-1] << endl;
        cout << "worst case" << endl;
    }
    else if(sl.size()==0){
        cout << "best case" << endl;
        cout << sh[0] << endl;
    }
    else{
        cout << sl[sl.size()-1] << endl;
        cout << sh[0] << endl;
    }

return 0;
}
