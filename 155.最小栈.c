/*
 * @lc app=leetcode.cn id=155 lang=c
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
typedef struct {
    int* arr;
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* ps=malloc(sizeof(MinStack));
    ps->arr=malloc(MAXSIZE*sizeof(int));
    ps->top=-1;
    return ps;
}

void minStackPush(MinStack* ps, int x) {
    if (ps->top == MAXSIZE-1) return;
    else {
        ++(ps->top);
        *(ps->arr + ps->top)=x;
    }
}

void minStackPop(MinStack* ps) {
    if (ps->top == -1) return;
    else --(ps->top);
}

int minStackTop(MinStack* ps) {
    if (ps->top == -1) return -1;
    return *(ps->arr + ps->top);
}

int minStackGetMin(MinStack* ps) {
    if (ps->top == -1) return -1;
    int minval=ps->arr[0];
    for (int i=0;i<=ps->top;++i) {
        if (ps->arr[i] < minval) {
            minval=ps->arr[i];
        }
    }
    return minval;
}

void minStackFree(MinStack* ps) {
    free(ps->arr);
    ps->arr=NULL;
    free(ps);
    ps=NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
// @lc code=end


int main(void) {
    MinStack* ps = minStackCreate();
    minStackPush(ps,1);
    minStackPush(ps,3);
    minStackPush(ps,5);
    minStackPush(ps,7);
    minStackPush(ps,9);
    minStackPop(ps);
    int a=minStackTop(ps);
    int b=minStackGetMin(ps);
    minStackFree(ps);
    printf("a=%d,b=%d\n",a,b);


    return 0;
}


