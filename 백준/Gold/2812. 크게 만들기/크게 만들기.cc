#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string number;
    cin >> number;

    string res = ""; // 스택의 top처럼 문자열의 마지막 원소만 비교, 제거
    for(int i=0; i<n; i++){
        while(!res.empty() && k > 0 && number[i] > res.back()){
            res.pop_back();
            k--;
        }

        res.push_back(number[i]);
    }
    while(k){
        res.pop_back();
        k--;
    }

    cout << res << '\n';

    return 0;
}
