#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0; // A도둑이 남긴 흔적의 누적 개수의 최솟값
    
    int k = info.size();
    // dp[i][b] = i번째까지 처리했을 때 a 최소 누적합. b(b의 누적합) < m
    vector<vector<int>> dp(k, vector<int>(m, 1e9));
    dp[0][0] = info[0][0];
    dp[0][info[0][1]] = 0;
    
    for(int i = 1; i < k; i++){
        for(int b = 0; b < m; b++){
            // a
            dp[i][b] = min(dp[i][b], dp[i - 1][b] + info[i][0]);
            // b
            int nb = b + info[i][1];
            if(nb < m) dp[i][nb] = min(dp[i][nb], dp[i - 1][b]);
        }
    }
    
    answer = n + 1;
    for(int b = 0; b < m; b++){
        answer = min(answer, dp[k - 1][b]);
    }
    if(answer >= n) answer = -1;
    return answer;
}