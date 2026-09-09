#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int del = 0, pick = 0;
    for(int i = n - 1; i >= 0; i--){
        del += deliveries[i]; // 모두 배달/수거할 때까지 (i + 1) 거리 왕복
        pick += pickups[i];
        int cnt = 0; // 왕복 횟수
        while(del > 0 || pick > 0){
            del -= cap; // 최대 배달/수거 개수
            pick -= cap;
            cnt++;
        }
        // cap보다 적어서 del<0 / pick<0 되면 다음 i지점으로 이월
        
        answer += ((long long)i + 1) * 2 * cnt;
    }
    
    return answer;
}