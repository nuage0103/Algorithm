#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int n = truck_weights.size();
    
    int answer = 0; // 현재 시간
    int w_sum = 0; // 다리 위 무게 합
    queue<int> q; // 다리 위
    // 큐 크기 제한
    for(int i = 0; i < bridge_length; i++){
        q.push(0);
    }
    
    int idx = 0;
    while(idx < n){
        answer++; // 한 타임에 한 트럭만 올림
        
        // 하나 빼기
        w_sum -= q.front();
        q.pop();
                
        // 하나 더하기: 큐 크기 동일하게 유지
        int t = truck_weights[idx];
        if(w_sum + t <= weight){
            w_sum += t;
            q.push(t);
            idx++;
        }
        else{
            q.push(0);
        }
    }
    // 마지막 트럭 이동 시간
    answer += bridge_length;
    
    return answer;
}