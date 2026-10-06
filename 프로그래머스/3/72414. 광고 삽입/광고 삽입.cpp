#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long ll;

int toSec(string s){
    stringstream ss(s);
    int hr, min, sec;
    string token;
    
    getline(ss, token, ':');
    hr = stoi(token);
    getline(ss, token, ':');
    min = stoi(token);
    getline(ss, token, ':');
    sec = stoi(token);
    
    return (hr * 3600 + min * 60 + sec);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int pt = toSec(play_time);
    int at = toSec(adv_time);
    if(pt <= at) return "00:00:00";
    
    vector<ll> cnt(99 * 3600 + 59 * 60 + 60, 0);
    for(string& log: logs){
        int st = toSec(log.substr(0, 8));
        int en = toSec(log.substr(9));
        cnt[st]++;
        cnt[en]--;
    }
    for(int i = 0; i < pt; i++){
        cnt[i + 1] += cnt[i];
    }
    
    ll max_sum = -1, sum = 0;
    int ans = -1;
    for(int i = 0; i < at; i++){
        // 0 ~ at-1
        sum += cnt[i];
    }
    max_sum = sum;
    ans = 0;
    for(int i = at; i <= pt; i++){
        // i-at+1 ~ i
        sum -= cnt[i - at];
        sum += cnt[i];
        if(max_sum < sum){
            max_sum = sum;
            ans = i - at + 1;
        }
    }
    
    answer += (ans / 3600 < 10)? "0" + to_string(ans / 3600) : to_string(ans / 3600);
    answer += ":";
    
    ans %= 3600;
    answer += (ans / 60 < 10)? "0" + to_string(ans / 60) : to_string(ans / 60);
    answer += ":";
    
    ans %= 60;
    answer += (ans < 10)? "0" + to_string(ans) : to_string(ans);
    
    return answer;
}