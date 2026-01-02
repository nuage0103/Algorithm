#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int x, y;
    int dist;
}Info;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    int start_x, start_y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                start_x = i;
                start_y = j;
            }
        }
    }

    queue<Info> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    q.push({start_x, start_y, 0});
    dist[start_x][start_y] = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().dist;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!map[nx][ny]) continue;

            if(dist[nx][ny] == -1){
                dist[nx][ny] = d + 1;
                q.push({nx, ny, d + 1});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!map[i][j]) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
