#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
현재 피로도 >= 최소 소모 피로도: 탐험 가능
탐험 후: 현재 피로도 -= 소모 피로도

dfs, backtracking
*/

int n;
int res;
vector<int> visited;

void dfs(int depth, int cur, vector<vector<int>>& dungeons, int cnt){
    /*
    if(depth == n){
        res = max(res, cnt);
        return;
    }
    */
    res = max(res, cnt);
    
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        if(cur >= dungeons[i][0]){
            visited[i] = 1;
            dfs(depth + 1, cur - dungeons[i][1], dungeons, cnt + 1);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    n = dungeons.size();
    visited.resize(n);
    res = -1;
    dfs(0, k, dungeons, 0);
    answer = res;
    
    return answer;
}