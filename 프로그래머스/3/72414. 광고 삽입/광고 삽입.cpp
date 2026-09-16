#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int change_time(string s){
    stringstream ss(s);
    string token;
    
    getline(ss, token, ':');
    int hr = stoi(token);
    getline(ss, token, ':');
    int min = stoi(token);
    getline(ss, token, ':');
    int sec = stoi(token);
    
    return (hr * 3600 + min * 60 + sec);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    if(play_time == adv_time) return "00:00:00";
    
    int ptime = change_time(play_time);
    int atime = change_time(adv_time);
    
    vector<long long> ltime(360000, 0); // 누적합. ltime[i] = i초 인원수
    // 99:59:59 = 359,999초
    for(string& log: logs){
        int st = change_time(log.substr(0, 8));
        int en = change_time(log.substr(9));
        ltime[st]++;
        ltime[en]--;
    }
    for(int i = 1; i <= ptime; i++){
        ltime[i] += ltime[i - 1];
    }
    
    int res = 0;
    long long max_sum = 0, sum = 0;
    // 슬라이딩 윈도우. 크기 atime
    for(int i = 0; i < atime; i++){
        // 0 ~ atime - 1
        sum += ltime[i];
    }
    max_sum = sum;
    for(int i = atime; i <= ptime; i++){
        // i - atime + 1 ~ i
        sum += ltime[i];
        sum -= ltime[i - atime];
        if(max_sum < sum){
            max_sum = sum;
            res = i - atime + 1; // 가장 빠른 시작 시각
        }
    }
    
    string x = (res / 3600 < 10)? "0" + to_string(res / 3600) : to_string(res / 3600);
    answer += x + ":";
    res %= 3600;
    x = (res / 60 < 10)? "0" + to_string(res / 60) : to_string(res / 60);
    answer += x + ":";
    res %= 60;
    x = (res < 10)? "0" + to_string(res) : to_string(res);
    answer += x;
    return answer;
}