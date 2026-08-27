#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer; // enroll_idx 순서
    
    int n = enroll.size();
    vector<int> parent(n, -1);
    unordered_map<string, int> um; // {name, enroll_idx}
    um["center"] = -1;
    for(int i = 0; i < n; i++){
        string ch = enroll[i];
        string pa = referral[i]; // 이미 enroll에 등장
        if(pa != "-") parent[i] = um[pa];
        um[ch] = i;
    }
    
    // 이익 100원
    answer.resize(n, 0);
    for(int i = 0; i < seller.size(); i++){
        int idx = um[seller[i]];
        int have = amount[i] * 100;
        int give = (have * 0.1 < 1)? 0 : have * 0.1;
        have -= give;
        while(idx != -1){
            answer[idx] += have;
            
            idx = parent[idx];
            have = give;
            give = (have * 0.1 < 1)? 0 : have * 0.1;
            have -= give;
        }
    }

    return answer;
}