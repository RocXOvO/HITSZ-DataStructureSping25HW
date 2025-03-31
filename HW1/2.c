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

char* ClearNumber(char *s){
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
    return store;
}

int isParlindromicString(char *s){
    char ch[100];
    for (int i = 0, j = strlen(s) - 1; i < strlen(s) && j >= 0; i++, j--){
        ch[i] = s[j];
    }
    if(strcmp(s,ch) == 0){
        return 1;
    }
    return 0;
}
int main(){
    char a[100];
    char *result = ClearNumber(a);
    int flag;
    scanf("%99s",a);
    TransUptoLower(result);
    flag = isParlindromicString(result); 
    if(flag){
        printf("true");
    } else {
        printf("false");
    }
    free(0);
}