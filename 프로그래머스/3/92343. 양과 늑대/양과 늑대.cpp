#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> graph; // graph[x]: left, right child
int max_sheep;

void dfs(vector<int>& info, int node_mask, int cur, int sheep, int wolf){
    if(info[cur] == 0) sheep++;
    else wolf++;
    
    if(sheep <= wolf) return;
    max_sheep = max(max_sheep, sheep);
        
    node_mask |= graph[cur];
    for(int i=0; i<n; i++){
        if(!(node_mask & (1<<i))) continue;
        
        node_mask &= ~(1<<i);
        dfs(info, node_mask, i, sheep, wolf);
        node_mask |= (1<<i);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    graph.resize(n, 0);
    for(int i=0; i<edges.size(); i++){
        graph[edges[i][0]] |= (1<<edges[i][1]);
    }
    
    max_sheep = -1; 
    dfs(info, 0, 0, 0, 0);
    
    int answer = max_sheep;     
    return answer;
}