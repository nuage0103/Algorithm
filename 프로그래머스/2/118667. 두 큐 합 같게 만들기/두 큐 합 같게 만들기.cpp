#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    int n = queue1.size();
    long long sum1 = 0, sum2 = 0;
    vector<int> q;
    for(int i = 0; i < n; i++){
        sum1 += queue1[i];
        q.push_back(queue1[i]);
    }
    for(int i = 0; i < n; i++){
        sum2 += queue2[i];
        q.push_back(queue2[i]);
    }
    if((sum1 + sum2) % 2) return -1;
    
    long long target = (sum1 + sum2) / 2;
    int st = 0, en = n - 1;
    n *= 2;
    answer = 0;
    while(answer < 3 * n){
        if(sum1 == target) return answer;
        
        if(sum1 > target){
            sum1 -= q[st];
            st = (st + 1) % n;
        }
        else{
            en = (en + 1) % n;
            sum1 += q[en];
        }
        answer++;
    }
    
    answer = -1;
    return answer;
}