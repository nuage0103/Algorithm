#include<vector>
#include<queue>

using namespace std;

int n, m;

int bfs(vector<vector<int>>& maps){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m));
    q.push({0, 0});
    visited[0][0] = 1;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int t = visited[x][y];
        q.pop();
        
        if(x == n - 1 && y == m - 1) return t;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;
            if(!maps[nx][ny]) continue;
            
            visited[nx][ny] = t + 1;
            q.push({nx, ny});
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    n = maps.size();
    m = maps[0].size();
    // 0: 벽, 1: 벽 없음
    // 출발 (0, 0) -> (n-1, m-1)
    answer = bfs(maps);
    
    return answer;
}