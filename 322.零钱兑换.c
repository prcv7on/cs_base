/*
 * @lc app=leetcode.cn id=322 lang=c
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int cmp(const void* a,const void* b) {
    return *(int*)b - *(int*)a;
}

void dfs_greed(int* coins,int sz,int reminder,int idx,int cnt,int* ret) {
    if (reminder==0) {
        if (cnt < (*ret)) *ret=cnt;
        return;
    }
    if (idx==sz) return;
    for (int k=reminder/coins[idx];k>=0 && cnt+k<(*ret); --k) {
        dfs_greed(coins,sz,reminder-k*coins[idx],idx+1,cnt+k,ret);
    }
}

int coinChange(int* coins, int csz, int amount) {
    if (amount==0) return 0;
    qsort(coins,csz,sizeof(int),cmp);
    int rt=INT_MAX;
    dfs_greed(coins,csz,amount,0,0,(int*)&rt);
    //printf("rt=%d\n",rt);
    return rt==INT_MAX ? -1 : rt;
}


// @lc code=end

int main(void) {
    int arr[]={5,1,2};
    int amount=11;
    int num=coinChange(arr,3,amount);
    printf("num=%d\n",num);


    return 0;
}