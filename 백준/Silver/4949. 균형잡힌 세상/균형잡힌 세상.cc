#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void solve(string& s){
    stack<char> st;
    bool flag = false;
    for(char c: s){
        if(flag){
            cout << "no\n";
            return;
        }

        if(c == '('){
            st.push(c);
        }
        else if(c == '['){
            st.push(c);
        }
        else if(c == ')'){
            if(!st.empty() && st.top() == '(') st.pop();
            else flag = true;
        }
        else if(c == ']'){
            if(!st.empty() && st.top() == '[') st.pop();
            else flag = true;
        }
        else continue;
    }

    if(st.empty()) cout << "yes\n";
    else cout << "no\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        string s;
        getline(cin, s);
        if(s == ".") break;
        solve(s);
    }

    return 0;
}
