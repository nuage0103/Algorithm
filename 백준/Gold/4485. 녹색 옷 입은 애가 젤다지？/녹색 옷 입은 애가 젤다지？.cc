#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int x, y;
    int cost;
}Node;

struct comp{
    bool operator()(const Node& a, const Node& b){
        return a.cost > b.cost;
    }
};

#define INF 1e9

int bfs(int n, vector<vector<int>>& graph){
    priority_queue<Node, vector<Node>, comp> q;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    cost[0][0] = graph[0][0];
    q.push({0, 0, cost[0][0]});

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while(!q.empty()){
        Node cur = q.top();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int w = cur.cost;
        if(cost[x][y] < w) continue;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if(cost[nx][ny] > w + graph[nx][ny]){
                cost[nx][ny] = w + graph[nx][ny];
                q.push({nx, ny, cost[nx][ny]});
            }

        }
    }

    return cost[n-1][n-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int p = 1;
    while(1){
        int n;
        cin >> n;
        if(!n) break;

        vector<vector<int>> graph(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> graph[i][j];
            }
        }

        int res = bfs(n, graph);
        cout << "Problem " << p << ": " << res << '\n';
        p++;
    }

    return 0;
}
