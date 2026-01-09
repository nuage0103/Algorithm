#include <bits/stdc++.h>
using namespace std;

int n;
string src, dst;
int min_cnt;

void solve(int flag){
    string ns = src;
    int cnt = 0;

    if(flag){
        ns[0] = (ns[0] == '0')? '1' : '0';
        ns[1] = (ns[1] == '0')? '1' : '0';
        cnt++;
    }

    for(int i = 1; i < n; i++){
        if(ns[i-1] == dst[i-1]) continue;

        ns[i-1] = (ns[i-1] == '0')? '1' : '0';
        ns[i] = (ns[i] == '0')? '1' : '0';
        if(i != n-1) ns[i+1] = (ns[i+1] == '0')? '1' : '0';
        cnt++;
    }

    if(ns == dst) min_cnt = min(min_cnt, cnt);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> src >> dst;

    if(n == 1){
        if(src == dst) cout << "0\n";
        else cout << "1\n";

        return 0;
    }

    min_cnt = 1e9;
    solve(0);
    solve(1);
    if(min_cnt == 1e9) cout << "-1\n";
    else cout << min_cnt << '\n';

    return 0;
}
