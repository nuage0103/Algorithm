#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    string head;
    int num, idx;
} File;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    struct comp{
        bool operator()(const File& a, const File& b){
            if(a.head != b.head) return a.head > b.head;
            if(a.num != b.num) return a.num > b.num;
            return a.idx > b.idx;
        }
    };
    
    priority_queue<File, vector<File>, comp> q;
    for(int i = 0; i < files.size(); i++){
        string f = files[i];
        string head = "", num = "";
        
        int p = 0;
        for(; p < f.size(); p++){
            char c = f[p];
            if(!isdigit(c)) head += tolower(c);
            else break;
        }
        for(; p < f.size(); p++){
            char c = f[p];
            if(isdigit(c)) num += c;
            else break;
        }
        
        q.push({head, stoi(num), i});
    }
    
    while(!q.empty()){
        File f = q.top();
        q.pop();
        
        answer.push_back(files[f.idx]);
    }
    return answer;
}