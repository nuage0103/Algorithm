#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {    
    int len = s.size();
    int answer = len;
    
    for(int w = 1; w <= len / 2; w++){
        string ns = "";
        
        string cur = s.substr(0, w);
        int cnt = 1;
        for(int p = w; p < len; p += w){
            string tmp = s.substr(p, w);
            if(tmp == cur){
                cnt++;
            }
            else{
                if(cnt > 1) ns += to_string(cnt);
                ns += cur;
                
                cur = tmp;
                cnt = 1;
            }
        }
        
        if(cnt > 1) ns += to_string(cnt);
        ns += cur;
            
        answer = min(answer, (int)ns.size());
    }
    
    return answer;
}