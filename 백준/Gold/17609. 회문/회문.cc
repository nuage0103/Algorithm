#include<bits/stdc++.h>
using namespace std;

// 0 회문, 1 유사회문, 2 일반
int solve(string s, int l, int r, int pass){
    while(l <= r){
        if(s[l] == s[r]){
            l++;
            r--;
        }
        else{
            if(pass > 0) return 2;

            if(solve(s, l+1, r, 1) == 0 || solve(s, l, r-1, 1) == 0) return 1;
            else return 2;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << solve(s, 0, s.length()-1, 0) << '\n';
    }

    return 0;
}
