#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> p_map;
    for(int i=0; i<participant.size(); i++){
        string name = participant[i];
        if(p_map.find(name) == p_map.end()) p_map[name] = 1;
        else p_map[name]++;
    }
    for(int i=0; i<completion.size(); i++){
        p_map[completion[i]]--;
    }
    
    string answer = "";
    for(int i=0; i<participant.size(); i++){
        string name = participant[i];
        if(p_map[name]){
            answer = name;
            break;
        }
    }
    return answer;
}