#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<int> height(w);
    for(int i = 0; i < w; i++){
        cin >> height[i];
    }

    int l = 0, r = w - 1;
    int left_max = 0, right_max = 0;
    int sum = 0;
    while(l < r){
        // 양쪽 최대 높이 중 작은 거 기준으로 합산
        if(height[l] >= height[r]){
            right_max = max(right_max, height[r]);
            sum += (right_max - height[r]);
            r--;
        }
        else{
            left_max = max(left_max, height[l]);
            sum += (left_max - height[l]);
            l++;
        }
    }

    cout << sum << '\n';
}
