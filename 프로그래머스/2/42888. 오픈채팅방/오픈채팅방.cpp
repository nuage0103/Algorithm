#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

/*
문자열 파싱
#include <sstream>
stringstream 사용: 공백을 기준으로 문자열 분할
cin >> 으로 변수 입력받는 것과 동일한 동작

find, substr보다 직관적, 인덱스 계산 실수 방지
*/

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<string, string>> msg; // id + enter/leave    
    unordered_map<string, string> um; // {id, name}
    for(auto& r: record){
        // parse
        /*
        int prev = -1;
        int p = r.find(' ', prev + 1);
        string op = r.substr(0, p); // 0~p-1
        prev = p;
        
        p = r.find(' ', prev + 1);
        string id = r.substr(prev + 1, p - 1 - prev); // prev+1~p-1
        prev = p;
        */
        
        stringstream ss(r);
        string op, id, name;
        ss >> op >> id >> name; // 공백 기준으로 변수 할당
        // leave: name에 입력 없이 ss 스트림 끝남. 명령어 길이에 따라 파싱 조건 분기할 필요 없음.
        
        string enter = "님이 들어왔습니다.";
        string leave = "님이 나갔습니다.";
        // enter
        if(op == "Enter"){
            //string name = r.substr(prev + 1);
            // 있는 아이디: 이름 변경, 결과 추가
            // 없는 아이디: 이름 추가, 결과 추가
            um[id] = name;
            msg.push_back({id, enter});
        }
        // leave
        if(op == "Leave"){
            msg.push_back({id, leave});
        }
        // change
        if(op == "Change"){
            //string name = r.substr(prev + 1);
            um[id] = name;
        }
    }
    
    for(auto& m: msg){
        // id -> name
        answer.push_back(um[m.first] + m.second);
    }
    return answer;
}
