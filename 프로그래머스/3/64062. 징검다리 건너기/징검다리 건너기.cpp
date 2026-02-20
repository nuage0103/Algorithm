#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    vector<int> sorted = stones;
    int n = stones.size();
    sort(sorted.begin(), sorted.end());

    int st = sorted[0], en = sorted[n-1];
    while(st <= en){
        int mid = (st + en) / 2;
        int skip = 0;
        bool flag = true;
        for(int x: stones){
            if(x - mid < 0) {
                skip++;
                if(skip >= k) {
                    flag = false;
                    break;
                }
            }
            else skip = 0;
        }
        
        if(flag){
            answer = max(answer, mid);
            st = mid + 1;
        }
        else en = mid - 1;
    }
    
    return answer;
}