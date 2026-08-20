#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0; // 인원수

    int st = 0, en = *max_element(stones.begin(), stones.end());
    while(st <= en){
        int mid = st + (en - st) / 2; // 인원수
        int con_zero = 0, max_con = 0; // 연속 0 개수
        for(int i = 0; i < stones.size(); i++){
            // stones[i] = 건널 수 있는 인원 수 >= mid
            if(stones[i] < mid) con_zero++;
            else {
                max_con = max(max_con, con_zero);
                con_zero = 0;
            }
        }
        max_con = max(max_con, con_zero); // 마지막 구간
        
        // 건너뛰는 개수 = 연속0 개수 + 1
        if(max_con < k){
            answer = max(answer, mid);
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
        
    }
    return answer;
}