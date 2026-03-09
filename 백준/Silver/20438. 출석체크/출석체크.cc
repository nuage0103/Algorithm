#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, q, m;
    cin >> n >> k >> q >> m;
    // 3 ~ n+2
    // -1: 못 받음, 0: 받음, 1: 졺
    vector<int> code(n + 3, -1);
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        code[x] = 1;
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if(code[x] == 1) continue; // 조는 학생

        for(int j = x; j <= n+2; j += x){
            if(code[j] == 1) continue; // 조는 학생
            code[j] = 0;
        }
    }

    vector<int> sum(n + 3);
    sum[3] = abs(code[3]);
    for(int i = 4; i <= n + 2; i++){
        sum[i] = sum[i - 1] + abs(code[i]);
    }

    while(m--){
        int st, en;
        cin >> st >> en;
        cout << sum[en] - sum[st - 1] << '\n';
    }

    return 0;
}
