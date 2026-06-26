#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<string> res;
vector<string> path;
vector<int> visited; // ticket[i] 사용여부
bool found = false;

void dfs(int depth, string src, vector<vector<string>>& tickets){
    if(found) return;
    
    if(depth == n) {
        res = path;
        found = true;
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(tickets[i][0] != src) continue;
        if(visited[i]) continue;
        
        visited[i] = 1;
        path.push_back(tickets[i][1]);
        dfs(depth + 1, tickets[i][1], tickets);
        visited[i] = 0;
        path.pop_back();
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    n = tickets.size();
    visited.resize(n);
    sort(tickets.begin(), tickets.end()); // 출발지 기준 정렬
    
    path.push_back("ICN");
    dfs(0, "ICN", tickets);
    answer = res;
    
    return answer;
}