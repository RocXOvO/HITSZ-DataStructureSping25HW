#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isPair(char stack, char ch){
    if (stack == '(' && ch == ')'){
        return 1;
    }
    if (stack == '[' && ch == ']'){
        return 1;
    }
    if (stack == '{' && ch == '}'){
        return 1;
    }
    return 0;
}

int isBalanced(char *str){
    char *stack =malloc(sizeof(char) * strlen(str));
    int top = -1;
    int length = strlen(str);
    for (int i = 0; i < length; i++){
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '['){
            stack[++top] = ch;
        } else if (ch == ')' || ch == '}' || ch == ']'){
            if (top != -1 && isPair(stack[top], ch)){
                top--;
            } else {
                free(stack);
                return 0;
            }
        }
    }
    int result = top == -1;
    free(stack);
    return result;
}

int main(){
    char *str = malloc(sizeof(char) * 100);
    if (str == NULL){
        printf("分配内存错误");
        exit(1);
    }
    scanf("%[^\n]",str);
    int flag;
    flag = isBalanced(str);
    if (flag){
        printf("True");
    } else {
        printf("False");
    }
}