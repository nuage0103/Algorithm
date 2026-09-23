#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
/*
numbers[i] 10->2진수
-> 포화이진트리: 노드 개수 2*n -1 / 노드 번호 중위순회
answer 0 = 자식노드 더미x, 부모노드 더미o
*/

string convert(long long x){
    string ret = "";
    int r;
    while(x > 1){
        r = x % 2;
        ret += to_string(r);
        x /= 2;
    }
    ret += to_string(x);
    reverse(ret.begin(), ret.end());
    
    int exp = 1;
    while((1 << exp) - 1 < ret.size()){
        exp++;
    }
    int len = (1 << exp) - 1;
    ret = string(len - ret.size(), '0') + ret;
    
    return ret;
}

bool check(const string& bin, int st, int en, bool parent_zero){
    if(st > en) return true;
    
    int mid = (st + en) / 2;
    if(parent_zero && bin[mid] == '1') return false;
    
    bool next_parent = (bin[mid] == '0');
    if(!check(bin, st, mid - 1, next_parent)) return false; // left
    if(!check(bin, mid + 1, en, next_parent)) return false; // right    
    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(long long x: numbers){
        string bin = convert(x);
                
        if(check(bin, 0, bin.size() - 1, false)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}