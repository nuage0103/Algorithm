#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    // hit = 1
    // miss = 5
    if(cacheSize == 0) return (5 * cities.size());
    
    for(string& city: cities){
        for(char& c: city) c = tolower(c);
    }

    deque<string> q;
    for(auto& city: cities){
        auto it = find(q.begin(), q.end(), city);
        if(it != q.end()){
            // hit 1
            answer += 1;
            q.erase(it);
            q.push_back(city);
        }
        else{
            // miss 5
            answer += 5;
            
            if(q.size() < cacheSize){
                q.push_back(city);
            }
            else{
                q.pop_front();
                q.push_back(city);
            }
        }
    }
    
    return answer;
}