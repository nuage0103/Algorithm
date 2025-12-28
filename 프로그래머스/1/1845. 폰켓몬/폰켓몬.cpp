#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    unordered_set<int> set;
    for(int i=0; i<n; i++){
        set.insert(nums[i]);
    }
    
    int answer = min((int)(set.size()), n/2); // 최대 종류 개수
    return answer;
}