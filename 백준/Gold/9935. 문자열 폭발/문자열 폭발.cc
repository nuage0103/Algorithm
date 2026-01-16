#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    int t_len = t.length();
    char last = t[t_len-1];
    string res = "";
    for(int i=0; i<s.length(); i++){
        res += s[i];
        if(res.length() < t_len) continue;

        if(s[i] == last){
            bool flag = true;
            int len = res.length();
            for(int j=0; j<t_len; j++){
                if(res[len-t_len+j] != t[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) res.resize(len - t_len);
        }
    }

    if(res.length()) cout << res << '\n';
    else cout << "FRULA\n";

    return 0;
}
