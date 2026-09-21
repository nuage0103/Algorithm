#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<vector<int>>> adj;
int max_res;
string order = "012";

int bfs(string& pipe, int n, int infection){
    queue<int> q;
    vector<vector<bool>> propagated(3, vector<bool>(n + 1, false)); // type, node
    vector<bool> infected(n + 1, false);
    infected[infection] = true;
    
    for(int i = 0; i < pipe.size(); i++){
        for(int i = 1; i < infected.size(); i++){
            if(infected[i]) q.push(i);
        }
        
        int type = pipe[i] - '0';
        
        while(!q.empty()){
            int x = q.front(); // 6
            q.pop();
            
            propagated[type][x] = true; // [a][6]
            for(int nx: adj[type][x]){ // 5                
                if(propagated[type][nx]) continue;
                q.push(nx);
                infected[nx] = true;
            }
        }
    }
    
    int res = 0;
    for(int i = 1; i < infected.size(); i++){
        if(infected[i]) res++;
    }
    
    return res;
}

void dfs(int k, string& pipe, int n, int infection){
    if(pipe.size() == k){
        max_res = max(max_res, bfs(pipe, n, infection));
        return;
    }
    
    for(int i = 0; i < 3; i++){
        pipe.push_back(order[i]);
        dfs(k, pipe, n, infection);
        pipe.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    
    adj.clear();
    adj.resize(3, vector<vector<int>>(n + 1));
    for(auto& e: edges){
        int x = e[0], y = e[1], type = e[2] - 1;
        adj[type][x].push_back(y);
        adj[type][y].push_back(x);
    }
    
    max_res = -1;
    string pipe = "";
    dfs(k, pipe, n, infection);
    
    answer = max_res;
    
    return answer;
}