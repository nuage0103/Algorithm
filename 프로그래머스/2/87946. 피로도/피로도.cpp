#include <string>
#include <vector>

using namespace std;

int n, cnt;
vector<int> visited;

void dfs(int depth, int cur, int n, vector<vector<int>>& dungeons){
    cnt = max(cnt, depth);
    
    if(depth == dungeons.size()) return;
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        if(cur < dungeons[i][0]) continue;
        
        visited[i] = 1;
        dfs(depth + 1, cur - dungeons[i][1], n, dungeons);
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    n = dungeons.size();
    cnt = 0;
    visited.resize(n);
    dfs(0, k, n, dungeons);
    answer = cnt;
    
    return answer;
}