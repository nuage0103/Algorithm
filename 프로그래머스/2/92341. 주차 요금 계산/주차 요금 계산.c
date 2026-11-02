#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// fees_len은 배열 fees의 길이입니다.
// records_len은 배열 records의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

#define MAX 10000

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    //int* answer = (int*)malloc(1);

    int car_time[MAX]; // 누적시간
    int car_exist[MAX]; // -1: 없음. 그외: 마지막 in시각
    memset(car_time, -1, sizeof(car_time));
    memset(car_exist, -1, sizeof(car_exist));
    
    int hour, min, num;
    char state[4] = {0};
    for(int i = 0; i < records_len; i++){
        sscanf(records[i], "%d:%d %d %s", &hour, &min, &num, state);
        if(strcmp(state, "IN") == 0){
            if(car_time[num] == -1) car_time[num] = 0;
            car_exist[num] = hour * 60 + min;
        }
        else{
            car_time[num] += (hour * 60 + min) - car_exist[num];
            car_exist[num] = -1;
        }
    }
    
    for(int i = 0; i < MAX; i++){
        if(car_exist[i] != -1){
            car_time[i] += (23 * 60 + 59) - car_exist[i];
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < MAX; i++){
        if(car_time[i] != -1) cnt++;
    }
    
    int f0 = fees[0], f1 = fees[1], f2 = fees[2], f3 = fees[3];
    int* answer = (int*)malloc(cnt * sizeof(int));
    int idx = 0;
    for(int i = 0; i < MAX; i++){
        if(car_time[i] == -1) continue;
        
        answer[idx] = f1;
        if(car_time[i] > f0){
            car_time[i] -= f0;
            answer[idx] += ceil((double)car_time[i] / f2) * f3;
        }
        
        idx++;
    }

    return answer;
}