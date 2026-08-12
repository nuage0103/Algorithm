#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, string> um; // {id, name}
    vector<pair<string, string>> msg; // {id, enter/leave}
    for(auto& r: record){
        stringstream ss(r);
        string status, id, name;
        ss >> status >> id >> name;
        
        if(status == "Enter"){
            um[id] = name;
            msg.push_back({id, "님이 들어왔습니다."});
        }
        else if(status == "Leave"){
            msg.push_back({id, "님이 나갔습니다."});
        }
        else{
            um[id] = name;
        }
    }
    
    for(auto& [id, status]: msg){
        answer.push_back(um[id] + status);
    }
    
    return answer;
}