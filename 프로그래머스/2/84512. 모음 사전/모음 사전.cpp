#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string word) {
    /*
    a----: 1 ~ 781번째
    e----: 781*1 + 1 ~ 
    i----: 781*2 + 1 ~
    
    aa---: 1 ~ 156
    ae---: 156*1 + 1 ~
    ea---: (781*1 + 1) + (1) ~
    ee---: (781*1 + 1) + (156*1 + 1) ~
    */
    int weight[5] = {781, 156, 31, 6, 1};
    int answer = 0;
    for(int i=0; i<word.length(); i++){
        int x;
        if(word[i] == 'A') x = 0;
        else if(word[i] == 'E') x = 1;
        else if(word[i] == 'I') x = 2;
        else if(word[i] == 'O') x = 3;
        else if(word[i] == 'U') x = 4;
        
        answer += weight[i] * x + 1;
    }
    return answer;
}