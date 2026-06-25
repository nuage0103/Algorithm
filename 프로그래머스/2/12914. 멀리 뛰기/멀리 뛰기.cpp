#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define mod 1234567

long long solution(int n) {
    long long answer = 0;
    
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(2)); // [0] 1칸, [1] 2칸
    dp[1][0] = 1; // 1
    dp[2][0] = 1, dp[2][1] = 1; // 11, 2
    
    for(int i = 3; i <= n; i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % mod;
    }
    answer = (dp[n][0] + dp[n][1]) % mod;
    return answer;
}