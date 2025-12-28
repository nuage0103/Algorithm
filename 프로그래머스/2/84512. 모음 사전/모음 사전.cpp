#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char vowel[5] = {'A', 'E', 'I', 'O', 'U'};
int cnt = 0;
bool check = false;

void dfs(int depth, string cur, string target){
    if(check) return;
    
    if(depth) {
        cnt++;
        if(cur == target) {
            check = true;
            return;
        }
    }
    if(depth == 5) return;
    
    for(int i=0; i<5; i++){
        cur.push_back(vowel[i]);
        dfs(depth + 1, cur, target);
        cur.pop_back();
    }
}

int solution(string word) {
    dfs(0, "", word);
    int answer = cnt;
    return answer;
}