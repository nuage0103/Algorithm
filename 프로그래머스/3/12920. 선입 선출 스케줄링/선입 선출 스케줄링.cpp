#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> cores) {
    if(n <= cores.size()) return n;
    
    int answer = 0;
    
    int c_len = cores.size();
    int st = 1, en = n * *max_element(cores.begin(), cores.end());
    int min_time = 0;
    while(st <= en){
        int mid = st + (en - st) / 2;
        int cnt = c_len; // 0초에 c_len 개 시작
        for(int i = 0; i < c_len; i++){
            cnt += mid / cores[i];
            if(cnt >= n) break;
        }
        
        if(cnt >= n){
            min_time = mid;
            en = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    
    // min_time 이전까지 끝낸 작업
    int cnt = c_len;
    for(int i = 0; i < c_len; i++){
        cnt += (min_time - 1) / cores[i];
    }
    // min_time에 시작하는 작업
    for(int i = 0; i < c_len; i++){
        if(min_time % cores[i] == 0){
            cnt++;
            if(cnt == n) return i + 1;
        }
    }
    
    return answer;
}