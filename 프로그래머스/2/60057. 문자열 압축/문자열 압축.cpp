#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int n = s.size();
    answer = n;
    for(int w = 1; w <= n / 2; w++){
        string cur, prev;
        string res = "";
        int cnt = 0;
        
        prev = s.substr(0, w);
        cnt++;
        for(int i = w; i < n; i += w){
            cur = s.substr(i, w);
            if(cur == prev){
                cnt++;
            }
            else{
                if(cnt == 1) res += prev;
                else res += to_string(cnt) + prev;
                
                prev = cur;
                cnt = 1;
            }
        }
        if(cnt == 1) res += prev;
        else res += to_string(cnt) + prev;
        
        answer = min(answer, (int)res.size());
    }
    
    return answer;
}