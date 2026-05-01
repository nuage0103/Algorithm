#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
// 번호, 요청 시각, 소요 시간
// 소요시간 짧, 요청시각 빠, 번호 작

typedef struct{
    int idx, start, dur;
}Node;

struct comp{
    bool operator()(const Node& a, const Node& b){
        if(a.dur != b.dur) return a.dur > b.dur;
        if(a.start != b.start) return a.start > b.start;
        return a.idx > b.idx;
    }
};

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    vector<Node> j(n);
    for(int i = 0; i < n; i++){
        j[i] = {i, jobs[i][0], jobs[i][1]};
    }
    
    sort(j.begin(), j.end(), [](const auto& a, const auto& b){
        return a.start < b.start;
    });
    
    priority_queue<Node, vector<Node>, comp> q;
    int answer = 0;
    
    int cur = 0; // 현재 시각
    int idx = 0; // 처리한 개수
    while(idx < n || !q.empty()){
        // 대기열 생성
        while(idx < n && j[idx].start <= cur){            
            q.push(j[idx]);
            idx++;
        }
        
        // 대기열 없음. 요청시각 빠 하나 선택
        if(q.empty()){
            cur = j[idx].start;
        }
        // 선택
        else {
            Node x = q.top();
            q.pop();
            
            cur += x.dur;
            answer += cur - x.start;
        }
    }
    
    answer /= n;
    return answer;
}