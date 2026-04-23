#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    int n = a.size();
    if(n < 3) return n;
    
    // 값 하나 제외, 양쪽 배열에서 최솟값
    // 최소1, 값, 최소2: 이 중 값이 최댓값인 경우 못남김
    vector<int> min_left(n), min_right(n); // 처음/끝에서부터 i까지 최솟값
    min_left[0] = a[0];
    for(int i = 1; i < n; i++){
        min_left[i] = min(a[i], min_left[i - 1]);
    }
    min_right[n - 1] = a[n - 1];
    for(int i = n - 2; i >=0; i--){
        min_right[i] = min(a[i], min_right[i + 1]);
    }
    
    answer = 2; // a[0], a[n - 1]은 무조건 포함
    for(int i = 1; i < n - 1; i++){
        int cur = a[i];
        int cur_max = max(cur, max(min_left[i - 1], min_right[i + 1]));
        if(cur_max != cur) answer++;
    }
    
    return answer;
}