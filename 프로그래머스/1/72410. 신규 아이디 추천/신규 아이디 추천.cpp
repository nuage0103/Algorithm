#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";
    for(char c: new_id){
        // 1
        if(c >= 'A' && c <= 'Z') tmp += c - 'A' + 'a';
        // 2
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.') tmp += c;
    }
    answer = tmp;
    cout << answer << '\n';
    
    // 3
    tmp = "";
    for(int i = 0; i < answer.size() - 1; i++){
        if(answer[i] == '.' && answer[i + 1] == '.') continue; // answer[i] 제거
        tmp += answer[i];
    }
    answer = tmp + answer[answer.size() - 1];
    cout << answer << '\n';
    
    // 4
    if(answer[0] == '.') answer.erase(0, 1);
    if(answer[answer.size() - 1] == '.') answer.pop_back();
    cout << answer << '\n';
    
    // 5
    if(answer.size() == 0) answer = "a";
    cout << answer << '\n';
    
    // 6
    if(answer.size() >= 16) {
        answer = answer.substr(0, 15);
        if(answer[answer.size() - 1] == '.') answer.pop_back();
    }
    cout << answer << '\n';

    // 7
    while(answer.size() <= 2) answer += answer.back();
    cout << answer << '\n';
    
    return answer;
}