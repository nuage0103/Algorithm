#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
//섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    sort(scoville.begin(), scoville.end());    
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end()); // min heap
    while(!q.empty()){
        if(q.top() >= K) break;
        if(q.size() < 2) break;
        
        int s1 = q.top();        
        q.pop();
        int s2 = q.top();
        q.pop();
        
        q.push(s1 + s2 * 2);
        answer++;
    }
    
    if(!q.empty() && q.top() < K) answer = -1;
    return answer;
}