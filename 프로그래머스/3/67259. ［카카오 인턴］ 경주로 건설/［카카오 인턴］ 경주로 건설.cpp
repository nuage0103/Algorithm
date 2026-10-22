#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int x, y;
    int dir;
    int cost;
}Node;

struct comp{
    bool operator()(const Node& a, const Node& b){
        return a.cost > b.cost;
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    //0빈칸, 직선100 코너500
    // 상하01, 좌우23
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    priority_queue<Node, vector<Node>, comp> q;
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(4, 1e9)));
    
    q.push({0, 0, -1, 0});
    answer = 1e9;
    
    while(!q.empty()){
        auto [x, y, prev, cost] = q.top();
        q.pop();
        
        if(x == n - 1 && y == n - 1){
            answer = min(answer, cost);
            continue;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny]) continue;
            
            int ncost = cost + 100;
            if((prev == 0 || prev == 1) && (i == 2 || i == 3)) ncost += 500;
            if((prev == 2 || prev == 3) && (i == 0 || i == 1)) ncost += 500;
            if(ncost < visited[nx][ny][i]){
                q.push({nx, ny, i, ncost});
                visited[nx][ny][i] = ncost;
            }
        }
    }
    
    return answer;
}