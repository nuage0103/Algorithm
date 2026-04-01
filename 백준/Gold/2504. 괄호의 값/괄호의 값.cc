#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int len = str.size();

    int res = 0;
    int tmp = 1;
    stack<char> st;
    for(int i = 0; i < len; i++){
        if(str[i] == '(') {
            tmp *= 2;
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            if(st.empty() || st.top() != '(') {
                res = 0;
                break;
            }

            if(str[i - 1] == '(') res += tmp;
            tmp /= 2;
            st.pop();
        }
        else if(str[i] == '['){
            tmp *= 3;
            st.push(str[i]);
        }
        else if(str[i] == ']'){
            if(st.empty() || st.top() != '[') {
                res = 0;
                break;
            }

            if(str[i - 1] == '[') res += tmp;
            tmp /= 3;
            st.pop();
        }
    }

    if(!st.empty()) res = 0;
    cout << res << '\n';

    return 0;
}
