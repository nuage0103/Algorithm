#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> num(n); // 오름차순
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    int start = 0, end = n - 1;
    ll min_sum = 3e9;
    int idx1 = start, idx2 = end;
    while(start < end){
        ll sum = num[start] + num[end];
        if(abs(sum) < min_sum){
            min_sum = abs(sum);
            idx1 = start;
            idx2 = end;
            if(min_sum == 0) break;
        }

        if(sum < 0) start++;
        else end--;
    }

    cout << num[idx1] << ' ' << num[idx2] << '\n';

    return 0;
}
