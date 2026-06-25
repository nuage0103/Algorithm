#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    today[4] = today[7] = ' ';
    stringstream ss(today);
    int y, m, d;
    ss >> y >> m >> d;
    
    int term_month[26] = {0};
    for(auto& t: terms){
        term_month[t[0] - 'A'] = stoi(t.substr(2));
    }
    
    for(int i = 0; i < privacies.size(); i++){
        string& p = privacies[i];
        
        p[4] = p[7] = ' ';
        stringstream ss2(privacies[i]);
        int yr, mon, day;
        char c;
        ss2 >> yr >> mon >> day >> c;
        
        int add = term_month[c - 'A'];
        yr += (add / 12);
        mon += (add % 12);
        if(mon > 12){
            mon %= 12;
            yr += 1;
        }

        if(yr > y) continue;
        else if(yr == y){
            if(mon > m) continue;
            else if(mon == m && day > d) continue;
        }
        
        answer.push_back(i + 1);
    }
    
    return answer;
}