#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// abc: 7
// 6 / a: 5, 4 / b: 3, 7 / c: 1, 2
// 파이프 열면, 더이상 감염되는 개체 없을 때까지 순차적 전파
int max_res;
vector<vector<vector<int>>> adj;
string order = "012";

int bfs(string& path, int n, int infection){
    vector<bool> infected(n + 1, false);
    infected[infection] = true;
    
    for(char& t: path){
        queue<int> q;
        int type = t - '0';
        for(int i = 1; i <= n; i++){
            if(infected[i]) q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(int nx: adj[type][x]){
                if(infected[nx]) continue;
                
                infected[nx] = true;
                q.push(nx);
            }
        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(infected[i]) res++;
    }
    return res;
}

void dfs(string& path, int n, int infection, int k){
    if(path.size() == k){
        max_res = max(max_res, bfs(path, n, infection));
        return;
    }
    
    for(int i = 0; i < 3; i++){
        path.push_back(order[i]);
        dfs(path, n, infection, k);
        path.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0; // 감염 개체수 최댓값
    
    adj.assign(3, vector<vector<int>>(n + 1));
    for(auto& e: edges){
        int u = e[0], v = e[1];
        int type = e[2] - 1;
        adj[type][u].push_back(v);
        adj[type][v].push_back(u);
    }
    
    max_res = -1;
    string path = "";
    dfs(path, n, infection, k);
    answer = max_res;
    
    return answer;
}