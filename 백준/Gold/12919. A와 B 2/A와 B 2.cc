#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check = false;

void find_s(string s, string t){
    if(s == t){
        check = true;
        return;
    }
    if(s.length() > t.length()) return;

    int len = t.length();
    if(t[len-1] == 'A'){
        string tmp = t.substr(0, len-1);
        find_s(s, tmp);
    }
    if(t[0] == 'B'){
        string tmp = t.substr(1);
        reverse(tmp.begin(), tmp.end());
        find_s(s, tmp);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    find_s(s, t);

    if(check) cout << "1\n";
    else cout << "0\n";

    return 0;
}
