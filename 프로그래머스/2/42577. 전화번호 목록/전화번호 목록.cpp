#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
 
    unordered_map<string, int> um;
    for(auto& p: phone_book){
        um[p] = 1;
    }
    
    for(auto& p: phone_book){
        string tmp = "";
        for(int i = 0; i < p.size() - 1; i++){
            tmp += p[i];
            if(um.find(tmp) != um.end()) return false;
        }
    }
    
    return answer;
}