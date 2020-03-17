/*
 * @lc app=leetcode.cn id=55 lang=c
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include <stdbool.h>

bool canJump(int* a, int sz){
    int k=0;
    for (int i=0;i<sz;++i) {
        if (i>k) return false;
        if (i+a[i] > k) k=i+a[i];
    }
    return true;
}


// @lc code=end

int main(void) {
    int arr[]={2,3,1,1,4};//3,2,1,0,4
    bool b1=canJump(arr,5);
    printf("b1=%d\n",b1);

    return 0;
}

