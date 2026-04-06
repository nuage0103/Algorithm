#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1000001
int n;
vector<vector<int>> adj;
int dp[MAX_N][2]; // [i][1]: i가 얼리인 경우, [i][0]: i가 얼리 아닌 경우 최소 얼리 개수
int visited[MAX_N];

void dfs(int x){
    visited[x] = 1;
    dp[x][1] = 1;
    dp[x][0] = 0;
    for(auto nx: adj[x]){
        if(visited[nx]) continue;

        dfs(nx);
        dp[x][1] += min(dp[nx][0], dp[nx][1]);
        dp[x][0] += dp[nx][1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    adj.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(visited, visited + n + 1, 0);
    dfs(1);
    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
