#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    string num;
    cin >> n >> k >> num;

    //stack<char> st;
    string res = "";
    int erase = 0;
    for(char c: num){
        while(!res.empty() && res.back() < c && erase < k){
            res.pop_back();
            erase++;
        }

        res.push_back(c);
    }
    while(erase < k){
        res.pop_back();
        erase++;
    }
/*
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
*/
    cout << res << '\n';

    return 0;
}
