#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
    int req, dur, idx; // 요청시각, 소요시간, 번호
}Job;

struct comp{
    bool operator() (const Job& a, const Job& b){
        // 우선순위 높은
        // 소요시간 짧
        if(a.dur != b.dur) return a.dur > b.dur;
        // 요청시간 빠른
        else if(a.req != b.req) return a.req > b.req;
        // 번호 작
        else return a.idx > b.idx;
    }
};

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    
    // jobs[i]: [요청시각, 소요시간]
    vector<Job> req_jobs;
    for(int i=0; i<n; i++){
        req_jobs.push_back({jobs[i][0], jobs[i][1], i});
    }
    sort(req_jobs.begin(), req_jobs.end(),
        [](const Job& a, const Job& b){
            // 요청시각 빠를수록 먼저
            return a.req < b.req;
        });
    
    priority_queue<Job, vector<Job>, comp> ready; // 우선순위 높을수록 루트
    int answer = 0; // 전체 소요 시간
    int cur = 0; // 기존 작업 끝난 시각. 현재
    int done = 0; // 끝난 작업 개수
    int i = 0; // req_jobs idx
    while(done < n){
        // 현재 시각까지 요청된 작업들만 대기큐에 삽입
        while(i < n && req_jobs[i].req <= cur){
            ready.push(req_jobs[i]);
            i++;
        }
        
        // 대기큐 빈 상태. 다음 작업으로 넘어가기
        if(ready.empty()){
            cur = req_jobs[i].req;
            continue;
        }
        
        Job j = ready.top();
        ready.pop();
        
        cur += j.dur;
        answer += (cur - j.req);
        done++;
    }
    answer /= n;
    return answer;
}