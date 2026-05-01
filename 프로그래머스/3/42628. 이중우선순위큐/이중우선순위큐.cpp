#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq; 
    unordered_map<int, int> freq;
    for(auto& op: operations){
        if(op[0] == 'I'){
            int num = stoi(op.substr(2));
            maxq.push(num);
            minq.push(num);
            freq[num]++;
        }
        else{
            while(!minq.empty() && freq[minq.top()] <= 0) minq.pop();
            while(!maxq.empty() && freq[maxq.top()] <= 0) maxq.pop();
            
            if(minq.empty() || maxq.empty()) continue;
            
            if(op[2] == '-'){
                // -1
                freq[minq.top()]--;
                minq.pop();
            }
            else{
                // 1
                freq[maxq.top()]--;
                maxq.pop();               
            }
        }
    }
    
    while(!minq.empty() && freq[minq.top()] <= 0) minq.pop();
    while(!maxq.empty() && freq[maxq.top()] <= 0) maxq.pop();
    
    if(!maxq.empty() && !minq.empty()){
        answer.push_back(maxq.top());
        answer.push_back(minq.top());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}