#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void TransUptoLower(char *s){
    for (int i = 0; i < strlen(s); i++){
        char *ch = &s[i];
        if (*ch >= 'A' && *ch <= 'Z'){
            *ch = *ch + ('a' - 'A');
        }
    }
}

void ClearNumber(char *s){
    char *store = malloc(sizeof(char) * strlen(s));
    if (store == NULL){
        printf("分配内存错误");
        exit(1);
    }
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++){
        char *ch = &s[i];
        if (!isdigit((unsigned char)*ch)){
            store[cnt] = *ch;
            cnt += 1;
        }
    }
    s = store;
}

int isParlindromicString(char *s){
    char ch[100];
    for (int i = 0, j = strlen(s) - 1; i < strlen(s) && j >= 0; i++, j--){
        ch[i] = s[j];
    }
    ch[strlen(s)] = '\0';
    if(strcmp(s,ch) == 0){
        return 1;
    }
    return 0;
}

void ClearSpace(char *s){
    char *store = malloc(sizeof(char) * strlen(s));
    if (store == NULL){
        printf("分配内存错误");
        exit(1);
    }
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++){
        char *ch = &s[i];
        if (!(*ch ==' ')) {
            store[cnt] = *ch;
            cnt += 1;
        }
    }
    s = store;
}

int main(){
    char a[100];
    int flag;
    scanf("%99s",a);
    ClearNumber(a);
    ClearSpace(a);
    TransUptoLower(a);
    flag = isParlindromicString(a); 
    if(flag){
        printf("true");
    } else {
        printf("false");
    }
    free(0);
}