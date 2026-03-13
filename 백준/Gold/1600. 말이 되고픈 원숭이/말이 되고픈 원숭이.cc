#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int k, w, h;
vector<vector<int>> graph; // 1 장애물
// 원숭이
int dxm[4] = {1, 0, -1, 0};
int dym[4] = {0, 1, 0, -1};
// 말
int dxh[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dyh[8] = {1, 2, 2, 1, -1, -2, -2, -1};

typedef struct{
    int x, y;
    int cnt; // ~k
}Node;
int visited[31][201][201];

int bfs(){
    queue<Node> q;
    fill(&visited[0][0][0], &visited[0][0][0] + 31 * 201 * 201, -1);
    q.push({0, 0, 0});
    visited[0][0][0] = 0;

    while(!q.empty()){
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int cnt = cur.cnt;
        int move = visited[cnt][x][y];
        if(x == h - 1 && y == w - 1) return move;

        if(cnt < k){
            for(int i = 0; i < 8; i++){
                int nx = x + dxh[i];
                int ny = y + dyh[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(graph[nx][ny] == 1) continue;
                if(visited[cnt + 1][nx][ny] != -1) continue;

                visited[cnt + 1][nx][ny] = move + 1;
                q.push({nx, ny, cnt + 1});
            }
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dxm[i];
            int ny = y + dym[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(graph[nx][ny] == 1) continue;
            if(visited[cnt][nx][ny] != -1) continue;

            visited[cnt][nx][ny] = move + 1;
            q.push({nx, ny, cnt});
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    cin >> w >> h;
    graph.resize(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> graph[i][j];
        }
    }

    cout << bfs() << '\n';

    return 0;
}
