#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> dp(n); // dp[i] = inp[0] ~ inp[i] 까지 합
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
        dp[i] = sum;
    }
    cin >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        if(i) cout << dp[j] - dp[i - 1] << '\n';
        else cout << dp[j] << '\n';
    }

    return 0;
}
