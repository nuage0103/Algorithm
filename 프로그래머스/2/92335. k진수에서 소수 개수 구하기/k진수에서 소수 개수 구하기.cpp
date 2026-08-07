#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

bool is_prime(long long num){
    if(num == 0 || num == 1) return false;
    
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }

    return true;
}

string convert(int n, int k){
    if(n == 0) return "0";
    if(k == 10) return to_string(n);
    
    string digit = "0123456789ABCDEF";
    string ret = "";
    while(n){
        ret += digit[n % k];
        n /= k;
    }
    
    reverse(ret.begin(), ret.end());
    
    if(ret[0] == '0') return ret.substr(1);
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> prime;
    string full = convert(n, k);
    
    stringstream ss(full);
    string token;
    while(getline(ss, token, '0')){
        if(token.empty()) continue;
        
        long long cur = stoll(token);
        if(is_prime(cur)) answer++;
    }
    
    return answer;
}