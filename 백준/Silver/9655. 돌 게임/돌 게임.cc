#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // dp[i]: i개 가져갈때까지 최소 회차, dp[i-1]+1, dp[i-3]+1
    vector<int> dp(1001);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;

    for(int i=4; i<=n; i++){
        dp[i] = min(dp[i-1]+1, dp[i-3]+1);
    }
    if(dp[n]%2) cout << "SK\n";
    else cout << "CY\n";

    return 0;
}
