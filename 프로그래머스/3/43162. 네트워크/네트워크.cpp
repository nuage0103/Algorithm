#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// disjoint set / bfs

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> net(n, -1); // net[i] = i가 속한 네트워크 + 방문여부 확인
    for(int i = 0; i < n; i++){
        if(net[i] != -1) continue;
        
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            net[x] = answer;
            
            for(int nx = 0; nx < computers[x].size(); nx++){
                if(nx == x) continue;
                if(!computers[x][nx]) continue;
                if(net[nx] != -1) continue;
                
                q.push(nx);
            }
        }
        
        answer++;
    }
    
    return answer;
}