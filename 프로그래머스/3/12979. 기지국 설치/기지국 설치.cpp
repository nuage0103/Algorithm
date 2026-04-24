#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
w: n-w ~ n ~ n+w
2w+1
*/

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    float check = 2 * w + 1;
    int last = 0;
    for(int p: stations){
        int left = p - w;
        int len = left - 1 - last; // last+1 ~ left-1
        if(len > 0){
            answer += ceil(len / check);
        }
        
        last = p + w;
    }
    
    if(last < n){
        int len = n - last; // last+1 ~ n
        answer += ceil(len / check);
    }

    return answer;
}