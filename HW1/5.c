#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
int isOperator(char *token){
    return token[0] == '+' || token[0] == '*' || token[0] == '-' || token[0] == '/';
}

int popStack(int *stack){
    if (top != -1){
        return stack[top--];
    }
    return 0;
}

void pushStack(int *stack,int val){
    if (top < MAX_SIZE - 1){
        stack[++top] = val;
    }
    return;
}

void evalRPN(char *tokens[], int n){
    char *token;
    int result;
    for (int i = 0; i < n; i++){
        token = tokens[i];
        if (!isOperator(token)){
            pushStack(stack,atoi(token));
        } else {
            int b = popStack(stack);
            int a = popStack(stack);
            if (strcmp(token, "+") == 0){
                result = a + b;
            } else if (strcmp(token, "*") == 0){
                result = a * b;
            } else if (strcmp(token, "-") == 0){
                result = a - b;
            } else if (strcmp(token, "/") == 0){
                result = a / b;
            }
            pushStack(stack, result);
        }
    }
}
int main(){
    int n;
    int result;
    scanf("%d", &n);
    char *tokens[n];
    for (int i = 0; i < n; i++){
        tokens[i] = malloc(sizeof(char) * 20);
        scanf("%s",tokens[i]);
    }
    evalRPN(tokens, n);
    printf("%d", stack[top]);
    for (int i = 0; i < n; i++){
        free(tokens[i]);
    }
    return 0;
}