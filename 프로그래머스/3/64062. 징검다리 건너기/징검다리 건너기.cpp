#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0; // 최대 인원
    
    int st = 0, en = *max_element(stones.begin(), stones.end());
    while(st <= en){
        int mid = st + (en - st) / 2;
        int skip = 0;
        for(int s: stones){
            if(s < mid){
                skip++;
                if(skip == k) break;
            }
            else skip = 0;
        }
        
        if(skip < k){
            answer = mid;
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }
    
    return answer;
}