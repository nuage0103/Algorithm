#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pi>> graph(n + 1); // graph[u]: {v, w} vector. u -> v
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    priority_queue<pi, vector<pi>, greater<pi>> q; // {dist, node}
    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;
    q.push({dist[1], 1});
    // 1 -> n
    while(!q.empty()){
        int d = q.top().first;
        int cur = q.top().second;
        q.pop();

        if(dist[cur] < d) continue;

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int nd = graph[cur][i].second + d;

            if(dist[next] > nd){
                dist[next] = nd;
                q.push({dist[next], next});
            }
        }
    }

    cout << dist[n] << '\n';

    return 0;
}
