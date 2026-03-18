#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    (A/B/C/D/E/F/.)(A1+)(F1+)(C1+)(A/B/C/D/E/F/.)

    0(B/C/D/E/F), 1 ~ N-2(A/F/C), N-1(A/B/C/D/E/F)
    0 ~ N-2(A/F/C), N-1(A/B/C/D/E/F)
    */
    int t;
    cin >> t;
    while(t--){
        string s; // A~Z
        cin >> s;
        int len = s.size();

        if(s[0] > 'F'){
            cout << "Good\n";
            continue;
        }

        int p = 0; // A로 시작
        if(s[0] != 'A') p = 1; // B~F로 시작

        while(s[p] == 'A') p++;

        if(p >= len || s[p] != 'F'){
            cout << "Good\n";
            continue;
        }
        while(s[p] == 'F') p++;

        if(p >= len || s[p] != 'C'){
            cout << "Good\n";
            continue;
        }
        while(p < len - 1 && s[p] == 'C') p++;

        if(s[p] > 'F') cout << "Good\n";
        else cout << "Infected!\n";
    }

    return 0;
}
