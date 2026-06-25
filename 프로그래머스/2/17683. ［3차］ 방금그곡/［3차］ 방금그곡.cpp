#include <string>
#include <vector>
#include <iostream>

using namespace std;

string change(string s){
    string ret = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            char last = ret.back();
            ret.pop_back();
            ret += tolower(last);
            continue;
        }
        else ret += s[i];
    }
    
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    /*
    m: 기억하는 악보
    시작, 끝, 제목, 악보(원본)
    시작~끝, 악보 길이 비교 후 악보 자르기/반복
    m이랑 일치여부
    */
    
    m = change(m);
    int max_time = -1;
    answer = "(None)";
    for(int i = 0; i < musicinfos.size(); i++){
        string info = musicinfos[i];
        
        // 정보 분리
        int p1 = info.find(',', 0);
        int p2 = info.find(',', p1 + 1);
        int p3 = info.find(',', p2 + 1);
        string st, en, title, melody;
        st = info.substr(0, p1); // 0~p1-1
        en = info.substr(p1 + 1, p2 - p1 - 1); // p1+1~p2-1. p2-1-p1
        title = info.substr(p2 + 1, p3 - p2 - 1); // p2+1~p3-1
        melody = info.substr(p3 + 1); // p3+1~
        
        // 재생 시간
        int start = stoi(st.substr(0, 2)) * 60 + stoi(st.substr(3));
        int end = stoi(en.substr(0, 2)) * 60 + stoi(en.substr(3));
        int total = end - start;
        
        // 악보 샵 변환
        melody = change(melody);
        
        // 재생 시간으로 악보 재생성
        string new_mel = "";
        for(int j = 0; j < total; j++){
            new_mel += melody[j % melody.size()];
        }
        
        // 새 악보랑 m 비교
        if(new_mel.find(m) != string::npos){
            // 재생시간 더 긴
            if(max_time < total){
                max_time = total;
                answer = title;
            }
            // 먼저 입력된 (i)
        }
    }
    
    return answer;
}