#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d, p;
    cin >> d >> p;
    vector<int> dp(d + 1); // dp[i] = 길이 i, 최대(최소(모든 구성 요소))
    dp[0] = 1e9;
    while(p--){
        int len, cap;
        cin >> len >> cap;
        for(int x = d; x >= len; x--){
            dp[x] = max(dp[x], min(dp[x - len], cap));
        }
    }
    cout << dp[d] << '\n';

    return 0;
}
