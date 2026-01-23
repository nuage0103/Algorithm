#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;
int s_size;

typedef struct{
    int x, y;
    int t;
}Food;

Food bfs(int s_x, int s_y){
    // bfs: 먹이 찾기
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    q.push({s_x, s_y});
    dist[s_x][s_y] = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    Food f = {-1, -1, -1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(f.t != -1 && dist[x][y] > f.t) break;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny] != -1) continue;
            // 커: 못지나가
            if(graph[nx][ny] > s_size) continue;

            // 같아: 지나가, 못먹어
            // 작아: 지나가, 먹이 후보
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
            if(graph[nx][ny] != 0 && graph[nx][ny] < s_size){
                // 최소 거리 = 최소 시간
                if(f.t == -1) {
                    f.t = dist[nx][ny];
                    f.x = nx;
                    f.y = ny;
                }
                else if(dist[nx][ny] == f.t) {
                    // 가장 위
                    // 가장 왼쪽
                    if(nx < f.x || (nx == f.x && ny < f.y)){
                        f.x = nx;
                        f.y = ny;
                    }
                }
            }
        }
    }

    return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    graph.resize(n, vector<int>(n));
    int s_x, s_y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 9){
                s_x = i;
                s_y = j;
            }
        }
    }
    graph[s_x][s_y] = 0;

    s_size = 2;
    int res = 0;
    int cnt = 0;
    while(1){
        Food f = bfs(s_x, s_y);
        if(f.t == -1) break;

        res += f.t;
        s_x = f.x;
        s_y = f.y;
        graph[s_x][s_y] = 0;
        cnt++;
        if(cnt == s_size){
            s_size++;
            cnt = 0;
        }
    }

    cout << res << '\n';

    return 0;
}
