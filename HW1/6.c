#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *str, int k){
    char *ch = malloc(sizeof(char) * 100);
    int length = strlen(str);
    for (int i = k - 1,j = 0; i >= 0 && j < k; i--, j++){
        ch[j] = str[i];
    }
    for (int i = 0; i < k; i++){
        str[i] = ch[i];
    }
    if (length < 3 * k){
        for (int i = length - 1, j = 0; i >= 2 * k && j < k; i--, j++){
            ch[j] = str[i];
        }
        for (int i = 2 * k; i < length; i++){
            str[i] = ch[i - 2 * k];
        }
    } else if (length < 4 * k) {
        for (int i = 3 * k - 1, j = 0; i >= 2 * k && j < k; i--, j++){
            ch[j] = str[i];
        }
        for (int i = 2 * k; i < 3 * k; i++){
            str[i] = ch[i - 2 * k];
        }
    }
    free(ch);
}
int main(){
    char *str = malloc(sizeof(char) * 100);
    if (str == NULL){
        printf("内存分配错误");
        exit(1);
    }
    scanf("%[^\n]", str);
    int k;
    scanf("%d", &k);
    reverse(str, k);
    printf("%s", str);
    return 0;
}