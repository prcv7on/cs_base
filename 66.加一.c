/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* arr, int asz, int* rsz){
    for (int i=asz-1;i>=0;--i) {
        arr[i]= ++arr[i] % 10;
        if (arr[i] != 0) {
            *rsz=asz;
            return arr;
        }
    }

    *rsz=asz+1;
    int* ret=(int*)malloc(*rsz*sizeof(int));
    ret[0]=1;
    // memcpy(ret+1,arr,asz);
    for (int i=1;i<=asz;++i) {
        ret[i]=0;
    }
    return ret;
}


// @lc code=end

// int* plusOne(int* arr, int asz, int* rsz){
//     for (int i=asz-1;i>=0;--i) {
//         arr[i]= ++arr[i] % 10;
//         if (arr[i] != 0) {
//             *rsz=asz;
//             return arr;
//         }
//         printf("i=%d\n",i);
//     }

//     *rsz=asz+1;
//     int* ret=(int*)malloc(*rsz*sizeof(int));
//     ret[0]=1;
//     memcpy(ret+1,arr,*rsz);
//     return ret;
// }

int main(void) {
    int arr[1]={9};//1,3,5,7,9
    int rsz=0;
    int* pa=plusOne(arr,1,&rsz);
    printf("rsz=%d\n",rsz);
    for (int i=0;i<rsz;++i) {
        printf("%d ",pa[i]);
    }
    printf("\n");

}

