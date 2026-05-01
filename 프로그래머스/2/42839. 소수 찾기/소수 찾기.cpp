#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>

using namespace std;

int freq[10] = {0};
bool is_prime[10000000];
set<int> s;
int n;

void prime(){
    fill(is_prime, is_prime + 10000000, true);
    is_prime[0] = false;
    is_prime[1] = false;
    
    for(int i = 2; i < sqrt(10000000); i++){
        if(!is_prime[i]) continue;
        
        for(int j = i * i; j < 10000000; j += i){
            is_prime[j] = false;
        }
    }
}

void dfs(string cur){
    if(cur.size()){
        int num = stoi(cur);
        if(is_prime[num]) s.insert(num);
    }
    
    if(cur.size() == n){
        return;
    }
    
    for(int i = 0; i < 10; i++){
        if(!freq[i]) continue;
        
        freq[i]--;
        cur += to_string(i);
        dfs(cur);
        freq[i]++;
        cur.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;
    
    n = numbers.size();
    for(char c: numbers) freq[c - '0']++;
    for(int i = 0; i < 10; i++) cout << freq[i] << ' ';
    prime();
    
    string str = "";
    dfs(str);
    answer = s.size();
    
    return answer;
}