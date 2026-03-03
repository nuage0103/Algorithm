#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;

typedef struct{
    int x, y;
    int crash;
} Node;

int bfs(){
    queue<Node> q;
    vector<vector<vector<int>>> dist;
    dist.resize(n, vector<vector<int>>(m, vector<int>(2, -1)));

    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while(!q.empty()){
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int c = cur.crash;
        int d = dist[x][y][c];

        if(x == n-1 && y == m-1) return d;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(graph[nx][ny]){
                if(c) continue;
                if(dist[nx][ny][1] != -1) continue;

                dist[nx][ny][1] = d + 1;
                q.push({nx, ny, 1});
            }
            else{
                if(dist[nx][ny][c] != -1) continue;

                dist[nx][ny][c] = d + 1;
                q.push({nx, ny, c});
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            graph[i].push_back(s[j] - '0');
        }
    }

    cout << bfs() << '\n';

    return 0;
}
