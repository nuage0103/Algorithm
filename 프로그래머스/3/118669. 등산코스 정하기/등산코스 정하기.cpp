#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
1~n: 출입구 gates, 쉼터, 산봉우리 summits
코스: 출 시작-봉1개-출 끝

intensity: 출->봉 경로 중 최대값
dist[x] = 출->x 경로 중 최소 intensity
*/

struct comp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    vector<int> type(n + 1, 0); // 0쉼터, 1출입구, 2봉우리
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q; // {node, intensity}
    vector<int> dist(n + 1, 1e9);
    for(int g: gates){
        type[g] = 1;
        q.push({g, 0});
        dist[g] = 0;
    }
    for(int s: summits){
        type[s] = 2;
    }
    
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>()); // u: {v, w}
    for(int i = 0; i < paths.size(); i++){
        int u = paths[i][0];
        int v = paths[i][1];
        int w = paths[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    while(!q.empty()){
        auto [x, intensity] = q.top();
        q.pop();
        
        // 출->x 여러경로 중 최소
        if(dist[x] < intensity) continue;
        if(type[x] == 2) continue;
        
        for(auto [nx, w]: adj[x]){
            // 출->x->nx: x까지 최대=intensity + 새 경로=w
            int ni = max(intensity, w);
            if(ni < dist[nx]){
                dist[nx] = ni;
                q.push({nx, ni});
            }
        }
    }
    
    // 봉우리, 값
    answer.push_back(1e9);
    answer.push_back(1e9);
    for(int s: summits){
        if(dist[s] < answer[1]){
            answer[0] = s;
            answer[1] = dist[s];
        }
        else if(answer[1] == dist[s]){
            answer[0] = min(answer[0], s);
        }
    }
    return answer;
}