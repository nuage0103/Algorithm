#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> map;
    int n = phone_book.size();

    for(int i=0; i<n; i++){
        map[phone_book[i]] = 1;
    }
    
    //bool answer = true;
    for(int i=0; i<n; i++){
        string cur = phone_book[i];
        int len = cur.length();
        for(int j=1; j<len; j++){
            // str.substr(pos, cnt): [pos, pos+cnt) 반환, pos+cnt가 범위 밖이면 문자열 끝까지만 반환
            // 중복되는 번호 없음. len-2까지만 확인
            string head = cur.substr(0, j);
            if(map[head] == 1) return false;
        }
    }
    return true;
}