#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define INF 1e9

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;
    vector<vector<pii>> graph(d + 1); // graph[u] : vector{v, w} u -> v (u<v 일방통행)
    for(int i = 0; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        if(v <= d) graph[u].push_back({v, w});
    }

    vector<int> dp(d + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < d; i++){
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        if(graph[i].size()){
            int u = i;
            for(int j = 0; j < graph[u].size(); j++){
                int v = graph[u][j].first;
                int w = graph[u][j].second;
                dp[v] = min(dp[v], dp[u] + w);
            }
        }
    }

    cout << dp[d] << '\n';

    return 0;
}
