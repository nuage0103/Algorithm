#include <stdio.h>
#include <string.h>
#define MAX 1001

void Push(char*, char);
void Pop(char*);
int Empty();

int top = -1;

int main(){
    int t;
    scanf("%d", &t);
    getchar();
    char str[MAX];
    char word[21];
    for(int i = 0; i < t; i++){
        fgets(str, MAX, stdin);
        str[strlen(str) - 1] = '\0';
        for(int j = 0; j < strlen(str); j++){
            if(str[j] == ' '){
                Pop(word);
            }
            else Push(word, str[j]);
        }
        Pop(word);
        printf("\n");
    }    

    return 0;
}

void Push(char *word, char alpha){
    word[++top] = alpha;
    return;
}

void Pop(char *word){
    while(!Empty()) printf("%c", word[top--]);
    printf(" ");
    top = -1;
    return;
}

int Empty(){
    if(top < 0) return 1;
    else return 0;
}
