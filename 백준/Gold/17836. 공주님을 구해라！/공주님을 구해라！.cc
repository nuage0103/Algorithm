#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, T;
vector<vector<int>> graph;
int visited[2][101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

typedef struct{
    int x, y;
    int have;
} Node;

int bfs(){
    queue<Node> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 0;

    while(!q.empty()){
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int h = cur.have;
        int t = visited[h][x][y];

        if(x == n - 1 && y == m - 1) {
            if(t > T) return -1;
            else return t;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(!h){
                int state = graph[nx][ny];
                if(state == 1) continue;

                if(state == 0 && visited[0][nx][ny] == -1){
                    q.push({nx, ny, h});
                    visited[0][nx][ny] = t + 1;
                }
                else if(state == 2 && visited[1][nx][ny] == -1){
                    q.push({nx, ny, 1});
                    visited[1][nx][ny] = t + 1;
                }
            }
            else{
                if(visited[1][nx][ny] != -1) continue;

                q.push({nx, ny, h});
                visited[h][nx][ny] = t + 1;
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> T;
    graph.resize(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    fill(&visited[0][0][0], &visited[0][0][0] + 2*101*101, -1);
    int res = bfs();
    if(res < 0) cout << "Fail\n";
    else cout << res << '\n';

    return 0;
}
