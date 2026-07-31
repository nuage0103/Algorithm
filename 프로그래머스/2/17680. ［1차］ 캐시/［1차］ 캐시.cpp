#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(!cacheSize) return cities.size() * 5;
    
    // 소문자로 변환
    for(string& s: cities){
        for(char& c: s) c = tolower(c);
    }
    
    vector<string> cache;
    // 시간 측정
    for(int i = 0; i < cities.size(); i++){
        string& s = cities[i];
        auto it = find(cache.begin(), cache.end(), s);
        // hit
        if(it != cache.end()){
            answer += 1;
            cache.erase(it);
            cache.push_back(s);
        }
        // miss
        else{
            answer += 5;
            if(cache.size() >= cacheSize){
                cache.erase(cache.begin());
            }
            cache.push_back(s);
        }
    }
    
    return answer;
}