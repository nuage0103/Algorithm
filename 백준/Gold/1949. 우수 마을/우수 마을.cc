#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> ppl;
int dp[10001][2]; // dp[i][1]: i가 우수, dp[i][0]: i 우수 아닌 경우에 최대 주민 총합
int visited[10001];

void dfs(int x){
    visited[x] = 1;
    dp[x][1] = ppl[x];
    dp[x][0] = 0;
    for(auto nx: adj[x]){
        if(visited[nx]) continue;

        dfs(nx);

        dp[x][1] += dp[nx][0];
        dp[x][0] += max(dp[nx][0], dp[nx][1]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ppl.resize(n + 1);
    adj.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ppl[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << max(dp[1][1], dp[1][0]) << '\n';

    return 0;
}
