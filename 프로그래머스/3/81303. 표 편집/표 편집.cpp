#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

typedef struct{
    int prev, next;
}Node;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    // z: 가장 최근 제거 대상 복구. lifo(stack)
    stack<int> deleted;
    vector<Node> nodes(n);
    for(int i = 0; i < n; i++){
        nodes[i].prev = i - 1;
        nodes[i].next = i + 1;
    }
    nodes[n - 1].next = -1;
    
    for(auto& s: cmd){
        if(s[0] == 'U'){
            int x = stoi(s.substr(2));
            while(x--){
                k = nodes[k].prev;
            }
        }
        if(s[0] == 'D'){
            int x = stoi(s.substr(2));
            while(x--){
                k = nodes[k].next;
            }
        }
        if(s[0] == 'C'){
            deleted.push(k);
            int pr = nodes[k].prev;
            int nx = nodes[k].next;
            if(nx != -1) nodes[nx].prev = pr;
            if(pr != -1) nodes[pr].next = nx;
            
            if(nx != - 1) k = nx;
            else k = pr;
        }
        if(s[0] == 'Z'){
            if(deleted.empty()) continue;
            
            int x = deleted.top();
            deleted.pop();
            int pr = nodes[x].prev;
            int nx = nodes[x].next;
            if(pr != -1) nodes[pr].next = x;
            if(nx != -1) nodes[nx].prev = x;
        }
    }
    
    for(int i = 0; i < n; i++) answer += "O";
    while(!deleted.empty()){
        answer[deleted.top()] = 'X';
        deleted.pop();
    }
    
    return answer;
}