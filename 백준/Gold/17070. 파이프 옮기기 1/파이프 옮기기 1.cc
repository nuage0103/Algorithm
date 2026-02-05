#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }

    vector<vector<vector<int>>> dp;
    dp.resize(3, vector<vector<int>>(n, vector<int>(n, 0)));
    //[dir][x][y] x,y는 끝점
    dp[0][0][1] = 1;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if(graph[x][y]) continue;

            //가로
            if(y-1 >= 0 && !graph[x][y]){
                dp[0][x][y] += dp[0][x][y-1] + dp[2][x][y-1];
            }
            //세로
            if(x-1 >= 0 && !graph[x][y]){
                dp[1][x][y] += dp[1][x-1][y] + dp[2][x-1][y];
            }
            //대각
            if(x-1 >= 0 && y-1 >= 0 && !graph[x][y]){
                if(graph[x][y-1] || graph[x-1][y]) continue;
                dp[2][x][y] += dp[0][x-1][y-1] + dp[1][x-1][y-1] + dp[2][x-1][y-1];
            }
        }
    }

    cout << dp[0][n-1][n-1] + dp[1][n-1][n-1] + dp[2][n-1][n-1] << '\n';

    return 0;
}
