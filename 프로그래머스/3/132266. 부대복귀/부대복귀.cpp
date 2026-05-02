#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> adj;

int bfs(int s, int d, int n){
    queue<int> q;
    vector<int> visited(n + 1, -1);
    q.push(s);
    visited[s] = 0;
    while(!q.empty()){
        int x = q.front();
        int t = visited[x];
        q.pop();
        
        if(x == d) return t;
        
        for(int nx: adj[x]){
            if(visited[nx] != -1) continue;
            
            visited[nx] = t + 1;
            q.push(nx);
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    adj.resize(n + 1);
    for(int i = 0; i < roads.size(); i++){
        int u = roads[i][0];
        int v = roads[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int s: sources) answer.push_back(bfs(s, destination, n));
    
    return answer;
}