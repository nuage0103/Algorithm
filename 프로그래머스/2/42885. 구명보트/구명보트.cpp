#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
두명 합이 limit 이하면 가능

*/

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int n = people.size();
    int st = 0, en = n - 1;
    // 현재 최소 = ppl[st], 최대 = ppl[en]
    // 둘의 합이 리미트보다 크면 en 혼자 하나. 이하면 st, en 둘이 하나.
    while(st <= en){
        if(people[st] + people[en] <= limit){
            answer++; // st, en 둘이 하나
            
            st++;
            en--;
            continue;
        }
        
        answer++; // en 혼자 하나
        en--;
    }
    return answer;
}