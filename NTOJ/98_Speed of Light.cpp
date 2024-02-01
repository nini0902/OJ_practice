#include <iostream>
using namespace std;

int main(){
    long long LS,LM,LH,LD,LW,LY,c;
    c = 299792458;
    LS = c;
    LM = LS * 60;
    LH = LM * 60;
    LD = LH * 24;
    LW = LD * 7;
    LY = LD * 365;
    cout << "1 Light-second(LS) is " << LS << " metres." << endl;
    cout << "1 Light-minute(LM) is " << LM << " metres." << endl;
    cout << "1 Light-hour(LH) is " << LH << " metres." << endl;
    cout << "1 Light-day(LD) is " << LD << " metres." << endl;
    cout << "1 Light-week(LW) is " << LW << " metres." << endl;
    cout << "1 Light-year(LY) is " << LY << " metres." << endl;
return 0;
    }
