#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int x, y;
    int type, cost;
} Node;

struct comp{
    bool operator()(Node& a, Node& b){
        return a.cost > b.cost;
    }
};

bool is_corner(int prev, int next){
    if(prev == -1) return false;
    if(prev < 2 && next >= 2) return true;
    if(prev >= 2 && next < 2) return true;
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = board.size();
    
    // 상하좌우
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    priority_queue<Node, vector<Node>, comp> q;
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(4, 1e9)));
    q.push({0, 0, -1, 0});
    answer = 1e9;
    
    while(!q.empty()){
        auto [x, y, type, cost] = q.top();
        q.pop();
                
        if(x == n - 1 && y == n - 1){
            answer = min(cost, answer);
            continue;
        }
        
        // 0 빈칸, 100 직선, 500 코너
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny]) continue;
            
            int ncost = (is_corner(type, i))? cost + 600 : cost + 100;
            if(ncost < visited[nx][ny][i]){
                visited[nx][ny][i] = ncost;
                q.push({nx, ny, i, ncost});
            }
        }
    }
    
    return answer;
}