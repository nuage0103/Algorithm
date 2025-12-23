#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    while(1){
        string inp;
        getline(cin, inp);

        if(inp.length() == 1 && inp[0] == '.') break;

        stack<char> st;
        bool check = true;
        int len = inp.length();
        for(int i=0; i<len; i++){
            if(inp[i] == '(' || inp[i] == '['){
                st.push(inp[i]);
            }
            if(inp[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
            if(inp[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else {
                    check = false;
                    break;
                }
            }
        }

        if(st.empty() && check) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
