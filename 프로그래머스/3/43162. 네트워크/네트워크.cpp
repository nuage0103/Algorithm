#include <string>
#include <vector>

using namespace std;

vector<int> visited;

void dfs(int x, int n, vector<vector<int>>& computers){
    visited[x] = 1;
    for(int i = 0; i < n; i++){
        if(!computers[x][i]) continue;
        if(visited[i]) continue;
        
        dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    
    return answer;
}