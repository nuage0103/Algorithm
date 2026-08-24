#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

bool bfs(int stx, int sty, vector<string>& place){
    queue<pair<int, int>> q;
    vector<vector<int>> dist(5, vector<int>(5, -1));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    q.push({stx, sty});
    dist[stx][sty] = 0;
    // P, 0: 이동 가능
    // X: 이동 불가
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        if(dist[x][y] >= 2) continue;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(dist[nx][ny] != -1) continue;
            if(place[nx][ny] == 'X') continue;
            
            if(place[nx][ny] == 'P') return false;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    
    return true;
}

bool check(vector<string>& place){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(place[i][j] == 'P'){
                if(!bfs(i, j, place)) return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < 5; i++){
        if(check(places[i])) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}