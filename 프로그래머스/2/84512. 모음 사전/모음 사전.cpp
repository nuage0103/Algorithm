#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dic;
char vowel[5] = {'A', 'E', 'I', 'O', 'U'};

void dfs(int depth, string str){
    if(depth) dic.push_back(str);
    if(depth == 5) return;
    
    for(int i=0; i<5; i++){
        str.push_back(vowel[i]);
        dfs(depth + 1, str);
        str.pop_back();
    }
}

int solution(string word) {
    dfs(0, ""); // 모든 단어 생성
    sort(dic.begin(), dic.end());
    int answer = find(dic.begin(), dic.end(), word) - dic.begin() + 1;
    return answer;
}