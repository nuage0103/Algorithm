#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> graph(n+1); // graph[u]={v, w} vector. u->v
    for(int i=0; i<k; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(u >= v) continue;

        graph[u].push_back({v, w});
    }

    // u->v 증가하는 순서로만 이동: dp
    vector<vector<int>> dp(n+1, vector<int>(m+1)); // dp[u][cnt-1] -> dp[v][cnt]
    dp[1][1] = 0;
    for(int i=0; i<graph[1].size(); i++){
        int v = graph[1][i].first;
        int w = graph[1][i].second;
        dp[v][2] = max(dp[v][2], dp[1][1] + w);
    }

    for(int cnt=2; cnt<m; cnt++){
        for(int u=2; u<n; u++){
            if(dp[u][cnt] == 0) continue;

            for(int i=0; i<graph[u].size(); i++){
                int v = graph[u][i].first;
                int w = graph[u][i].second;
                dp[v][cnt+1] = max(dp[v][cnt+1], dp[u][cnt]+w);
            }
        }
    }

    int res = -1;
    for(int i=2; i<=m; i++){
        res = max(res, dp[n][i]);
    }
    cout << res << '\n';

    return 0;
}
