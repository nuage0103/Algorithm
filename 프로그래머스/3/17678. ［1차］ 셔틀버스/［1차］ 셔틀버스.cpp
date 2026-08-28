#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    priority_queue<int, vector<int>, greater<int>> q;
    for(string& s: timetable){
        int hr = stoi(s.substr(0, 2));
        int min = stoi(s.substr(3, 2));
        int time = hr * 60 + min;
        q.push(time);
    }
    
    int cur = 9 * 60; // 09:00
    int cnt = 0; // ~m
    int last = 0; // 마지막 크루
    for(int i = 0; i < n; i++){
        while(!q.empty()){
            if(cnt == m) break;
            
            last = q.top();
            if(last <= cur) {
                q.pop();
                cnt++;
            }
            else break;
        }
        if(i == n - 1){
            if(cnt < m) last = cur;
            else last -= 1;
            
            int hr = last / 60;
            int min = last % 60;
            if(hr < 10) answer += "0";
            answer += to_string(hr) + ":";
            if(min < 10) answer += "0";
            answer += to_string(min);
        }
                
        cur += t;
        cnt = 0;
    }
    
    return answer;
}