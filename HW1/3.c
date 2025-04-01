#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    int val;
    scanf("%d",&num);
    int *nums = malloc(sizeof(int) * (num + 1));
    if (nums == NULL){
        printf("内存分配错误");
        exit(1);
    }
    for (int i = 0; i < num; i++){
        scanf("%d",&nums[i]);
    }
    scanf("%d",&val);

    int pos = 0;
    while (pos < num && val >= nums[pos]){
        pos++;
    }
    //其后的元素应该向后腾出空间
    for (int i = num; i > pos; i--){
        nums[i] = nums[i - 1];
    }
    nums[pos] = val;
    for (int i = 0; i < num; i++){
        printf("%d ",nums[i]);
    }
    printf("%d",nums[num]);
    free(nums);
    return 0;
}