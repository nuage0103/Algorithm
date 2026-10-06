#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    
    int num_w = weak.size();
    int num_d = dist.size();
    // 이동거리 내림차순
    sort(dist.begin(), dist.end(), greater<int>());
    
    // bfs: 친구 수 늘려가면서 취약점 처리
    queue<pair<int, int>> q; // {사람수, 마스크: 처리된 지점 1}
    vector<int> state(1 << num_w, 1e9); // state[i] = i 마스크 처리하는 최소 인원 수
    
    q.push({0, 0}); // 사람수 = dist idx = 0부터 시작
    state[0] = 0;
    answer = num_d + 1;
    while(!q.empty()){
        auto [cnt, mask] = q.front();
        q.pop();
        
        if(mask == (1 << num_w) - 1){
            answer = cnt;
            break;
        }
        if(cnt >= num_d) continue;
        
        int d = dist[cnt]; // 이번 사람 이동 거리
        for(int i = 0; i < num_w; i++){
            if(mask & (1 << i)) continue;
            
            int nx_mask = mask | (1 << i); // i출발. d만큼 이동
            for(int j = 0; j < num_w; j++){
                if(i == j) continue;
                int diff = (weak[i] < weak[j])? (weak[j] - weak[i]) : (n + weak[j] - weak[i]);
                
                if(diff <= d){
                    nx_mask |= (1 << j);
                }
            }
            
            if(cnt + 1 < state[nx_mask]){
                state[nx_mask] = cnt + 1;
                q.push({cnt + 1, nx_mask});
            }
        }
    }
    
    if(answer > num_d) answer = -1;
    
    return answer;
}