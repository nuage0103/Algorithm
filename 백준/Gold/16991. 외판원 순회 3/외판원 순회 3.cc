#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<double>> graph;
double min_cost;
vector<vector<double>> dp; // dp[x][mask]: x출발 mask경로 최소 비용
#define INF 1e18

double dfs(int cur, int mask){
    if(mask == (1 << n) - 1){
        if(graph[cur][0]) return graph[cur][0];
        else return INF;
    }

    if(dp[cur][mask] != -1) return dp[cur][mask];

    dp[cur][mask] = INF;
    for(int i = 0; i < n; i++){
        if(!(mask & (1 << i)) && graph[cur][i]){
            dp[cur][mask] = min(dp[cur][mask], graph[cur][i] + dfs(i, mask | (1 << i)));
        }
    }
    return dp[cur][mask];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    graph.resize(n, vector<double>(n));
    vector<pair<double, double>> coor;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        coor.push_back({x, y});
    }

    for(int i = 0; i < n - 1; i++){
        double x1 = coor[i].first;
        double y1 = coor[i].second;

        for(int j = i + 1; j < n; j++){
            double x2 = coor[j].first;
            double y2 = coor[j].second;
            double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            graph[i][j] = dist;
            graph[j][i] = dist;
        }
    }

    min_cost = INF;
    dp.resize(n, vector<double>(1 << n, -1));
    cout << fixed << setprecision(10) << dfs(0, 1) << '\n';

    return 0;
}
