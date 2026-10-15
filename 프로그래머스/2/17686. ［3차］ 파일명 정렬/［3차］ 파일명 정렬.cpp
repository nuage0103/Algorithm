#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    string head;
    int number, idx;
} Info;

struct comp{
    bool operator()(const Info& a, const Info& b){
        if(a.head != b.head) return a.head < b.head;
        return a.number < b.number; 
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<Info> file_info;
    string head, number;
    for(int idx = 0; idx < files.size(); idx++){
        string file = files[idx];
        head.clear();
        head = "";
        int i;
        for(i = 0; i < file.size(); i++){
            char c = file[i];
            if(!isdigit(c)) head += c;
            else break;
        }
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        
        number = "";
        for(; i < file.size(); i++){
            char c = file[i];
            if(number.size() < 5 && isdigit(c)) number += c;
            else break;
        }
        
        file_info.push_back({head, stoi(number), idx});
    }
    
    stable_sort(file_info.begin(), file_info.end(), comp());
    for(auto& info: file_info){
        answer.push_back(files[info.idx]);
    }
    
    return answer;
}