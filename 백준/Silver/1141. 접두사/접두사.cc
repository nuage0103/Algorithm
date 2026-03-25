#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> inp(n);
    for(int i = 0; i < n; i++){
        cin >> inp[i];
    }

    sort(inp.begin(), inp.end(), [](const string &a, const string &b){
        if(a.size() != b.size()) return a.size() < b.size();
        else return a < b;
    });

    int res = 0;
    for(int i = 0; i < n; i++){
        bool check = false;
        for(int j = i + 1; j < n; j++){
            if(inp[j].find(inp[i]) == 0){
                check = true;
                break;
            }
        }

        if(!check) res++;
    }

    cout << res << '\n';

    return 0;
}
