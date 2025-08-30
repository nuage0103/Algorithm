#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    int id;
    int rec;
    int time;
} Info;

bool comp(const Info& a, const Info& b){
    return a.id < b.id;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> rec(m);
    for(int i = 0; i < m; i++){
        scanf("%d", &rec[i]);
    }

    vector<Info> res(n);
    int cnt = 0;
    for(int t = 0; t < m; t++){
        // t: 추천시각. 작을수록 오래됨
        int id = rec[t];

        bool exist = false;
        for(int i = 0; i < cnt; i++){
            // 이미 게시된 학생
            if(res[i].id == id){
                res[i].rec++;
                exist = true;
                break;
            }
        }
        if(exist) continue;

        // 게시
        if(cnt < n){
            res[cnt] = {id, 1, t};
            cnt++;
            continue;
        }

        // 빈틀 없는 경우
        // 삭제 대상
        int del = 0;
        for(int i = 1; i < n; i++){
            if(res[i].rec < res[del].rec){
                del = i;
            }
            else if(res[i].rec == res[del].rec && res[i].time < res[del].time){
                del = i;
            }
        }

        // 삭제(교제)
        res[del] = {id, 1, t};

    }

    sort(res.begin(), res.begin() + cnt, comp);

    for(int i = 0; i < cnt; i++){
        printf("%d ", res[i].id);
    }

    return 0;
}
