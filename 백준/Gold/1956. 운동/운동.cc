#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;
    // v <= 400. 모든 정점 간의 최소 거리
    vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));
    for(int i = 1; i <= V; i++) dist[i][i] = 0;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for(int k = 1; k <= V; k++){
        for(int u = 1; u <= V; u++){
            for(int v = 1; v <= V; v++){
                if(dist[u][k] != INF && dist[k][v] != INF){
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    int res = INF;
    for(int u = 1; u <= V; u++){
        for(int v = 1; v <= V; v++){
            if(u == v) continue;
            if(dist[u][v] != INF && dist[v][u] != INF){
                res = min(res, dist[u][v] + dist[v][u]);
            }
        }
    }
    if(res == INF) cout << "-1\n";
    else cout << res << '\n';

    return 0;
}
