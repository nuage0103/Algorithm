#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int x, y;
    int d; // 현재 바람 방향
}Node;

vector<vector<int>> graph;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; // 0상 1우 2하 3좌
vector<vector<int>> dir; // dir[i][j] = k, 물건i 바람 방향 j->k
vector<vector<vector<int>>> visited;
vector<vector<int>> res;
queue<Node> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    graph.resize(n, vector<int>(m));
    visited.resize(4, vector<vector<int>>(n, vector<int>(m, 0)));
    res.resize(n, vector<int>(m, 0));
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 9) {
                visited[0][i][j] = visited[1][i][j] = visited[2][i][j] = visited[3][i][j] = 1;
                q.push({i, j, 0});
                q.push({i, j, 1});
                q.push({i, j, 2});
                q.push({i, j, 3});
                res[i][j] = 1;
                cnt++;
            }
        }
    }

    dir.resize(5, vector<int>(4));
    // 방향전환 없음
    dir[0] = {0, 1, 2, 3};
    // 1: 상상, 우좌, 하하, 좌우
    dir[1] = {0, 3, 2, 1};
    // 2: 상하, 우우, 하상, 좌좌
    dir[2] = {2, 1, 0, 3};
    // 3: 상우, 우상, 하좌, 좌하
    dir[3] = {1, 0, 3, 2};
    // 4: 상좌, 우하, 하우, 좌상
    dir[4] = {3, 2, 1, 0};

    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int d = cur.d;

        int type = graph[x][y];
        if(type == 9) type = 0;

        int nd = dir[type][d];
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited[nd][nx][ny]) continue;

        visited[nd][nx][ny] = 1;
        q.push({nx, ny, nd});
        if(!res[nx][ny]){
            res[nx][ny] = 1;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
