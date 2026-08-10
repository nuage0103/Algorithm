#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> dic;
    for(int i = 0; i < 26; i++){
        string key = "";
        key += ('A' + i);
        dic[key] = i + 1;
    }
    
    int i = 0;
    int nxt = 27;
    while(i < msg.size()){
        string w = "";
        while(i < msg.size() && dic.find(w + msg[i]) != dic.end()){
            w += msg[i];
            i++;
        }
        answer.push_back(dic[w]);
        
        if(i < msg.size()){
            dic[w + msg[i]] = nxt;
            nxt++;
        }
    }
    
    return answer;
}