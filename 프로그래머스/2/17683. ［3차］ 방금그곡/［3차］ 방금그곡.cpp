#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

/*
처음부터 끝까지 반복 / 처음부터 중간까지 재생
재생 시작 ~ 끝 / 악보 길이. 음1개 = 1분
선택 조건: 재생 시간 긴, 먼저 입력된

C# -> c / C -> C
hh:mm -> h*60+m
*/

string change(string& s){
    string ret = "";
    for(int i = 0; i < s.size(); i++){
        if(i + 1 < s.size() && s[i + 1] == '#'){
            ret += tolower(s[i]);
            i++;
        }
        else ret += s[i];
    }
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    m = change(m);
    answer = "(None)";
    int max_time = -1;
    for(int i = 0; i < musicinfos.size(); i++){
        stringstream ss(musicinfos[i]);
        string st, end, title, music;
        getline(ss, st, ',');
        getline(ss, end, ',');
        getline(ss, title, ',');
        getline(ss, music, ',');
        
        int st_h = stoi(st.substr(0, 2));
        int st_m = stoi(st.substr(3));
        int end_h = stoi(end.substr(0, 2));
        int end_m = stoi(end.substr(3));
        int time = (end_h * 60 + end_m) - (st_h * 60 + st_m);
        
        music = change(music);
        string played = "";
        for(int j = 0; j < time; j++){
            played += music[j % music.size()];
        }
        
        // 선택 조건: 재생 시간 긴, 먼저 입력된
        if(played.find(m) != string::npos){
            if(time > max_time) {
                max_time = time;
                answer = title;
            }
        }
    }
    return answer;
}