#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graph(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    dp[1][1] = 1;
    for(int x=1; x<=n; x++){
        for(int y=1; y<=n; y++){
            if(!graph[x][y]) continue;
            if(x == n && y == n) continue;

            int move = graph[x][y];
            int nx = x + move;
            int ny = y + move;
            if(nx <= n) dp[nx][y] += dp[x][y];
            if(ny <= n) dp[x][ny] += dp[x][y];
        }
    }
    cout << dp[n][n]<< '\n';

    return 0;
}
